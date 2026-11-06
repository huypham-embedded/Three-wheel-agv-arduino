
// =================================================
//       THREE-WHEEL AGV
//       ARDUINO UNO + L298N + HC-SR04
// =================================================
//
// Functions:
// 1. Automatic forward movement.
// 2. Distance measurement using an ultrasonic sensor.
// 3. When an obstacle is detected within 25 cm:
//    - Stop the vehicle.
//    - Move backward.
//    - Turn right.
// 4. Resume forward movement.
//
// Both motors use the same PWM speed value.
// =================================================


// ================================================
// 1. L298N MOTOR DRIVER PIN CONFIGURATION
// ================================================

// Left motor - Channel A
#define ENA 3
#define IN1 5
#define IN2 6

// Right motor - Channel B
#define ENB 11
#define IN3 9
#define IN4 10


// ================================================
// 2. HC-SR04 ULTRASONIC SENSOR PIN CONFIGURATION
// ================================================

#define TRIG 7
#define ECHO 4


// ================================================
// 3. AGV CONFIGURATION
// ================================================

// Motor speed settings
int forwardSpeed = 180;
int backwardSpeed = 160;
int turningSpeed = 180;

// Obstacle detection threshold (cm)
int obstacleThreshold = 25;

// Movement duration (milliseconds)
int backwardDuration = 350;
int turningDuration = 400;


// ================================================
// 4. SETUP
// ================================================

void setup() {

  // Configure left motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Configure right motor pins
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configure ultrasonic sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Initialize Serial Monitor
  Serial.begin(9600);

  // Stop the vehicle at startup
  stopMotors();

  Serial.println("AGV SYSTEM INITIALIZED!");

  delay(1000);
}


// ================================================
// 5. DISTANCE MEASUREMENT FUNCTION
// ================================================

float measureDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Measure the ultrasonic echo duration
  long duration = pulseIn(ECHO, HIGH, 25000UL);

  // If no echo is received,
  // assume there is no obstacle within the detection range
  if (duration == 0) {
    return 400;
  }

  // Calculate distance in centimeters
  float distance = duration * 0.0343 / 2;

  return distance;
}


// ================================================
// 6. FORWARD MOVEMENT FUNCTION
// ================================================

void moveForward() {

  // Set both motors to forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Apply the same PWM speed to both motors
  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);

}


// ================================================
// 7. BACKWARD MOVEMENT FUNCTION
// ================================================

void moveBackward() {

  // Set both motors to backward direction
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Apply the same PWM speed to both motors
  analogWrite(ENA, backwardSpeed);
  analogWrite(ENB, backwardSpeed);

}


// ================================================
// 8. TURN RIGHT FUNCTION
// ================================================

void turnRight() {

  // Left motor moves forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor moves backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, turningSpeed);
  analogWrite(ENB, turningSpeed);

}


// ================================================
// 9. TURN LEFT FUNCTION
// ================================================

void turnLeft() {

  // Left motor moves backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor moves forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, turningSpeed);
  analogWrite(ENB, turningSpeed);

}


// ================================================
// 10. STOP FUNCTION
// ================================================

void stopMotors() {

  // Stop both motors
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}


// ================================================
// 11. OBSTACLE AVOIDANCE FUNCTION
// ================================================

void avoidObstacle() {

  Serial.println("OBSTACLE DETECTED!");

  // Step 1: Stop the vehicle
  stopMotors();
  delay(200);

  // Step 2: Move backward
  Serial.println("MOVING BACKWARD...");

  moveBackward();
  delay(backwardDuration);

  // Step 3: Stop the vehicle
  stopMotors();
  delay(200);

  // Step 4: Turn right
  Serial.println("TURNING RIGHT...");

  turnRight();
  delay(turningDuration);

  // Step 5: Stop after turning
  stopMotors();
  delay(200);

}


// ================================================
// 12. MAIN PROGRAM
// ================================================

void loop() {

  // Measure the distance to the obstacle
  float distance = measureDistance();

  Serial.print("Obstacle Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check whether the path is clear
  if (distance > obstacleThreshold) {

    // No obstacle detected within the threshold
    Serial.println("AGV MOVING FORWARD");

    moveForward();

  }

  else {

    // An obstacle has been detected
    avoidObstacle();

  }

  delay(50);

}
