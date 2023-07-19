/*
    Toby's Low Cost Macro Keyboard
*/

#ifndef USER_USB_RAM
#error "Require USB RAM. Go Tools > USB Setting and pick the 2nd option in the dropdown list"
#endif

#include "src/userUsbHidMediaKeyboard/USBHIDMediaKeyboard.h"
#include "win-zh_util.h"

////////////// HARDWARE CONFIG //////////
//Mode LED
#define LED_A 34
#define LED_B 33

//RGB LED
#define LED_Red 32
#define LED_Green 31
#define LED_Blue 30

//Mode switch
#define SWITCH 14

//Button (Mechnical, left to right)
#define BTN_1 15
#define BTN_2 16
#define BTN_3 17
#define BTN_4 11

///////////////// RUNTIME ///////////////
//Current Mode
bool modeA = true;

//Previous button states
bool bt1ActiveState = false;
bool bt2ActiveState = false;
bool bt3ActiveState = false;
bool bt4ActiveState = false;

//Current button states
bool bt1Active = false;
bool bt2Active = false;
bool bt3Active = false;
bool bt4Active = false;

////////////// Special Hotkeys //////////////////
//When Button 2 is hold in mode A, activate volume Mode to 
//allow button 3 and 4 to change volume instead of prev / next song
bool volMode = false;

void setup() {
  USBInit();
  pinMode(SWITCH, INPUT);
  
  //Modes LED
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);

  //Bottom RGB LEDs
  //by defaults it follows the LED A or B
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  
  if (!digitalRead(SWITCH)){
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);

    digitalWrite(LED_Blue, HIGH);
    digitalWrite(LED_Red, LOW);
  }else{
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);

    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Red, HIGH);
  }

  
  //LED G reserve for media controller Button 2 long press
  digitalWrite(LED_Green, LOW);
}

