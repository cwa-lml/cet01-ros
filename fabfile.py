import os
import string
import random
import time

from fabric.operations import local as lrun
from fabric.api import *
from fabric.contrib import *
from string import lower

prompt=False
site=''
web_docs_dir='/var/www'
base_dir='/mnt/data'
files_dir=base_dir+'/cet_site_data'


# if available, use ssh config
if env.ssh_config_path and os.path.isfile(os.path.expanduser(env.ssh_config_path)):
    env.use_ssh_config=True

# agent forwarding
env.forward_agent=True

# reset the shell
#env.shell='/bin/bash -i -c'


def get_project_name(branch):
  """ Attempts to generate a project name given a branch """
  proj = local('pwd', capture=True).split('/')[-1]
  if branch == 'master':
    tstamp = time.strftime("%Y%m%d%H%M")
    project_name = proj + '-' + branch + '-' + tstamp
  else:
    project_name = proj + '-' + branch
  return project_name

def apache_user():
  """
  This retruns the primary user of the apache process
  it can be used to set permissions on folders and files
  """
  if is_el() is True:
    return 'apache'
  else:
    return 'www-data'

def is_el():
  """
  Helper function that returns whether we are running rhel/centos
  we, assume that we are running debian based distro otherwise.
  """
  return files.exists('/etc/init.d/httpd')

def sudo_run(cmd):
  """ Run the command, this is a wrapper as sudo on localhost is not very reliable """
  if env.run is lrun:
    return env.run('sudo ' + cmd)
  else:
    return sudo(cmd)


@task
def localhost():
  """ Run command on localhost """
  env.run = lrun
  env.cd = lcd
  env.hosts = ["localhost"]


@task
def remote(host):
  """ Run command on remote hosts """
  env.run = run
  env.cd = cd

  if ',' in host:
    host = host.split(',')
  elif ' ' in host:
    host = host.split();
  else:
    host = [host]

  env.hosts = host


@task
def git_archive(branch = 'master', out = '/tmp/outfile.zip'):
  """ RUN: "git archive [branch] -o [out (default '/tmp/outfile.zip')]" """
  # archive the git branch
  local("git archive " + branch + " -o " + out)


@task
def apache_deploy_site_conf(file):
  """ Copy [file] to apache /etc/apache2/sites.d or /etc/httpd/sites.d depending on environment"""
  if is_el() is True:
    path = '/etc/httpd/sites.d'
  else:
    path = '/etc/apache2/sites-available'

  if env.run is not lrun:
    put(file, path, use_sudo=True)


@task
def apache_enable_site(site):
  """ Runs "a2ensite [site] """
  if is_el() is not True:
    sudo_run('a2ensite ' + site)


@task
def apache_disable_site(site):
  """ Runs "a2dissite [site] """
  if is_el() is not True:
    sudo_run('a2dissite ' + site)


@task
def unlink(path, sudo = False, recursive = False, force = False):
  cmd = 'rm '

  if recursive is not False:
    cmd += '-r '

  if force is not False:
    cmd =+ '-f '

  if sudo is False:
    env.run(cmd + path)
  else:
    if recursive is not False:
      yes = prompt('Are you sure you want to sudo run ' + cmd + path, default='n')
      if yes.lower() == 'y':
        sudo_run(cmd + path)
    else:
      sudo_run(cmd + path)


@task
def symlink(src, link, sudo = False, replace = True):
  """ Create a symlink [link] to [src] """

  cmd='ln -s '
  if replace is not False:
    cmd+='-f '

  if sudo:
    sudo_run(cmd+src+' '+link)
  else:
    env.run(cmd+src+' '+link)


@task
def chown(path=None,owner=None,group=None,recursive=False,sudo=False):
  """ chown [own].[group] [path] """
  if path is None:
    path = prompt('Enter path to "chown": ', default='~/')

  cmd='chown '
  if recursive:
    cmd+='-R'

  if owner is None:
    owner=env.user

  cmd+=' '+owner

  if group:
    cmd+=':'+group

  if sudo:
    sudo_run(cmd+' '+path)
  else:
    env.run(cmd+' '+path)


