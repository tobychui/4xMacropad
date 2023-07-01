/*
 * Numpad.ino
 * This script convert chars (e.g. '1') into numpad key ids
 */

void PressNumericAsKeypad(char in){
  int delayTime = 1;
  switch (in) {
  case '0':
    Keyboard_press('\352');
    delay(delayTime);
    Keyboard_release('\352');
    break;
  case '1':
    Keyboard_press('\341');
    delay(delayTime);
    Keyboard_release('\341');
    break;
  case '2':
    Keyboard_press('\342');
    delay(delayTime);
    Keyboard_release('\342');
    break;
  case '3':
    Keyboard_press('\343');
    delay(delayTime);
    Keyboard_release('\343');
    break;
  case '4':
    Keyboard_press('\344');
    delay(delayTime);
    Keyboard_release('\344');
    break;
  case '5':
    Keyboard_press('\345');
    delay(delayTime);
    Keyboard_release('\345');
    break;
  case '6':
    Keyboard_press('\346');
    delay(delayTime);
    Keyboard_release('\346');
    break;
  case '7':
    Keyboard_press('\347');
    delay(delayTime);
    Keyboard_release('\347');
    break;
  case '8':
    Keyboard_press('\350');
    delay(delayTime);
    Keyboard_release('\350');
    break;
  case '9':
    Keyboard_press('\351');
    delay(delayTime);
    Keyboard_release('\351');
    break;
  default:
    break;
  }
}

void UpdateNumlockState(){
  if (funcMode) {
    digitalWrite(LED_NUMLOCK, HIGH);
  } else {
    digitalWrite(LED_NUMLOCK, LOW);
  }
}
