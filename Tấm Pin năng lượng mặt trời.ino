#include <Servo.h>

const int leftTop_AO = A4;
const int rightTop_AO = A3;
const int leftBot_AO = A1;
const int rightBot_AO = A2;

const int servoHorizontal = 2;
const int servoVertical = 3;

Servo servoH;
Servo servoV;

int angleH = 90;
int angleV = 90;
int delayTime = 50;
int lightThreshold = 200;
int stepAngle = 2;

void setup() {
  Serial.begin(9600);

  servoH.attach(servoHorizontal);
  servoV.attach(servoVertical);

  servoH.write(angleH);
  servoV.write(angleV);

  Serial.println("=== Solar Tracker 2-Axis - Analog Mode ===");
  Serial.println("4 cảm biến: LeftTop, RightTop, LeftBot, RightBot");
  Serial.println("Giá trị analog: 0-1023 (càng sáng càng cao)");
  delay(1000);
}

void loop() {
  int A1 = analogRead(leftBot_AO);
  int A2 = analogRead(rightBot_AO);
  int A3 = analogRead(rightTop_AO);
  int A4 = analogRead(leftTop_AO);

  Serial.print("A1:"); Serial.print(A1);
  Serial.print(" A2:"); Serial.print(A2);
  Serial.print(" A3:"); Serial.print(A3);
  Serial.print(" A4:"); Serial.print(A4);
  Serial.print(" | H:"); Serial.print(angleH);
  Serial.print("° V:"); Serial.print(angleV);
  Serial.println("°");

  if (A1 > lightThreshold && A2 > lightThreshold && A3 > lightThreshold && A4 > lightThreshold) {
    Serial.println("  -> Tất cả > 200, ĐỨNG YÊN");
    delay(delayTime);
    return;
  }

  if (A1 > A3 && A1 > A4 && A2 > A3 && A2 > A4) {
    angleV = constrain(angleV + stepAngle, 0, 180);
    servoV.write(angleV);
    Serial.println("  -> A1,A2 sáng nhất -> Servo dọc ++");
  } else if (A3 > A1 && A3 > A2 && A4 > A1 && A4 > A2) {
    angleV = constrain(angleV - stepAngle, 0, 180);
    servoV.write(angleV);
    Serial.println("  -> A3,A4 sáng nhất -> Servo dọc --");
  } else if (A1 > A2 && A1 > A4 && A3 > A2 && A3 > A4) {
    angleH = constrain(angleH + stepAngle, 0, 180);
    servoH.write(angleH);
    Serial.println("  -> A1,A3 sáng nhất -> Servo ngang ++");
  } else if (A4 > A1 && A4 > A3 && A2 > A1 && A2 > A3) {
    angleH = constrain(angleH + stepAngle, 0, 180);
    servoH.write(angleH);
    Serial.println("  -> A4,A2 sáng nhất -> Servo ngang ++");
  }

  delay(delayTime);
}