@task
def chmod(path = None, mode = None, recursive = False, sudo = False):
  """ chmod [mode] [path] """
  if path is None:
    path = prompt('Enter path to "chmod": ', default='~/')

  """ chmod [mode] [path] """
  if mode is None:
    mode = prompt('Enter mode: ', default='755')

  cmd = 'chmod '

  if recursive:
    cmd += '-R'

  cmd += ' ' + mode + ' ' + path

  if sudo:
    sudo_run(cmd)
  else:
    env.run(cmd)


@task
def drush_cc(cache = 'all', path = None, uri = None, sudo = False):
  """ Clear drupal caches """
  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y '

  if uri is not None:
    cmd += '--uri=' + uri + ' '

  cmd += 'cc ' + cache

  with env.cd(path):
    if sudo is True:
      sudo_run(cmd)
    else:
      env.run(cmd)


@task
def drush_setmaintenance(maintenance = False, path = None, uri = None, version = 7):
  """ Sets the site availability status """
  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y '

  if uri is not None:
    cmd += '--uri=' + uri + ' '

  cmd += 'vset maintenance_mode '

  if maintenance is False:
    cmd += '0'
  else:
    cmd += '1'

  with env.cd(path):
    if version == 7:
      env.run(cmd)
    else:
      env.run(cmd)


@task
def drush_updb(path = None, sudo = False, uri = None):
  """ Run "drush updb" """
  puts(path)
  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y '

  if uri is not None:
    cmd += '--uri=' + uri + ' '

  cmd += 'updb '

  with env.cd(path):
    if sudo is True:
      sudo_run(cmd)
    else:
      env.run(cmd)

@task
def drush_en(project=None, path = None, sudo = False, uri = None):
  """ Run "drush fr [feature]"  """
  if project is None:
    project = prompt('Enter project to enable: ')

  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y en '+project

  with env.cd(path):
    if sudo is True:
      sudo_run(cmd)
    else:
      env.run(cmd)

@task
def drush_fra(path = None, sudo = False, uri = None):
  """ Run "drush fr [feature]"  """
  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y fra'

  with env.cd(path):
    if sudo is True:
      sudo_run(cmd)
    else:
      env.run(cmd)


@task
def drush_sqldump(path = None, filename = None, compress=True, uri = None, copy = False, sudo = False):
  """ Run "drush fr [feature]"  """
  if path is None:
    if prompt is True:
      path = prompt('Enter site path: ', default = web_docs_dir + '/' + site)
    else:
      path = web_docs_dir + '/' + site

  cmd = 'drush -y sql-dump'

  if filename is not None:
    if compress is True:
      filename = filename+'.gz'
      cmd = cmd+' | gzip > '+filename
    else:
      cmd = cmd+' > '+filename

  with env.cd(path):
    if sudo is True:
      sudo_run(cmd)
    else:
      env.run(cmd)


@task
def drush_import_sql_file(file, path = None):
  """
  Runs "drush sql-query --file=[file]"
  """
  if path is None:
    path = prompt('Enter site path: ', default=web_docs_dir + '/' + site)

  if env.run is not lrun:
    if not files.exists(file):
      # assume file is local and pout to server
      filename = '/tmp/' + sql.split('/')[-1]
      put(sql, filename)
    else:
      # file exists on server
      filename = file
  else:
    filename = sql

  # import
  with env.cd(site_path):
    env.run('drush sql-query --file="' + filename + '"')


@task
def rsync_remote(src=None, dst=None, user=None, delete=False, sudo=False):
  """
  Allow users to sync files from a remote host to the env host init'ed
  """
  if src is None:
    src = prompt('Enter source path: ')

  if src is None:
    abort('Remote source path missing: ')

  if dst is None:
    dst = prompt('Enter destination path: ')

  if user is None:
    user = env.user

  d = ''
  if delete is True:
    d = ' --delete'

  if sudo:
    with settings(warn_only=True):
      sudo_run('/usr/bin/rsync -r -v -e "/usr/bin/ssh -l ' + user + '" ' + d + ' ' + src + ' ' + dst)
  else:
    with settings(warn_only=True):
      env.run('/usr/bin/rsync -r   -v -e "/usr/bin/ssh -l ' + user + '" ' + d + ' ' + src + ' ' + dst)


