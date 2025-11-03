// Black wire to linear actuator is closer to middle, while red is on the outside
// On 262, D5 == White Wire, D6 == Red Wire, Green wire is 3.3V

const int downPin = 5;  // D5 == White Wire
const int upPin = 6;    // D6 == Red Wire
const int relayPin = 7;
const int pwmPin = 9;
const int dirPin = 8;

bool systemEnabled = false;

void setup() {
  pinMode(upPin, INPUT_PULLDOWN);
  pinMode(downPin, INPUT_PULLDOWN);

  pinMode(relayPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(relayPin, HIGH);  // CH2 | Backup Camera
  analogWrite(pwmPin, 0);
}

void loop() {
  bool isUp = digitalRead(upPin) == HIGH;
  bool isDown = digitalRead(downPin) == HIGH;

  // ---- STARTUP LOCK ----
  if (!systemEnabled) {
    if (isDown) {
      systemEnabled = true;
      delay(200);
    } else {
      delay(100);
      return;
    }
  }

  // ---- NORMAL OPERATION ----
  if (isUp) {
    digitalWrite(dirPin, LOW);
    analogWrite(pwmPin, 255);
    digitalWrite(relayPin, LOW);
  } else if (isDown) {
    digitalWrite(dirPin, HIGH);
    analogWrite(pwmPin, 255);
    digitalWrite(relayPin, HIGH);
  } else {
    analogWrite(pwmPin, 0);
  }

  delay(100);
}