void loop() {
  //Read the mode of the keyboard
  modeA = !digitalRead(SWITCH);

  //Read the button states, default PULL HIGH (aka LOW Activate)
  bt1Active = !digitalRead(BTN_1);
  bt2Active = !digitalRead(BTN_2);
  bt3Active = !digitalRead(BTN_3);
  bt4Active = !digitalRead(BTN_4);

  if (modeA == HIGH){
    //Mode A
    //Media Controller

    //Button 1: Play / Pause
    if (bt1ActiveState != bt1Active){
      bt1ActiveState = bt1Active;
      if (bt1Active){
        Consumer_press(MEDIA_PLAY_PAUSE);
      }else{
        Consumer_release(MEDIA_PLAY_PAUSE);
      }
    }

    //Button 2: Toggle Playlist / Volumn Control Mode
    if (bt2ActiveState != bt2Active){
      bt2ActiveState = bt2Active;
      if (bt2Active){
        volMode = true;
        digitalWrite(LED_Green, HIGH);
      }else{
        volMode = false;
        digitalWrite(LED_Green, LOW);
      }
    }

    //Previous Song / Vol Down
    if (bt3ActiveState != bt3Active){
      bt3ActiveState = bt3Active;
      if (volMode){
         //Button 2 is held
        if (bt3Active){
          Consumer_press(MEDIA_VOLUME_DOWN);
        }else{
          Consumer_release(MEDIA_VOLUME_DOWN);
        }
      }else{
         //Default mode
        if (bt3Active){
          Consumer_press(MEDIA_PREV);
        }else{
          Consumer_release(MEDIA_PREV);
        }
      }
      
    }

    //Button 4: Next Song / Vol Up
    if (bt4ActiveState != bt4Active){
      bt4ActiveState = bt4Active;
       if (volMode){
          //Button 2 is held
          if (bt4Active){
            Consumer_press(MEDIA_VOLUME_UP);
          }else{
            Consumer_release(MEDIA_VOLUME_UP);
          }
       }else{
          //Default mode
          if (bt4Active){
            Consumer_press(MEDIA_NEXT);
          }else{
             Consumer_release(MEDIA_NEXT);
          }
       }
    }

    //Set the status LED
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_Blue, HIGH);
    digitalWrite(LED_Red, LOW);
  }else{
    //Mode B
    //For printing out information
    
    //Button 1
    if (bt1ActiveState != bt1Active){
      bt1ActiveState = bt1Active;
      if (bt1Active){
        //Open browser
        Consumer_press(CONSUMER_BROWSER_HOME);
        delay(100);
        Consumer_release(CONSUMER_BROWSER_HOME);
        delay(1500);
        //Type website
        Keyboard_write('h');
        delay(30);
        Keyboard_write('t');
        delay(30);
        Keyboard_write('t');
        delay(30);
        Keyboard_write('p');
        delay(30);
        Keyboard_write('s');
        delay(30);
        Keyboard_write(':');
        delay(30);
        Keyboard_write('/');
        delay(30);
        Keyboard_write('/');
        delay(30);
        Keyboard_write('i');
        delay(30);
        Keyboard_write('m');
        delay(30);
        Keyboard_write('u');
        delay(30);
        Keyboard_write('s');
        delay(30);
        Keyboard_write('l');
        delay(30);
        Keyboard_write('a');
        delay(30);
        Keyboard_write('b');
        delay(30);
        Keyboard_write('.');
        delay(30);
        Keyboard_write('c');
        delay(30);
        Keyboard_write('o');
        delay(30);
        Keyboard_write('m');
        delay(30);
        Keyboard_write(KEY_RETURN);
        delay(30);
      }
    }
  
    //Button 2
    if (bt2ActiveState != bt2Active){
      bt2ActiveState = bt2Active;
      if (bt2Active){
        typeChinese("45935"); //這
        typeChinese("44111"); //是
        Keyboard_write(' ');
        Keyboard_write('U');
        Keyboard_write('T');
        Keyboard_write('F');
        Keyboard_write('-');
        Keyboard_write('8');
        Keyboard_write(' ');
        typeChinese("43706"); //的
        typeChinese("42148"); //中
        typeChinese("42213"); //文
        typeChinese("49129"); //輸
        typeChinese("42328"); //出
      }
    }

    //Button 3
    if (bt3ActiveState != bt3Active){
      bt3ActiveState = bt3Active;
      if (bt3Active){
        typeChinese("36889"); //這
        typeChinese("26159"); //是
        Keyboard_write(' ');
        Keyboard_write('b');
        Keyboard_write('i');
        Keyboard_write('g');
        Keyboard_write('5');
        Keyboard_write(' ');
        typeChinese("30340"); //的
        typeChinese("20013"); //中
        typeChinese("25991"); //文
        typeChinese("36664"); //輸
        typeChinese("20986"); //出
      }
    }

    //Button 4
    if (bt4ActiveState != bt4Active){
      bt4ActiveState = bt4Active;
      if (bt4Active){
        Keyboard_write('S');
        Keyboard_write('e');
        Keyboard_write('e');
        Keyboard_write(' ');
        Keyboard_write('m');
        Keyboard_write('o');
        Keyboard_write('r');
        Keyboard_write('e');
        Keyboard_write(' ');
        Keyboard_write('o');
        Keyboard_write('n');
        Keyboard_write(' ');
        Keyboard_write('h');
        Keyboard_write('t');
        Keyboard_write('t');
        Keyboard_write('p');
        Keyboard_write('s');
        Keyboard_write(':');
        Keyboard_write('/');
        Keyboard_write('/');
        Keyboard_write('g');
        Keyboard_write('i');
        Keyboard_write('t');
        Keyboard_write('h');
        Keyboard_write('u');
        Keyboard_write('b');
        Keyboard_write('.');
        Keyboard_write('c');
        Keyboard_write('o');
        Keyboard_write('m');
        Keyboard_write('/');
        Keyboard_write('t');
        Keyboard_write('o');
        Keyboard_write('b');
        Keyboard_write('y');
        Keyboard_write('c');
        Keyboard_write('h');
        Keyboard_write('u');
        Keyboard_write('i');
        Keyboard_write('/');
        Keyboard_write('4');
        Keyboard_write('x');
        Keyboard_write('M');
        Keyboard_write('a');
        Keyboard_write('c');
        Keyboard_write('r');
        Keyboard_write('o');
        Keyboard_write('p');
        Keyboard_write('a');
        Keyboard_write('d');
      }
       
    }
    
    //Set the status LED
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Red, HIGH);
  }
  
  delay(50);  //naive debouncing
}
