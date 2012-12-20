// Turn off autocomplete on new password entry
// * If the node is protected
// * And the password1 field has a value
// * But the password2 field is empty
// * Then most likely the password was automatically filled in by the
//   browser and will cause errors when the form is submitted.

jQuery('#edit-password-pass1').ready(function(){
  var pass1 = jQuery('#edit-password-pass1');
  var pass2 = jQuery('#edit-password-pass2');

  // Only proceed if the fields exist. 
  if (pass1.length > 0 && pass2.length > 0) {
    var len1 = pass1.val().length;
    var len2 = pass2.val().length;
    
    // Turn off autocomplete
    pass1.attr('autocomplete', 'off');
    pass2.attr('autocomplete', 'off');
    
    // If pass1 is filled in but pass2 is not..
    if (len1 > 0 && len2 == 0) {
      // Clear the password fields.
      pass1.val('');
      pass2.val('');
    }
  }
});

