#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int ldr5 = A4;
int val;
int dc1 = 2;
int dc2 = 3;
int threshold = 800;



void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("ok");

  tmrpcm.setVolume(3);
  tmrpcm.speakerPin = 9;

  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD failure");
    return;
  }
  if (SD.exists("buzzer.wav")) {
    Serial.println("buzzer file exists");
  }
}

void toot() {
  if(tmrpcm.isPlaying() == 1) {
    Serial.println("already bzzzt!");
  }
  else {
    tmrpcm.play("buzzer.wav");
    Serial.println("toot!!");
  }
}


void loop() {
  int a = digitalRead(dc1);
  if(a == HIGH) {
    Serial.println("dc1 high");
    val = analogRead(A0);
    if(val < threshold) {
      toot();
    }
    val = analogRead(A1);
    if(val < threshold) {
      toot();
    }
  }
  
  int b = digitalRead(dc2);
  if(b == HIGH) {
    Serial.println("dc2 high");
    val = analogRead(A2);
    if(val < threshold) {
      toot();
    }
    val = analogRead(A3);
    if(val < threshold) {
      toot();
    }
    val = analogRead(A4);
    if(val < threshold) {
      toot();
    }
    }
 }
