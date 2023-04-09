/*
    Toby's Low Cost Macro Keyboard
*/

#ifndef USER_USB_RAM
#error "Require USB RAM. Go Tools > USB Setting and pick the 2nd option in the dropdown list"
#endif

#include "src/userUsbHidMediaKeyboard/USBHIDMediaKeyboard.h"

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

    //Button 1
    if (bt1ActiveState != bt1Active){
      bt1ActiveState = bt1Active;
      if (bt1Active){
        {{codeA1}}
      }
    }

    //Button 2
    if (bt2ActiveState != bt2Active){
      bt2ActiveState = bt2Active;
      if (bt2Active){
        {{codeA2}}
      }
    }

    //Button 3
    if (bt3ActiveState != bt3Active){
      bt3ActiveState = bt3Active;
      if (bt3Active){
        {{codeA3}}
      }
    }

    //Button 4
    if (bt4ActiveState != bt4Active){
      bt4ActiveState = bt4Active;
      if (bt4Active){
        {{codeA4}}
      }
    }

    //Set the status LED
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_Blue, HIGH);
    digitalWrite(LED_Red, LOW);
  }else{
    //Mode B
    
    //Button 1
    if (bt1ActiveState != bt1Active){
      bt1ActiveState = bt1Active;
      if (bt1Active){
        {{codeB1}}
      }
    }

    //Button 2
    if (bt2ActiveState != bt2Active){
      bt2ActiveState = bt2Active;
      if (bt2Active){
        {{codeB2}}
      }
    }

    //Button 3
    if (bt3ActiveState != bt3Active){
      bt3ActiveState = bt3Active;
      if (bt3Active){
        {{codeB3}}
      }
    }

    //Button 4
    if (bt4ActiveState != bt4Active){
      bt4ActiveState = bt4Active;
      if (bt4Active){
        {{codeB4}}
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
