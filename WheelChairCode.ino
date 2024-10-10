#define IN1 12
#define IN2 14
#define ENA 13
#define IN3 27
#define IN4 26
#define ENB 25
#define X_PIN 34
#define Y_PIN 35

#define THRESHOLD_FORWARD 1350
#define THRESHOLD_BACKWARD 1000
#define THRESHOLD_LEFT 1050
#define THRESHOLD_RIGHT 1250

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  int xVal = analogRead(X_PIN);
  int yVal = analogRead(Y_PIN);
  
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" Y: ");
  Serial.println(yVal);
  
  if (yVal > THRESHOLD_FORWARD) {
    moveForward();
  } else if (yVal < THRESHOLD_BACKWARD) {
    moveBackward();
  } else if (xVal < THRESHOLD_LEFT) {
    turnLeft();
  } else if (xVal > THRESHOLD_RIGHT) {
    turnRight();
  } else {
    stopMotors();
  }
  
  delay(100);
}

void moveForward() {
  Serial.println("forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);  // Full speed
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);  // Full speed
}

void moveBackward() {
  Serial.println("backward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);  // Full speed
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);  // Full speed
}

void turnLeft() {
  Serial.println("left");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);  // Stop motor 1
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);  // Full speed
}

void turnRight() {
  Serial.println("right");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);  // Full speed
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);  // Stop motor 2
}

void stopMotors() {
  Serial.println("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
