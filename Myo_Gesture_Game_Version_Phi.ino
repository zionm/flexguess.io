/* ************************************************************************************
 *                           Gesture Controlled Lab Demo Game Code 
 *                               Written by: Zion Maynard
 *                                    Version phi, 16/06/2020
 * ***********************************************************************************
 */

 // Call Myoduino library 
#include <MyoController.h> 

// Set all LEDs to inputs
const int redLED = 2;
const int blueLED = 3;
const int greenLED = 4;
const int orgLED =5;
// Set all gestures each to a unique pin
#define FIST_PIN 11
#define WAVEIN_PIN 10
#define WAVEOUT_PIN 9
#define FINGERSSPREAD_PIN 8
MyoController myo = MyoController();

// intialize inputs from gesture 
int fiist = 0;
int wave_in =0;
int wave_out=0;
int fing=0;

// intialize random number to be passed into loop
int rand_num =0;


void setup() {

//Set gestures to inputs
pinMode(FIST_PIN, INPUT);
pinMode(WAVEIN_PIN, INPUT);
pinMode(WAVEOUT_PIN, INPUT);
pinMode(FINGERSSPREAD_PIN, INPUT);

// Set LEDs  to outputs
pinMode(redLED, OUTPUT);
pinMode(blueLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(orgLED, OUTPUT);

myo.initMyo();



// turns off all the LEDs at start of program   
digitalWrite(redLED, LOW);
digitalWrite(blueLED, LOW);
digitalWrite(greenLED, LOW);
digitalWrite(orgLED, LOW);
}

void loop() {
myo.updatePose();
randomSeed(analogRead(0));

rand_num = random(2,5);

int fiist = digitalRead(FIST_PIN);
int wave_in = digitalRead(WAVEIN_PIN);
int wave_out = digitalRead(WAVEOUT_PIN);
int fing = digitalRead(FINGERSSPREAD_PIN);   

if (rand_num == 2){
  digitalWrite(redLED,HIGH);
}
else if (rand_num == 3){
  digitalWrite(blueLED,HIGH);
}
else if (rand_num == 4){
  digitalWrite(greenLED,HIGH);
}

else if (rand_num == 5) {
  digitalWrite(orgLED,HIGH);
}

switch ( myo.getCurrentPose() ) {
    case fist:
      digitalWrite(FIST_PIN, HIGH);
      digitalWrite(redLED,LOW);
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN, HIGH);
      digitalWrite(blueLED,LOW);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN, HIGH);
      digitalWrite(greenLED,LOW);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN, HIGH);
      digitalWrite(orgLED,LOW);
      break;
}
}
