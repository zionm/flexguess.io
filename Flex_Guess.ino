
/*
 * Developed by Zion Maynard
 * This code powers the Flex Guess Gesture control game that assists physicians in facilitating hand rehabilitation.
 * Last Updated: 02 Sep 2020
 */




#include <MyoController.h>


#define FIST_PIN 4
#define WAVEIN_PIN 2
#define WAVEOUT_PIN 9
#define DOUBLETAP_PIN 3
#define FINGERSSPREAD_PIN 11

MyoController myo = MyoController();

bool LED_FistIn_Status;
bool LED_WaveIn_Status;
bool LED_WaveOut_Status;
bool LED_FingerSpread_Status;

unsigned long lastMillis_Sampling;
unsigned long lastMillis_FistIn;
unsigned long lastMillis_WaveIn;
unsigned long lastMillis_WaveOut;
unsigned long lastMillis_FingerSpread;

int ledDelay_FistIn = 500;
int ledDelay_WaveIn = 500;
int ledDelay_WaveOut = 500;
int ledDelay_FingerSpread = 500;

String movementStr[4] = {"FistIn", "WaveIn", "WaveOut", "FingerSpread"};
uint8_t ledOutput[4] = {4, 2, 9, 11};
uint8_t randomIntSelected;
String randomStrSelected;
uint8_t userMovement;
bool taskComplete = LOW;

void setup() {

  Serial.begin(9600);
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);

  for (int x = 0; x<4; x++){
    digitalWrite(ledOutput[x], LOW);
  }

  myo.initMyo();
}

void loop() {

  randomIntSelected = random(0, 4);
  digitalWrite(ledOutput[randomIntSelected], HIGH);
  //randomStrSelected = movementStr(randomIntSelected);

  while (taskComplete == LOW){
    
     myo.updatePose();

    switch ( myo.getCurrentPose() ) {
      case fist:
        userMovement = 0;
        break;
      case waveIn:
        userMovement = 1;
        break;
      case waveOut:
        userMovement = 2;
        break;
      case fingersSpread:
        userMovement = 3;
        break;
    }
  
    if(userMovement == randomIntSelected){
      digitalWrite(ledOutput[randomIntSelected], LOW);
      taskComplete = HIGH;
      break;
    }
  }

  delay(1000);
  taskComplete = LOW;
  
}
