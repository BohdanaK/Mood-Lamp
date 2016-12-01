// Output
int redPin = 9;   // Red LED,   connected to digital pin 9
int grnPin = 10;  // Green LED, connected to digital pin 10
int bluPin = 11;  // Blue LED,  connected to digital pin 11

unsigned int hue = 0;
unsigned int saturation = 0;
unsigned int value = 0;

// Set up the LED outputs
void setup()
{
  pinMode(redPin, OUTPUT);   // sets the pins as output
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT); 

  hue = 0;          // hue from 0 to 359
  saturation = 90;  // sat from 0 to 100
  value = 255;      // val from 0 to 255
}

// Main program
void loop()
{
    hsvToRgb(hue, saturation, value);  
    delay(30);     // speed of color change
    hue = (hue + 1) % 360;  
}

// BELOW THIS LINE IS THE HSV MATH
void hsvToRgb(unsigned int h, unsigned int s, unsigned int v){
    int hI, a, vMin, vInc, vDec, out;

    if (h >= 360) h = 0;  
    if (s > 100) s = 100;
    if (v > 255) v = 255;
    
    vMin = round(((100-s)*v) * 0.01f);
    a = round((v - vMin) * ((h % 60) * 0.0167f));
    vInc = vMin + a;
    vDec = v - a;
    hI = (h/60) % 60;

    switch (hI) {
      case 0: {
        analogWrite(redPin, 255 - v);
        analogWrite(grnPin, 255 - vInc);
        analogWrite(bluPin, 255 - vMin);
      }
        break;
      case 1: {
        analogWrite(redPin, 255 - vDec);
        analogWrite(grnPin, 255 - v);
        analogWrite(bluPin, 255 - vMin);
      }
        break;
      case 2: {
        analogWrite(redPin, 255 - vMin);
        analogWrite(grnPin, 255 - v);
        analogWrite(bluPin, 255 - vInc);
      }
        break;
      case 3: {
        analogWrite(redPin, 255 - vMin);
        analogWrite(grnPin, 255 - vDec);
        analogWrite(bluPin, 255 - v);
      }
        break;
      case 4: {
        analogWrite(redPin, 255 - vInc);
        analogWrite(grnPin, 255 - vMin);
        analogWrite(bluPin, 255 - v);
      }
        break;
      case 5: {
        analogWrite(redPin, 255 - v);
        analogWrite(grnPin, 255 - vMin);
        analogWrite(bluPin, 255 - vDec);
      }
        break;
      default: {
        analogWrite(redPin, 255 - 0);
        analogWrite(grnPin, 255 - 0);
        analogWrite(bluPin, 255 - 0);
      }
        break;
    }
}
