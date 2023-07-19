/*
    HANDLE KEY CHANGES

    The section below define what to do when a user pressed a key or release a key.
    The key layout is identical to the 2D array defined at the top of the main script.
    See that for more information
*/

void HandleKeyPressEvents(int row, int col, bool previousState, bool currentState) {
  bool isKeyDown = (previousState == false && currentState == true);
  bool isKeyUp = (previousState == true && currentState == false);
  if (isKeyDown) {
    /*
     * 
     *  KEY DOWN EVENTS
     *  
     *  Toggle when the key is just pressed
     *  
     */
    switch (row) {
      case 0:
        switch (col) {
          case 0:
            // Case: row 0, col 0
            Keyboard_press('\352'); //0
            break;
          case 1:
            // Case: row 0, col 1
            //Fn Key
            funcMode = true;
            break;
          case 2:
            // Case: row 0, col 2
            // Keypad .
            Keyboard_press('\353');
            break;
          case 3:
            // Case: row 0, col 3
            //Keypad Enter
            Keyboard_press('\340');
            break;
        }
        break;
      case 1:
        switch (col) {
          case 0:
            // Case: row 1, col 0
            Keyboard_press('\341'); //1
            break;
          case 1:
            // Case: row 1, col 1
            Keyboard_press('\342'); //2
            break;
          case 2:
            // Case: row 1, col 2
            Keyboard_press('\343'); //3
            break;
          case 3:
            // Case: row 1, col 3
            //keypad Enter
            Keyboard_press('\340');
            break;
        }
        break;
      case 2:
        // Cases for row 2 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 2, col 0
            Keyboard_press('\344');
            break;
          case 1:
            // Case: row 2, col 1
            Keyboard_press('\345');
            break;
          case 2:
            // Case: row 2, col 2
            Keyboard_press('\346');
            break;
          case 3:
            // Case: row 2, col 3
            break;
        }
        break;
      case 3:
        // Cases for row 3 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 3, col 0
            Keyboard_press('\347'); //7
            break;
          case 1:
            // Case: row 3, col 1
            Keyboard_press('\350'); //8
            break;
          case 2:
            // Case: row 3, col 2
            Keyboard_press('\351'); //9
            break;
          case 3:
            // Case: row 3, col 3
            //keypad +
            Keyboard_press('\337');
            break;
        }
        break;
      case 4:
        // Cases for row 4 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 4, col 0
            //NUM LOCK
            Keyboard_press('\333');
            break;
          case 1:
            // Case: row 4, col 1
            // keypad /
            Keyboard_press('\334');
            break;
          case 2:
            // Case: row 4, col 2
            // keypad *
            Keyboard_press('\335');
            break;
          case 3:
            // Case: row 4, col 3
            if (funcMode){
               Keyboard_press(KEY_BACKSPACE);
            }else{
              //keypad -
              Keyboard_press('\336');
            }
            
            break;
        }
        break;
    }
    return;
  } else if (isKeyUp) {
    /*
     * 
     *  KEY UP EVENTS
     *  
     *  Toggle when the key is released
     *  
     */
     
    switch (row) {
      case 0:
        switch (col) {
          case 0:
            // Case: row 0, col 0
            Keyboard_release('\352');
            break;
          case 1:
            // Case: row 0, col 1
            //Fn Key 
            funcMode = false;
            break;
          case 2:
            // Case: row 0, col 2
            // Keypad .
            Keyboard_release('\353');
            break;
          case 3:
            // Case: row 0, col 3
            //Keypad Enter
            Keyboard_release('\340');
            break;
        }
        break;
      case 1:
        switch (col) {
          case 0:
            // Case: row 1, col 0
            Keyboard_release('\341'); //1
            break;
          case 1:
            // Case: row 1, col 1
            Keyboard_release('\342'); //2
            break;
          case 2:
            // Case: row 1, col 2
            Keyboard_release('\343'); //3
            break;
          case 3:
            // Case: row 1, col 3
            //Keypad Enter
            Keyboard_release('\340');
            break;
        }
        break;
      case 2:
        // Cases for row 2 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 2, col 0
            Keyboard_release('\344'); //4
            break;
          case 1:
            // Case: row 2, col 1
            Keyboard_release('\345'); //5
            break;
          case 2:
            // Case: row 2, col 2
            Keyboard_release('\346'); //6
            break;
          case 3:
            // Case: row 2, col 3
            // Handled in key-down events
            break;
        }
        break;
      case 3:
        // Cases for row 3 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 3, col 0
            Keyboard_release('\347'); //7
            break;
          case 1:
            // Case: row 3, col 1
            Keyboard_release('\350'); //8
            break;
          case 2:
            // Case: row 3, col 2
            Keyboard_release('\351'); //9
            break;
          case 3:
            // Case: row 3, col 3
            //keypad +
            Keyboard_release('\337');
            break;
        }
        break;
      case 4:
        // Cases for row 4 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 4, col 0
            //NUM LOCK
            Keyboard_release('\333');
            break;
          case 1:
            // Case: row 4, col 1
            // keypad /
            Keyboard_release('\334');
            break;
          case 2:
            // Case: row 4, col 2
            // keypad *
            Keyboard_release('\335');
            break;
          case 3:
            // Case: row 4, col 3
            if (funcMode){
              Keyboard_release(KEY_BACKSPACE);
            }else{
              //keypad -
              Keyboard_release('\336');
            }
            break;
        }
        break;
    }
    return;
  }

}
