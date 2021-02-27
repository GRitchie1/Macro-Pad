#include "HID-Project.h"

//
//
// Encoder 1
//
//

// Rotary Encoder 1 Inputs
#define First_inputDT 7
#define First_inputCLK 6
#define First_inputSwitch 5

// Rotary Encoder 1 Variables
int First_counter1 = 0; 
int First_counter2 = 0; 
int First_currentStateCLK;
int First_previousStateCLK; 
String First_encdir ="";


//
//
// Encoder 2
//
//

// Rotary Encoder 2 Inputs
#define Second_inputDT 4
#define Second_inputCLK 3
#define Second_inputSwitch 2

// Rotary Encoder 2 Variables
int Second_counter1 = 0; 
int Second_counter2 = 0; 
int Second_currentStateCLK;
int Second_previousStateCLK; 
String Second_encdir ="";


//
//
// Encoder 3
//
//

// Rotary Encoder 3 Inputs
#define Third_inputDT A1
#define Third_inputCLK A2
#define Third_inputSwitch A3

// Rotary Encoder 3 Variables
int Third_counter1 = 0; 
int Third_counter2 = 0; 
int Third_currentStateCLK;
int Third_previousStateCLK; 
String Third_encdir ="";




//
//
// Switches (1-5)
//
//

int Switch1 = 8;
int Switch2 = 9;
int Switch3 = 10;
int Switch4 = 16;
int Switch5 = 14;



