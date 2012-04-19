/*
  Flexible Circuit Sequencer Anystream 3000
  Martin Murer, Eckhard Riedenklau, Jens A. Ewald TEI 2012
*/

const int testPin  = A0;
const int audioPin = 11;
const int startPin = 2;
const int endPin   = startPin+8;

int stepspeed = 125;
int threshold = 255;

const int maxFreq = 1047;
const int minFreq = 131;

void setup(){
  for(int i = startPin; i < endPin; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop(){
  for(int i = startPin; i < endPin; i++){
    digitalWrite(i, HIGH);
    int value = analogRead(testPin);
    if(value >= threshold){
      tone(audioPin, map(value, threshold, 1023, minFreq, maxFreq),stepspeed);
      pinMode(i, OUTPUT); 
    } else {
      noTone(i);
      delay(stepspeed);
    }
    delay(stepspeed/2);
    digitalWrite(i, LOW);
  }
}

