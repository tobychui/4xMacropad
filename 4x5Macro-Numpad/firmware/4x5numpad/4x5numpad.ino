/*
    4x5 Numpad

    if you are using the Macro-numpad arrangement, use the other firmware
*/
#ifndef USER_USB_RAM
#error "Require USB RAM. Go Tools > USB Setting and pick the 2nd option in the dropdown list"
#endif

#include "src/userUsbHidMediaKeyboard/USBHIDMediaKeyboard.h"

////////////// HARDWARE CONFIG //////////
//LED OUTPUT
#define LED_OUT 14


//SCAN LINES
//Input Pins. Pull High (When reading is low = pressed)
#define COL_1 15
#define COL_2 16
#define COL_3 17
#define COL_4 11

//Output Pins. Set to low to scan that line
#define ROW_1 32
#define ROW_2 31
#define ROW_3 30
#define ROW_4 34
#define ROW_5 33

///////////////// RUNTIME ///////////////
const int readColSeq[4] = {COL_4, COL_3, COL_2, COL_1};
const int scanRowSeq[5] = {ROW_5, ROW_4, ROW_3, ROW_2, ROW_1};
bool funcMode = false; //If Fn key is hold (Default func key: [0,1]

//The layout is identical to the keypad when view from the front side (i.e. not the MCU side)
int keyPressState[5][4] = {
  {false,false,false,false},
  {false,false,false,false},
  {false,false,false,false},
  {false,false,false,false},
  {false,false,false,false},
};

///////////////// FUNC PROTOTYPES ///////////////
void HandleKeyPressEvents(int row, int col, bool previousState, bool currentState);
void PressNumericAsKeypad(char in);
void UpdateLEDState();


void setup() {
  delay(300);
  USBInit();
  //LED
  pinMode(LED_OUT, OUTPUT);

  //Sensing lines
  pinMode(COL_1, INPUT);
  pinMode(COL_2, INPUT);
  pinMode(COL_3, INPUT);
  pinMode(COL_4, INPUT);

  //Select lines
  pinMode(ROW_1, OUTPUT);
  pinMode(ROW_2, OUTPUT);
  pinMode(ROW_3, OUTPUT);
  pinMode(ROW_4, OUTPUT);
  pinMode(ROW_5, OUTPUT);

  //Set all lines to high (active low)
  digitalWrite(ROW_1, HIGH);
  digitalWrite(ROW_2, HIGH);
  digitalWrite(ROW_3, HIGH);
  digitalWrite(ROW_4, HIGH);
  digitalWrite(ROW_5, HIGH);
}

//Activate the row to be scanned
void setScanningRow(int rowNumber) {
  //Hardcoding the sequence save some RAM and faster :)
  (rowNumber==0)?digitalWrite(scanRowSeq[0], LOW):digitalWrite(scanRowSeq[0], HIGH);
  (rowNumber==1)?digitalWrite(scanRowSeq[1], LOW):digitalWrite(scanRowSeq[1], HIGH);
  (rowNumber==2)?digitalWrite(scanRowSeq[2], LOW):digitalWrite(scanRowSeq[2], HIGH);
  (rowNumber==3)?digitalWrite(scanRowSeq[3], LOW):digitalWrite(scanRowSeq[3], HIGH);
  (rowNumber==4)?digitalWrite(scanRowSeq[4], LOW):digitalWrite(scanRowSeq[4], HIGH);
  
  //Disable all and enable the target one not sure why it is not working
  
  //Activate the target row
  //int targetRowPin = scanRowSeq[rowNumber];
  //digitalWrite(targetRowPin, LOW);
  //delay(30);  //naive debouncing
}

//Read and return the key press status of a given column
//Notes: keys are low activated. When not press, the keys are pull HIGH
bool readKeyPress(int colNumber){
  int readPin = readColSeq[colNumber];
  return (digitalRead(readPin) == 0);
}


//Read all the switches states and update to the global array
void updateSwitchStatus() {
  for (int i = 0; i < 5; i++) {
    //For each of the row, read each of the col switch
    setScanningRow(i);
    for (int j = 0; j < 4; j++) {
      bool isKeyDown = readKeyPress(j);
      bool prevState = keyPressState[i][j];
      if (isKeyDown != prevState){
        //Trigger on change events
        HandleKeyPressEvents(i,j,prevState,isKeyDown);
        delay(30); //resp time
      }
      keyPressState[i][j] = isKeyDown;
    }
  }
}

//Update the LED status
void UpdateLEDState(){
  if (funcMode) {
    digitalWrite(LED_OUT, HIGH);
  } else {
    digitalWrite(LED_OUT, LOW);
  }
}

void loop() {
  //Read the mode of the keyboard
  updateSwitchStatus();
  
  //Update the NumLock LED
  UpdateLEDState();
}
