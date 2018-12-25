#define SOUNDPIN           A0
#define THRESHOLDPOTI      A1
#define SOUNDTHRESHOLD     300 //420 // unused

// how long go display the beat detection
#define VISUAL_TIMEOUT     13  


// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

// Our Global Sample Rate, 5000hz
#define SAMPLEPERIODUS 200

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif




void sound_setup()
{
  pinMode(SOUNDPIN, INPUT_PULLUP);

  // Set ADC to 77khz, max for 10bit
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0);

}


int beat_detected=0;

void sound_visual1()
{




  unsigned long time = micros(); // Used to track rate
  float sample, value, envelope, beat, thresh;
  unsigned char i;

  for (i = 0;; ++i) {
    // Read ADC and center so +-512
    sample = (float)analogRead(SOUNDPIN) - 503.f;

    // Filter only bass component
    value = bassFilter(sample);

    // Take signal amplitude and filter
    if (value < 0)value = -value;
    envelope = envelopeFilter(value);

    // Every 200 samples (25hz) filter the envelope
    if (i == 15) {
      // Filter out repeating bass sounds 100 - 180bpm
      beat = beatFilter(envelope);
     // Serial.println(beat);

      int pot = analogRead(THRESHOLDPOTI);


      // Threshold it based on potentiometer on AN1
      thresh = 0.02f * (float) pot;
//      Serial.println("%f.02  - %f.02", beat, thresh);
      
      // If we are above threshold, light up LED
      if (beat > thresh)
      {
        beat_detected=VISUAL_TIMEOUT;
      }


      //Reset sample counter
      i = 0;

//Serial.println(int(beat));
//return;
                update_leds(beat_detected);

    }


    
    // Consume excess clock cycles, to keep at 5000 hz
    //  for(unsigned long up = time+SAMPLEPERIODUS; time > 20 && time < up; time = micros());

  }
  


}


//argument ranges from 0 to 12
void update_leds(int beat)
{

    beat_detected--;

    if(beat<0) beat=0;

    /*
    //beat=random(0,1024);
    beat = map(beat,0,30,0,12);
    beat = min(beat, 13);
    beat = max(beat, 0);
    */
    
  //Serial.println(beat);

  
     for(int j=0;j<NUMPIXELS ;j++) pixels.setPixelColor(j, pixels.Color(8 ,0,16)); 
  
  
    
//    for(int j=0;j<beat;j++)
    for(int j=0;j<beat;j++)
    {
      for(int i=0;i<12;i++)
      {
       if( (i==2) || (i==3) || (i==4) || (i==6) || (i==10) || (i==11) )
       {  
        if(j<13) pixels.setPixelColor(bottom_up[i][12-j], pixels.Color(255,0,0));   
        if(j<8) pixels.setPixelColor(bottom_up[i][12-j], pixels.Color(255,255,0)); 
        if(j<5) pixels.setPixelColor(bottom_up[i][12-j], pixels.Color(0,255,0));      
       }       
       else
       {

       
       
        if(j<13) pixels.setPixelColor(bottom_up[i][j], pixels.Color(255,0,0));   
        if(j<8) pixels.setPixelColor(bottom_up[i][j], pixels.Color(255,255,0)); 
        if(j<5) pixels.setPixelColor(bottom_up[i][j], pixels.Color(0,255,0));      
       }
      } 
    }
   

   //    Serial.println(beat_detected);
   pixels.show(); // This sends the updated pixel color to the hardware.


}












////////////// HELPER




// 20 - 200hz Single Pole Bandpass IIR Filter
float bassFilter(float sample) {
  static float xv[3] = {0, 0, 0}, yv[3] = {0, 0, 0};
  xv[0] = xv[1]; xv[1] = xv[2];
  xv[2] = sample / 9.1f;
  yv[0] = yv[1]; yv[1] = yv[2];
  yv[2] = (xv[2] - xv[0])
          + (-0.7960060012f * yv[0]) + (1.7903124146f * yv[1]);
  return yv[2];
}

// 10hz Single Pole Lowpass IIR Filter
float envelopeFilter(float sample) { //10hz low pass
  static float xv[2] = {0, 0}, yv[2] = {0, 0};
  xv[0] = xv[1];
  xv[1] = sample / 160.f;
  yv[0] = yv[1];
  yv[1] = (xv[0] + xv[1]) + (0.9875119299f * yv[0]);
  return yv[1];
}

// 1.7 - 3.0hz Single Pole Bandpass IIR Filter
float beatFilter(float sample) {
  static float xv[3] = {0, 0, 0}, yv[3] = {0, 0, 0};
  xv[0] = xv[1]; xv[1] = xv[2];
  xv[2] = sample / 7.015f;
  yv[0] = yv[1]; yv[1] = yv[2];
  yv[2] = (xv[2] - xv[0])
          + (-0.7169861741f * yv[0]) + (1.4453653501f * yv[1]);
  return yv[2];
}


