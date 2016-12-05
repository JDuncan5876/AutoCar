#define PWM_PIN 5
#define FORWARD_PIN 9
#define BACKWARD_PIN 7
#define LEFT_PIN 11
#define RIGHT_PIN 13
#define FRONT_SENSOR A0
#define LEFT_SENSOR A1
#define RIGHT_SENSOR A2

int front = 0;
int left = 0;
int right = 0;

void setup() {
  pinMode(FORWARD_PIN, OUTPUT);
  digitalWrite(FORWARD_PIN, HIGH);
  pinMode(BACKWARD_PIN, OUTPUT);
  digitalWrite(BACKWARD_PIN, LOW);
  pinMode(LEFT_PIN, OUTPUT);
  digitalWrite(LEFT_PIN, LOW);
  pinMode(RIGHT_PIN, OUTPUT);
  digitalWrite(RIGHT_PIN, LOW);
  pinMode(FRONT_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 120);
}

void loop() {
  front = 0.75 * front + 0.25 * analogRead(FRONT_SENSOR);
  left = 0.75 * left + 0.25 * analogRead(LEFT_SENSOR);
  right = 0.75 * right + 0.25 * analogRead(RIGHT_SENSOR);
  if (front > 300 || left > 300 || right > 300) {
    if (front >= left && front >= right) {
      digitalWrite(FORWARD_PIN, LOW);
      delay(100);
      digitalWrite(BACKWARD_PIN, HIGH);
      delay(3000);
      digitalWrite(BACKWARD_PIN, LOW);
      delay(100);
      digitalWrite(FORWARD_PIN, HIGH);
    }
    if (left <= right) {
      digitalWrite(LEFT_PIN, HIGH);
      delay(1500);
      digitalWrite(LEFT_PIN, LOW);
    } else {
      digitalWrite(RIGHT_PIN, HIGH);
      delay(1500);
      digitalWrite(RIGHT_PIN, LOW);
    }
  }
}

