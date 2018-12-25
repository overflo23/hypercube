// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include "cube_structures.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define LEDPIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      156

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second

void setup() 
{
  Serial.begin(115200);
  sound_setup();
  pixels.begin(); // This initializes the NeoPixel library.
  
}



void loop() {


sound_visual1();

  
/*

for(int i=0;i<500;i+=3)
{
 runner(Wheel(i%255),10);
}




for(int i=0;i<500;i+=3)
{
 plasma(Wheel(i%255),12);
}

return;
*/



/*
int target = random(10,100);
int entropy = random(2,20);



for(int i=5;i<target;i++)
{
 regenbogen_kaleidoskop(i,entropy);
}
for(int i=target;i>5;i--)
{
 regenbogen_kaleidoskop(i,entropy);
}
*/





 /*
 for(int j=0;j<255;j++)
 {

  goback(Wheel(j),15,0,12);
  gofront(Wheel(j),15,0,12);  
  goleft(Wheel(j),15,0,12);  
  up(Wheel(j),15,0,12);
  goright(Wheel(j),15,0,12); 
  down(Wheel(j),15,0,12);
 }
 return;
*/


/*
 ganze_streben();
 return;
*/


 /*
 for(int i=0;i<256;i++)
 {
   full_cube( Wheel( i ) );
   delay(40);
 }
 return;
*/


 
 



}






