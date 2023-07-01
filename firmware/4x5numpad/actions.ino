
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
    //Keydown events
    switch (row) {
      case 0:
        switch (col) {
          case 0:
            // Case: row 0, col 0
            PressNumericAsKeypad('0');
            break;
          case 1:
            // Case: row 0, col 1
            funcMode = true;
            break;
          case 2:
            // Case: row 0, col 2
            // Keypad .
            Keyboard_press('\353');
            delay(1);
            Keyboard_release('\353');
            break;
          case 3:
            // Case: row 0, col 3
            //Keypad Enter
            Keyboard_press('\340');
            delay(1);
            Keyboard_release('\340');
            break;
        }
        break;
      case 1:
        switch (col) {
          case 0:
            // Case: row 1, col 0
            PressNumericAsKeypad('1');
            break;
          case 1:
            // Case: row 1, col 1
            PressNumericAsKeypad('2');
            break;
          case 2:
            // Case: row 1, col 2
            PressNumericAsKeypad('3');
            break;
          case 3:
            // Case: row 1, col 3
            //keypad +
            Keyboard_press('\337');
            delay(1);
            Keyboard_release('\337');
            break;
        }
        break;
      case 2:
        // Cases for row 2 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 2, col 0
            PressNumericAsKeypad('4');
            break;
          case 1:
            // Case: row 2, col 1
            PressNumericAsKeypad('5');
            break;
          case 2:
            // Case: row 2, col 2
            PressNumericAsKeypad('6');
            break;
          case 3:
            // Case: row 2, col 3
            if (funcMode) {
              //Vol Down
              Consumer_write(MEDIA_VOLUME_DOWN);
            } else {
              //Previous Song
              Consumer_write(MEDIA_PREV);
            }

            break;
        }
        break;
      case 3:
        // Cases for row 3 (col 0, col 1, col 2, col 3)
        switch (col) {
          case 0:
            // Case: row 3, col 0
            PressNumericAsKeypad('7');
            break;
          case 1:
            // Case: row 3, col 1
            PressNumericAsKeypad('8');
            break;
          case 2:
            // Case: row 3, col 2
            PressNumericAsKeypad('9');
            break;
          case 3:
            // Case: row 3, col 3
            if (funcMode) {
              //Vol Up
              Consumer_write(MEDIA_VOLUME_UP);
            } else {
              //Next Song
              Consumer_write(MEDIA_NEXT);
            }

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
            delay(1);
            Keyboard_release('\333');
            break;
          case 1:
            // Case: row 4, col 1
            // keypad /
            Keyboard_press('\334');
            delay(1);
            Keyboard_release('\334');
            break;
          case 2:
            // Case: row 4, col 2
            // keypad *
            Keyboard_press('\335');
            delay(1);
            Keyboard_release('\335');
            break;
          case 3:
            // Case: row 4, col 3
            //keypad -
            Keyboard_press('\336');
            delay(1);
            Keyboard_release('\336');
            break;
        }
        break;
    }
    return;
  } else if (isKeyUp) {
    //Keyup events
    switch (row) {
      case 0:
        switch (col) {
          case 1:
            // Case: row 0, col 1
            funcMode = false;
            break;
        }
        break;
    }
    return;
  }

}
