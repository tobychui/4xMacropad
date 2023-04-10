/*
    Windows Chinese Typing Codec for Unicode and Big5

    This is a module that handle Traditional Chinese typing
    on Windows devices using ALT + utf-8 or big5 DEC code 
    method. Note that this only works on computer with native
    Chinese support (Tested on Windows 10 Chinese version for 
    Hong Kong and Taiwan). 
    
    Primary design for CH552G, but in theory, should work with 
    any Arduino board supporting USB HID keyboard.

    CopyRight tobychui, All Right Reserved
*/
#include <Arduino.h>
#include <string.h>

void pressNumericAsKeypad(char in){
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
    return;
    break;
  }
}

void typeChinese(char* keycode){
  //Hold ALT
  Keyboard_press(KEY_LEFT_ALT);
  delay(20);
  for (int i = 0; i < strlen(keycode); i++) {
    pressNumericAsKeypad(keycode[i]);
  }
  //Release ALT
  delay(20);
  Keyboard_release(KEY_LEFT_ALT);
}
