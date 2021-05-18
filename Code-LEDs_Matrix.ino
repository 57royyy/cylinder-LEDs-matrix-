
///// Including all the libraries we need /////
#include <TimeLib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

///// Defining some parameters  /////
#define TIME_HEADER  "T"
#define TIME_REQUEST  7
#define LEDS 3
#define BUTTON_set_time  9
#define BUTTON_hour 10
#define BUTTON_minute 11
#define BUTTON_color 6


///// Initialization of some variables and functions/////

int hournbr = 0;
int minutenbr = 0;
int C=0;
int x = matrix.width();

const uint16_t Colors[] = {             ///// Colors: the function to switch colors, from a list of colors. Here we have of them
  matrix.Color(255,0,0),matrix.Color(0,255,0),matrix.Color(0,0,255),matrix.Color(255,255,0),matrix.Color(238,130,238)
  };
  
String Values(int Hour, int Min) {      ///// Values: the function to put the time in string and in the right format
  String H ;
  String M;
  String T;
    if (Hour < 10) {                    ///// If the hour is only one digit, it had a zero before it
      H = "0" + String(Hour);}
    else {
      H = String(Hour);}
    if (Min < 10) {
      M = "0" + String(Min);}           ///// If the minute is only one digit, it had a zero before it
    else {
      M = String (Min);}
  T = H + ":" + M;                      ///// Everything in string, even the two points
  return T ;
}

///// Initialization of the Matrix of numbers /////

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(19, 11, LEDS,              ///// numbers of LED's strips: 19 in width and 11 in height
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,       //// Top/Bottom Right/Left Columns/Rows ZigZag/Progressive : to set how the LED's are arranged
                            NEO_GRB            + NEO_KHZ800);

                            

void setup() {
  matrix.begin();                                     ///// Start the Matrix, start on "00:00"
  matrix.setTextWrap(false);
  matrix.setBrightness(100);                          ///// Set the Colors, the Brithness...
  matrix.setTextColor(Colors[0]);
  Serial.begin(9600);                                 ///// To be able to see the values in the serial monitor 

///// Setting a pullup pin for each button /////
  pinMode(BUTTON_set_time, INPUT_PULLUP);
  pinMode(BUTTON_hour, INPUT_PULLUP);
  pinMode(BUTTON_minute, INPUT_PULLUP);
  pinMode(BUTTON_color, INPUT_PULLUP);
  
}



void loop() {
  ///// While loop to enable to set the time /////
  
  while ((digitalRead(BUTTON_set_time) == LOW)) {     ///// while the "setup" button is pressed 
      if (digitalRead(BUTTON_hour) == LOW) {          ///// if the hour button is pressed
          hournbr += 1;
          if (hournbr >= 24) {                        ///// to make sure to stay in the 24 hours format
              hournbr = 0;}
      delay(100);                                     ///// a delay to make sure each push is counted individualy 
      }
    
      if (digitalRead(BUTTON_minute) == LOW) {        ///// if the minute button is pressed
          minutenbr += 1;
          if (minutenbr >= 60) {                      ///// to make sure to stay in the 60 minutes format
              minutenbr = 0;}
      delay(100);
      }
      
      if (digitalRead(BUTTON_color) == LOW){          ///// if the color button is pressed
          C+=1;   
          matrix.setTextColor(Colors[C]);             ///// switch to the next color
          matrix.show();
          if (C>=4){                                  ///// Here we have 5 colors : C can go from 0 to 4 
              C=-1;}
      delay(100);
      }
 }    

///// After all the changes, we set the new time /////
 setTime(hournbr, minutenbr, 00, 0, 0, 0);            ///// setTime format : (Hour,Minute,Seconde,Day,Month,Year) and we only want the Hour and Minute
  
///// Putting the new time on the matrix, and the spinning motion  /////
String Time = Values(hournbr, minutenbr);             ///// Creating the variable Time from hourbnr and minutenbr, in string with Values     

  matrix.fillScreen(0);
  matrix.setCursor(x, 2);
  matrix.print(Time);                                 ///// The matrix forms the desired Time (this value is also printed on the serial monitor)
  Serial.println(Time);
  if (--x < -36) {                                    ///// Limit the spinning motion of the matrix 
    x = matrix.width();}
  matrix.show();
  delay(200);
}
