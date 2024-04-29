// Motor  connections
int enA = 13;
int in1 = 52;
int in2 = 53;
// out1 -> purple connection on motor
// out2 -> orange connection on motor
// Switching the outputs will cause the car to move in reverse

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(enA, LOW);
}

void loop() {
  driveForward();
  delay(1000);
  //speedControl();
  //delay(1000);
}

// This function lets you control spinning direction of motors
void driveForward() {
  // Set motor to half speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 254);

  // Drive forwards for 3 seconds
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000);
  
  // Now change motor directions for 2 seconds
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, HIGH);
  //delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    delay(20);
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    delay(20);
  }
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