void setup() { 
   // Setup Serial Monitor
   Serial.begin (9600);
   Consumer.begin();

      //Encoder 1
   // Set encoder pins as inputs  
   pinMode (First_inputCLK,INPUT_PULLUP);
   pinMode (First_inputDT,INPUT_PULLUP);
   pinMode (First_inputSwitch,INPUT_PULLUP);


   //Encoder 2
   // Set encoder pins as inputs  
   pinMode (Second_inputCLK,INPUT_PULLUP);
   pinMode (Second_inputDT,INPUT_PULLUP);
   pinMode (Second_inputSwitch,INPUT_PULLUP);



   //Encoder 3
   // Set encoder pins as inputs  
   pinMode (Third_inputCLK,INPUT_PULLUP);
   pinMode (Third_inputDT,INPUT_PULLUP);
   pinMode (Third_inputSwitch,INPUT_PULLUP);



  //Switches (1-5)
  pinMode (Switch1,INPUT_PULLUP);
  pinMode (Switch2,INPUT_PULLUP);
  pinMode (Switch3,INPUT_PULLUP);
  pinMode (Switch4,INPUT_PULLUP);
  pinMode (Switch5,INPUT_PULLUP);





while (!digitalRead(Third_inputSwitch)) {
  
}
 } 






 void loop() { 

  //
  //
  //Encoder 1
  //
  //
  
  // Read the current state of First_inputCLK
   First_currentStateCLK = digitalRead(First_inputCLK);
    
   // If the previous and the current state of the First_inputCLK are different then a pulse has occured
   if (First_currentStateCLK != First_previousStateCLK){ 
     // If the First_inputDT state is different than the First_inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(First_inputDT) != First_currentStateCLK) { 
       First_counter1++;
       Serial.print("OFF");
       if (First_counter1>1){
       First_counter1=0;
       First_encdir ="CCW";
       Consumer.write(MEDIA_VOLUME_DOWN);                                     //Encoder 1 Down - AntiClockwise
       }
     } else {
       Serial.print("ON");
       First_counter2++;
       if (First_counter2>1){
       First_counter2=0;
       First_encdir ="CW";

       Consumer.write(MEDIA_VOLUME_UP);                                       //Encoder 1 Up - Clockwise
       }
     }

   }
   // Update First_previousStateCLK with the current state
   First_previousStateCLK = First_currentStateCLK; 

     if (!digitalRead(First_inputSwitch)) {
   
    Consumer.write(MEDIA_VOLUME_MUTE);                                        //Encoder 1 Switch
   
    delay(300);
  }


  //
  //
  //Encoder 2
  //
  //
  
  // Read the current state of Second_inputCLK
   Second_currentStateCLK = digitalRead(Second_inputCLK);
    
   // If the previous and the current state of the Second_inputCLK are different then a pulse has occured
   if (Second_currentStateCLK != Second_previousStateCLK){ 
     // If the Second_inputDT state is different than the Second_inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(Second_inputDT) != Second_currentStateCLK) { 
       Second_counter1++;
       Serial.print("OFF");
       if (Second_counter1>1){
       Second_counter1=0;
       Second_encdir ="CCW";
       Keyboard.write(KEY_F13);                                                       //Encoder 2 Down - AntiClockwise
       }
     } else {
       Serial.print("ON");
       Second_counter2++;
       if (Second_counter2>1){
       Second_counter2=0;
       Second_encdir ="CW";

       Keyboard.write(KEY_F14);                                                       //Encoder 2 Up - Clockwise
       }
     }

   }
   // Update Second_previousStateCLK with the current state
   Second_previousStateCLK = Second_currentStateCLK; 

     if (!digitalRead(Second_inputSwitch)) {
   
    Keyboard.write(KEY_F15);                                                          //Encoder 2 Switch
   
    delay(300);
  }





  //
  //
  //Encoder 3
  //
  //
  
  // Read the current state of Third_inputCLK
   Third_currentStateCLK = digitalRead(Third_inputCLK);
    
   // If the previous and the current state of the Third_inputCLK are different then a pulse has occured
   if (Third_currentStateCLK != Third_previousStateCLK){ 
     // If the Third_inputDT state is different than the Third_inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(Third_inputDT) != Third_currentStateCLK) { 
       Third_counter1++;
       Serial.print("OFF");
       if (Third_counter1>1){
       Third_counter1=0;
       Third_encdir ="CCW";
       Keyboard.write(KEY_F16);                                                           //Encoder 3 Down - AntiClockwise
       }
     } else {
       Serial.print("ON");
       Third_counter2++;
       if (Third_counter2>1){
       Third_counter2=0;
       Third_encdir ="CW";

       Keyboard.write(KEY_F17);                                                            //Encoder 3 Up - Clockwise
       }  
     }

   }
   // Update Third_previousStateCLK with the current state
   Third_previousStateCLK = Third_currentStateCLK; 

     if (!digitalRead(Third_inputSwitch)) {
   
    Keyboard.write(KEY_F18);                                                            //Encoder 3 Switch
   
    delay(300);
  }





//Switches 
// ================================================================================================================================

  if (!digitalRead(Switch1)) {
   
    //Consumer.write(MEDIA_VOLUME_MUTE);                                                            //Switch 1
    //Keyboard.write(KEY_F19);

    
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    const char notepad[] = "notepad++";
    for(int i =0; i < strlen(notepad); i++ ) {
      char c = notepad[i];
      Keyboard.write(c);
    }
    delay(50);
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    
    delay(300);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('n');
    Keyboard.releaseAll();
    
    
    
    delay(2000);
  }


  if (!digitalRead(Switch2)) {
   
    //Consumer.write(MEDIA_VOLUME_MUTE);                                                            //Switch 2
    Keyboard.write(KEY_F20);
    delay(300);
  }


  if (!digitalRead(Switch3)) {
   
    //Consumer.write(MEDIA_VOLUME_MUTE);                                                            //Switch 3
    Keyboard.write(KEY_F21);
    delay(300);
  }


  if (!digitalRead(Switch4)) {
   
    //Consumer.write(MEDIA_VOLUME_MUTE);                                                            //Switch 4
    Keyboard.write(KEY_F22);
    delay(300);
  }


  if (!digitalRead(Switch5)) {
   
    //Consumer.write(MEDIA_VOLUME_MUTE);                                                            //Switch 5
    Keyboard.write(KEY_F23);
    delay(300);
  }

  


  
   
 }
