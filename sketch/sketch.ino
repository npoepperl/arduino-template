#include <LedControl.h>

LedControl lc=LedControl(12,11,10,1);

void setup(){
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop(){

  printI();
  delay(1000);
  printLuv();
  delay(1000);
  printU();
  delay(1000);
  
}

void printI(){
  lc.setRow(0,0,B00000000);
  lc.setRow(0,1,B00011000);
  lc.setRow(0,2,B00011000);
  lc.setRow(0,3,B00011000);
  lc.setRow(0,4,B00011000);
  lc.setRow(0,5,B00011000);
  lc.setRow(0,6,B00011000);
  lc.setRow(0,7,B00000000);
}

void printLuv(){
  lc.setRow(0,0,B00000000);
  lc.setRow(0,1,B01100110);
  lc.setRow(0,2,B10011001);
  lc.setRow(0,3,B10000001);
  lc.setRow(0,4,B01000010);
  lc.setRow(0,5,B00100100);
  lc.setRow(0,6,B00011000);
  lc.setRow(0,7,B00000000);
}

void printU(){
  lc.setRow(0,0,B00000000);
  lc.setRow(0,1,B01100110);
  lc.setRow(0,2,B01100110);
  lc.setRow(0,3,B01100110);
  lc.setRow(0,4,B01100110);
  lc.setRow(0,5,B01111110);
  lc.setRow(0,6,B00111100);
  lc.setRow(0,7,B00000000);
}

