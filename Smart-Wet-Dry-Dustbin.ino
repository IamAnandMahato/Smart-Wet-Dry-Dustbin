
#include <Servo.h>

// ===================================
// SMART WET AND DRY DUSTBIN
// Arduino Uno + HC-SR04 + FC-28 + SG90
// ===================================

// PIN CONFIGURATION
#define TRIG_PIN 7
#define ECHO_PIN 8
#define MOISTURE_PIN A0
#define SERVO_PIN 6

// OBJECT DETECTION
const int DETECTION_DISTANCE = 20;
const int RESET_DISTANCE = 30;

// FC-28 CALIBRATION
// Change after checking your sensor readings.
int MOISTURE_THRESHOLD = 500;

// FC-28 usually gives lower readings when wet.
// Change to false if your readings behave oppositely.
const bool WET_READING_IS_LOWER = true;

// SERVO POSITIONS
const int CENTER_ANGLE = 90;
const int WET_ANGLE = 35;
const int DRY_ANGLE = 145;

// TIMING
const unsigned long SENSOR_WAIT = 1000;
const unsigned long SORTING_TIME = 2000;
const unsigned long COOLDOWN_TIME = 1000;

Servo sortingServo;

bool processingWaste = false;

// ===================================
// ULTRASONIC DISTANCE
// ===================================

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
    pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return 999;
  }

  return duration * 0.0343 / 2;
}

// ===================================
// FC-28 MOISTURE READING
// ===================================

int getMoistureValue() {

  long total = 0;

  for (int i = 0; i < 10; i++) {

    total += analogRead(MOISTURE_PIN);

    delay(50);
  }

  return total / 10;
}

// ===================================
// WASTE SORTING
// ===================================

void sortWaste() {

  Serial.println();
  Serial.println("Waste detected!");

  Serial.println("Checking moisture...");

  delay(SENSOR_WAIT);

  int moistureValue = getMoistureValue();

  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  bool isWet;

  if (WET_READING_IS_LOWER) {
    isWet = moistureValue < MOISTURE_THRESHOLD;
  }
  else {
    isWet = moistureValue > MOISTURE_THRESHOLD;
  }

  if (isWet) {

    Serial.println("WET WASTE DETECTED");

    sortingServo.write(WET_ANGLE);

  }
  else {

    Serial.println("DRY WASTE DETECTED");

    sortingServo.write(DRY_ANGLE);

  }

  Serial.println("Sorting waste...");

  delay(SORTING_TIME);

  sortingServo.write(CENTER_ANGLE);

  Serial.println("Sorting completed!");

  delay(COOLDOWN_TIME);
}

// ===================================
// SETUP
// ===================================

void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(MOISTURE_PIN, INPUT);

  sortingServo.attach(SERVO_PIN);

  sortingServo.write(CENTER_ANGLE);

  delay(500);

  Serial.println("==============================");
  Serial.println("SMART WET AND DRY DUSTBIN");
  Serial.println("==============================");

  Serial.println("System Ready!");
}

// ===================================
// MAIN LOOP
// ===================================

void loop() {

  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= DETECTION_DISTANCE &&
      distance > 0 &&
      !processingWaste) {

    processingWaste = true;

    sortWaste();

    Serial.println("Remove the waste...");

    // Wait until object moves away
    while (getDistance() <= RESET_DISTANCE) {
      delay(200);
    }

    processingWaste = false;

    Serial.println("Ready for next waste!");
  }

  delay(200);
}
