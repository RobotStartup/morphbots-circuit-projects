#include <Servo.h>

Servo servo1;


int trigPin;
int echoPin;
const int arrayLen = 10;
float distanceArray[arrayLen];
float avgDist;
int servoAngle; 
int closestAngle; 
float closestDistance; 
boolean shouldSurvey;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  Serial.begin(9600);
  trigPin = 13;
  echoPin = 10;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  closestAngle = 0;
  closestDistance = 400;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print( needAverage(distanceArray, arrayLen, trigPin, echoPin));

  if (shouldSurvey == true) {
    survey();
  }else{ 
    check();
    } 
   }

float getDistance(int aTrigPin, int anEchoPin) {
  float distance;
  float duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(anEchoPin, HIGH);
  distance = (duration / 2) * 0.0344;
    delay(5);
  return distance;
}


float avgValue(float * anArray, int anArrayLen) {
  // make sure sum starts at 0
  float sum = 0;
  for (int i = 0; i < anArrayLen; i++) {
    sum += anArray[i];
     }
  float avg = sum / anArrayLen;
  return avg;
}


float needAverage (float *a, float l, int trig, int echo) {
  float dis = getDistance(trigPin, echoPin);

  for (int i = 0; i < l; i++) {
    a[i] = dis;
  }
  float thisAvg = avgValue(distanceArray, arrayLen);
  delay(500);
  return (thisAvg);
}



float survey() {
  servo1.write(servoAngle);
  float howClose = needAverage(distanceArray, arrayLen, trigPin, echoPin);
  if (howClose < closestDistance) {
    closestDistance= howClose;
    closestAngle = servoAngle;
  }
    delay(500);
    servoAngle += 30; 
   if (servoAngle >= 175) {
      Serial.print("here");
      servo1.write(closestAngle);
      servoAngle = 0;
      shouldSurvey = false;
    }
  }

  void check(){
    float c= needAverage(distanceArray, arrayLen, trigPin, echoPin);
    if(abs(c-closestDistance)>20){
      shouldSurvey=true;
      closestDistance=400;
    }
  }
