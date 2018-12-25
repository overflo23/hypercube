void ganze_streben()
{

  uint32_t color = 0 ;
   
  for(int i=0;i<12;i++)
  {
   color= Wheel(random(0,255));
   for(int j=0;j<13;j++)
   {   
    pixels.setPixelColor(bottom_up[i][j], color); 
   
   }
   pixels.show(); // This sends the updated pixel color to the hardware.
   delay(50);
  
  }
}



void full_cube(uint32_t color)
{
   for(int j=0;j<156;j++)
   {   
    pixels.setPixelColor(j, color);   
   }
   pixels.show(); // This sends the updated pixel color to the hardware.

  
}


void all_off()
{
 for(int j=0;j<156;j++)
   {   
    pixels.setPixelColor(j, 0); 
   
   } 
}




void down(uint32_t color, int pause, int min, int max)
{
 


 
  all_off();
 for(int i=max-1;i>=min;i--)
 {
  pixels.setPixelColor(bottom_up[4][i], color);  
  pixels.setPixelColor(bottom_up[5][i], color);  
  pixels.setPixelColor(bottom_up[6][i], color);  
  pixels.setPixelColor(bottom_up[7][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }





}



void up(uint32_t color, int pause, int min, int max)
{
  all_off();
 for(int i=min;i<=max;i++)
 {
  pixels.setPixelColor(bottom_up[4][i], color);  
  pixels.setPixelColor(bottom_up[5][i], color);  
  pixels.setPixelColor(bottom_up[6][i], color);  
  pixels.setPixelColor(bottom_up[7][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }


  
}





void goright(uint32_t color, int pause, int min, int max)
{

  
  
  all_off();
 for(int i=min;i<=max;i++)
 {
  pixels.setPixelColor(bottom_up[0][i], color);  
  pixels.setPixelColor(bottom_up[2][i], color);  
  pixels.setPixelColor(bottom_up[9][i], color);  
  pixels.setPixelColor(bottom_up[11][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }


  
}



void goleft(uint32_t color, int pause, int min, int max)
{

  
  
  all_off();
  
 for(int i=max;i>=min;i--)
 {
  pixels.setPixelColor(bottom_up[0][i], color);  
  pixels.setPixelColor(bottom_up[2][i], color);  
  pixels.setPixelColor(bottom_up[9][i], color);  
  pixels.setPixelColor(bottom_up[11][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }


  
}



void gofront(uint32_t color, int pause, int min, int max)
{

  
  
  all_off();
  
 for(int i=max;i>=min;i--)
 {
  pixels.setPixelColor(bottom_up[1][i], color);  
  pixels.setPixelColor(bottom_up[3][i], color);  
  pixels.setPixelColor(bottom_up[8][i], color);  
  pixels.setPixelColor(bottom_up[10][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }


  
}


void goback(uint32_t color, int pause, int min, int max)
{

  
  
  all_off();
  
 for(int i=min;i<=max;i++)
 {
  pixels.setPixelColor(bottom_up[1][i], color);  
  pixels.setPixelColor(bottom_up[3][i], color);  
  pixels.setPixelColor(bottom_up[8][i], color);  
  pixels.setPixelColor(bottom_up[10][i], color);      

  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(pause);
  all_off();  
 }


  
}


int global_counter=0;

void regenbogen_kaleidoskop(int wait, int entropy)
{
  uint32_t color = 0 ;
  if(global_counter>255) global_counter=0;
  


  // pixels.setPixelColor(bottom_up[i][6], Wheel((k+i)%255));
   for(int j=0;j<7;j++)
   {   
     global_counter++;
     color= Wheel((global_counter+(j*entropy))%255);

    for(int i=0;i<12;i++)
    {
    
      if(!j)
      {
      pixels.setPixelColor(bottom_up[i][6], color ); 
      }
      else
      {
       pixels.setPixelColor(bottom_up[i][6-j], color ); 
       pixels.setPixelColor(bottom_up[i][6+j], color );   
      }      
    }
   }
   
   pixels.show(); // This sends the updated pixel color to the hardware.
   delay(wait);



  
}


#define PI 3.14159265

void plasma(uint32_t c, int cycles) 
{



  


  float y;
  byte  r, g, b, r2, g2, b2;

  // Need to decompose color into its r, g, b elements
  g = (c >> 16) & 0x7f;
  r = (c >>  8) & 0x7f;
  b =  c        & 0x7f; 

  for(int x=0; x<(pixels.numPixels()); x++)
  {
    for(int i=0; i<pixels.numPixels(); i++) {
      y = sin(PI * (float)cycles * (float)(x + i) / (float)pixels.numPixels());
      if(y >= 0.0) {
        // Peaks of sine wave are white
        y  = 1.0 - y; // Translate Y to 0.0 (top) to 1.0 (center)
        r2 = 128 - (byte)((float)(128 - r) * y);
        g2 = 128 - (byte)((float)(128 - g) * y);
        b2 = 128 - (byte)((float)(128 - b) * y);
      } else {
        // Troughs of sine wave are black
        y += 1.0; // Translate Y to 0.0 (bottom) to 1.0 (center)
        r2 = (byte)((float)r * y);
        g2 = (byte)((float)g * y);
        b2 = (byte)((float)b * y);
      }
      pixels.setPixelColor(i, r2, g2, b2);
    }
    
  //     strip.setPixelColor(timelookup[(hour*5)], strip.Color(255,255,255));
    
    
    pixels.show();


  }
}







void runner(uint32_t color, int wait)
{

  for(int i=0;i<pixels.numPixels();i++)
  {
    all_off();
   
   pixels.setPixelColor(i, color );    
   if(i<pixels.numPixels()-1)  pixels.setPixelColor(i+1, color );  
   if(i<pixels.numPixels()-2)  pixels.setPixelColor(i+2, color );   

   
   pixels.show(); // This sends the updated pixel color to the hardware.
   delay(wait);
  }

}




/// HELPER





// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}









  