@task
def apache_restart():
  """
  Restart apache on RHEL, CentOS or Debian based distributions
  """
  if is_el() is True:
    cmd = '/etc/init.d/httpd restart'
  else:
    cmd = '/etc/init.d/apache2 restart'
  sudo_run(cmd)


@task
def review_code(modules='sites/all/custom', level='major'):
  print('Yeah')


@task
def install_drush(min_version=None,core='7.x',path='/usr/local'):
  """
  Installs drush onto the init'ed host

  with install directory being [path]/share
  and executable being [path]/bin/drush
  """
  install = path + '/share'
  binary = path + '/bin'
  tmp_dir = '/tmp'

  # require a version
  if min_version is None:
    min_version = prompt('Please enter the version of drush you require: ')

  # dont can it if drush isn't installed
  with settings(warn_only=True):
    installed = env.run('which drush')

  # if installed determine if we want to
  # upgrade or replace the existing version
  if installed:
    if installed.count('no drush in') == 0:
      version = env.run('drush --version').split()[-1]
      if float(version) <= float(min_version):
        update = prompt('A version [' + version + '] of drush is installed. Do you want to Replace/Upgrade? : ', default='Y')
        if update.lower() != 'y':
          quit()

  # build drush tarball name
  drush = 'drush-' + core + '-' + min_version + '.tar.gz'

  # url to drush project
  url = 'http://ftp.drupal.org/files/projects/' + drush

  # ensure install directory exists
  if not files.exists(install):
    sudo_run('mkdir ' + install)

  # ensure bin directory exists
  if not files.exists(binary):
    sudo_run('mkdir ' + binary)

  # download to tmp dir and uncompress to install dir
  with env.cd(tmp_dir):
    env.run('wget -c ' + url)
    sudo_run('tar -zxf ' + drush + ' -C ' + install)

  # create symlink to bin dir
  sudo_run('ln -fs ' + install + '/drush/drush ' + binary + '/drush')

  # hide the output since it'll flood the screen
  with settings(hide('running', 'stdout', 'stderr')):
    sudo_run(binary + '/drush')

  # clean up
  env.run('rm ' + tmp_dir + '/' + drush)


@task
def deploy_production(branch = 'master'):
  project = get_project_name(branch)

  # set site package
  site_package=deployed_site_package='/tmp/'+project+'.zip'

  # set the site dir and dont rely on the defaults
  site_dir=web_docs_dir+'/'+site

  # set maintenance
  drush_setmaintenance(True,path=site_dir)

  # prod site, back up db
  drush_sqldump(site_dir,site_dir+'/'+site,compress=True,sudo=True)

  # create git archive
  git_archive(branch, site_package)
  deploy_generic(site_package,project,site_dir)


@task
def deploy_non_live(branch = 'master'):
  project = get_project_name(branch)

  # set site package
  site_package=deployed_site_package='/tmp/'+project+'.zip'

  # set the site dir and dont rely on the defaults
  site_dir=web_docs_dir+'/'+site

  # set maintenance
  drush_setmaintenance(True,path=site_dir)

  # create git archive
  git_archive(branch, site_package)
  deploy_generic(site_package,project,site_dir)



def deploy_generic(site_package, project, site_dir):
  # deploy file to uat
  if env.run is not lrun:
    put(site_package, site_package)

  # set the current_project_dir
  current_project_dir=base_dir+'/'+project

  # uncompress this branch/master version to web dir
  sudo_run('unzip -q -o -u '+site_package+' -d '+current_project_dir)

  # set the ownership of the just deployed package
  chown(current_project_dir, 'root', apache_user(), True, True)
  chmod(current_project_dir, '755', True, True)

  # link settings.php to sites/default
  symlink(files_dir+'/settings.php', current_project_dir+'/sites/default/settings.php', sudo=True);
  symlink(files_dir+'/files', current_project_dir+'/sites/default/files', sudo=True);

  # symlink new site dir
  unlink(site_dir, True)
  symlink(current_project_dir, site_dir, True, True)

  # run updb
  drush_updb(site_dir)
  drush_cc('all', site_dir)

  drush_fra(site_dir)
  drush_cc('all', site_dir)

  # enable site
  drush_setmaintenance(False)
