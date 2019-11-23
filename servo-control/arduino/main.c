#include <Servo.h>
#define SERVO_PIN 9
#define INITIAL_SERVO 90
int inputRotate = 0;

// ServoMoterは0から180までの角度しか表現できない？
Servo servo;//Servoオブジェクトの宣言

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(INITIAL_SERVO); //初期化角度
}

void loop() {
  inputRotate = Serial.read();
  servo.write(inputRotate);
  delay(100);
}
