// Define IR sensor pins
#define IR1 A5
#define IR2 A2
#define IR3 A7
#define IR4 A4
#define IR5 A3
#define IR6 A6
#define IR7 A1
#define IR8 A0

// Define motor control pins
#define EN_A 3
#define IN1 2
#define IN2 4
#define EN_B 5
#define IN3 7
#define IN4 6

// Initialize sensor values
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int sensor5 = 0;
int sensor6 = 0;
int sensor7 = 0;
int sensor8 = 0;

// Define threshold values
const int blackThreshold = 800;
const int whiteThreshold = 800;

// Define time delays
const int leapTime = 13;

// Function declarations
void readSensors_pakdhe();
void displaySensorValues_pakdhe(int s1, int s2, int s3, int s4, int s5, int s6, int s7);
void controlMotorSpeed_pakdhe(int leftSpeed, int rightSpeed);
void setMotorDirection_pakdhe(int leftDir, int rightDir);
void initializeSensors_pakdhe();
void initializeMotors_pakdhe();

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize sensors and motors
  initializeSensors_pakdhe();
  initializeMotors_pakdhe();

  // Give a delay for initial setup
  delay(500);
}

void loop() {
  // Read the sensor values
  readSensors_pakdhe();

  // Main logic for line following based on sensor readings
  if (sensor4 > blackThreshold && sensor5 > blackThreshold) {
    setMotorDirection_pakdhe(1, 1);
    controlMotorSpeed_pakdhe(255, 255);
  } else if (sensor4 < whiteThreshold && sensor5 > blackThreshold) {
    setMotorDirection_pakdhe(1, 1);
    controlMotorSpeed_pakdhe(255, 170);
  } else if (sensor4 > blackThreshold && sensor5 < whiteThreshold) {
    setMotorDirection_pakdhe(1, 1);
    controlMotorSpeed_pakdhe(170, 255);
  }

  // Handle intersection scenarios
  if (sensor1 > blackThreshold && sensor2 > blackThreshold && sensor6 < whiteThreshold) {
    setMotorDirection_pakdhe(1, 1);
    controlMotorSpeed_pakdhe(71, 71);
    // delay(9);
    while (true) {
      readSensors_pakdhe();
      setMotorDirection_pakdhe(2, 1);
      controlMotorSpeed_pakdhe(230, 255);
      if (sensor4 > blackThreshold || sensor5 > blackThreshold) {
        break;
      }
    }
  }
  if (sensor1 < whiteThreshold && sensor2 < whiteThreshold && sensor6 > blackThreshold) {
    setMotorDirection_pakdhe(1, 1);
    controlMotorSpeed_pakdhe(71, 71);
    // delay(9);
    while (true) {
      readSensors_pakdhe();
      setMotorDirection_pakdhe(1, 2);
      controlMotorSpeed_pakdhe(255, 230);
      if (sensor4 > blackThreshold || sensor5 > blackThreshold) {
        break;
      }
    }
  }
}

// Initialize IR sensor pins
void initializeSensors_pakdhe() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);
}

// Display sensor values on Serial Monitor
void displaySensorValues_pakdhe(int s1, int s2, int s3, int s4, int s5, int s6, int s7) {
  Serial.print("s1 = ");
  Serial.print(s1);
  Serial.print(", s2 = ");
  Serial.print(s2);
  Serial.print(", s3 = ");
  Serial.print(s3);
  Serial.print(", s4 = ");
  Serial.print(s4);
  Serial.print(", s5 = ");
  Serial.print(s5);
  Serial.print(", s6 = ");
  Serial.print(s6);
  Serial.print(", s7 = ");
  Serial.println(s7);
  // Serial.print(", s8 = ");
  // Serial.println(s8);
  delay(200);
}

// Read sensor values
void readSensors_pakdhe() {
  delay(leapTime);
  sensor1 = analogRead(IR1);
  sensor2 = analogRead(IR2);
  sensor3 = analogRead(IR3);
  sensor4 = analogRead(IR4);
  sensor5 = analogRead(IR5);
  sensor6 = analogRead(IR6);
  sensor7 = analogRead(IR7);
  // sensor8 = analogRead(IR8);

  // Uncomment the line below to display sensor values
  // displaySensorValues_pakdhe(sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7);
}

// Control the speed of the motors
void controlMotorSpeed_pakdhe(int leftSpeed, int rightSpeed) {
  analogWrite(EN_A, leftSpeed);
  analogWrite(EN_B, rightSpeed);
}

// Set the direction of the motors
void setMotorDirection_pakdhe(int leftDir, int rightDir) {
  if (leftDir == 1) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (leftDir == 2) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else if (leftDir == 3) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  if (rightDir == 1) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (rightDir == 2) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (rightDir == 3) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

// Initialize motor control pins
void initializeMotors_pakdhe() {
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
