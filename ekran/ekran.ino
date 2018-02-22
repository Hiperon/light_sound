// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            A0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

class LED_RGB_pix{
public:
  void set_pix(int n,int r,int g,int b);
};

void LED_RGB_pix::set_pix(int n,int r,int g,int b){
  pixels.setPixelColor(n, pixels.Color(r,g,b));
}

class ekran{
public:
  int           wiersze;
  int           kolumny;
  LED_RGB_pix   pixel;

  void rozmiar(int a,int b){
    wiersze = a;
    kolumny = b;
  }

  int przeliczenie(int a, int b){
    return(a*wiersze + b - 1);
  }

  void set_one_pix(int,int,int,int,int);
};

void ekran::set_one_pix(int x, int y, int r, int g, int b){
  int nr_pix=przeliczenie(x,y);
  pixel.set_pix(nr_pix,r,g,b);
}

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
/*#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif*/
  // End of trinket special code
  

  pixels.begin(); // This initializes the NeoPixel library.
}

ekran bozek;

LED_RGB_pix my_pixels;

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
bozek.rozmiar(10,9);
  for(int i=1;i<=NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
//  my_pixels.set_pix(i,0,150,0);
    bozek.set_one_pix(0,i,0,150,0);
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}
