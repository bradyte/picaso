//Simple Demo that demonstrates 'print' and 'println' new functionality.

#define DisplaySerial Serial

//-------Picaso DISPLAYS-------

#include "Picaso_Const4D.h"
#include "Picaso_Serial_4DLib.h"

//use Serial0 to communicate with the display.
Picaso_Serial_4DLib Display(&DisplaySerial); 

//---------END-----------------

void setup() {
  //For handling errors
  Display.Callback4D = mycallback ;

  //5 second timeout on all commands  
  Display.TimeLimit4D   = 5000 ;
  
  DisplaySerial.begin(9600) ;

  //--------------------------------Optional reset routine-----------------------------------
  //Reset the Display using D4 of the Arduino (if using the new 4D Arduino Adaptor - Rev 2)
  //If using the old 4D Arduino Adaptor (Rev 1), change D4 to D2 below.
  //If using jumper wires, reverse the logic states below. 
  //Refer to the accompanying application note for important information.
  pinMode(4, OUTPUT);  // Set D4 on Arduino to Output (4D Arduino Adaptor V2 - Display Reset)
  digitalWrite(4, 1);  // Reset the Display via D4
  delay(100);
  digitalWrite(4, 0);  // unReset the Display via D4
  //-----------------------------------------END---------------------------------------------
  
  delay (5000); //let the display start up  

  Display.gfx_ScreenMode(PORTRAIT);
  //Display.gfx_BGcolour(WHITE) ; //change background color to white
  Display.gfx_Cls();            //clear the screen


  Display.println("Hello World!"); 


}

void loop() 
{

}

void mycallback(int ErrCode, unsigned char Errorbyte)
{
  // Pin 13 has an LED connected on most Arduino boards. Just give it a name
  int led = 13;
  pinMode(led, OUTPUT);
  while(1)
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                // wait for 200 ms
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                // wait for 200 ms
  }
}
