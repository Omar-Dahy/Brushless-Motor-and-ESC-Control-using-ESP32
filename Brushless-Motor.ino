#include <Arduino.h>

/* Define ESC pins */
const int ESC1_PIN = 18;
const int ESC2_PIN = 19;
const int ESC3_PIN = 20;
const int ESC4_PIN = 21;

/* Motor class to control ESCs */
class Motor {
  private:
    int pin;
    
  public:
    /* Constructor to initialize motor pin */
    Motor(int motorPin) {
      pin = motorPin;
      pinMode(pin, OUTPUT);
    }
    
    /* Set motor speed with a constrained range (90-180) */
    void setSpeed(int speed) {
      speed = constrain(speed, 90, 180);
      int pulseWidth = map(speed, 90, 180, 1500, 2000); /* Adjusted range: 1.5-2ms */
      digitalWrite(pin, HIGH);
      delayMicroseconds(pulseWidth);
      digitalWrite(pin, LOW);
      delayMicroseconds(20000 - pulseWidth); /* 50Hz signal */
    }
};

/* Create motor objects */
Motor forwardMotor1(ESC1_PIN);
Motor forwardMotor2(ESC2_PIN);
Motor backwardMotor1(ESC3_PIN);
Motor backwardMotor2(ESC4_PIN);

/* Function to pulse all motors at a given speed for a number of pulses */
void pulseMotors(int speed, int pulses) {
  for (int i = 0; i < pulses; i++) {
    forwardMotor1.setSpeed(speed);
    forwardMotor2.setSpeed(speed);
    backwardMotor1.setSpeed(speed);
    backwardMotor2.setSpeed(speed);
  }
}

/* Function to calibrate ESCs */
void calibrateESCs() {
  delay(3000);
  Serial.println("Start The ESC TEST...");
  delay(3000);

  Serial.println("Set to max throttle for calibration...");
  for (int i = 0; i < 200; i++) {
    forwardMotor1.setSpeed(180);
    forwardMotor2.setSpeed(180);
    backwardMotor1.setSpeed(180);
    backwardMotor2.setSpeed(180);
  }
  delay(3000); /* Hold max for ESCs to register */
  
  Serial.println("Set to min throttle...");
  for (int i = 0; i < 200; i++) {
    forwardMotor1.setSpeed(90);
    forwardMotor2.setSpeed(90);
    backwardMotor1.setSpeed(90);
    backwardMotor2.setSpeed(90);
  }
  delay(3000);
  Serial.println("Calibration complete");
}

/* Setup function runs once at startup */
void setup() {
  Serial.begin(9600);
  calibrateESCs();

  Serial.println("ESCs Initializing...");
  pulseMotors(90, 100);
  delay(2000);
  
  pulseMotors(180, 100);
  Serial.println("Max throttle (180)");
  delay(2000);
  
  pulseMotors(90, 100);
  Serial.println("Idle/Stop (90)");
  delay(2000);
}

/* Main loop function to test motor speeds */
void loop() {
  Serial.println("Forward Motors Testing 120...");
  forwardMotor1.setSpeed(120);
  forwardMotor2.setSpeed(120);
  delay(4000);
  
  Serial.println("Stopping Forward Motors...");
  forwardMotor1.setSpeed(90);
  forwardMotor2.setSpeed(90);
  delay(4000);
  
  Serial.println("Backward Motors Testing 120...");
  backwardMotor1.setSpeed(120);
  backwardMotor2.setSpeed(120);
  delay(4000);
  
  Serial.println("Stopping Backward Motors...");
  backwardMotor1.setSpeed(90);
  backwardMotor2.setSpeed(90);
  delay(4000);
}
