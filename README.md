# ESC Motor Control

## Overview
This repository contains an ESP32-based implementation for controlling brushless motors using Electronic Speed Controllers (ESCs). The code provides motor control, ESC calibration, and testing functionalities.

## Features
- Control up to four brushless motors
- ESC calibration for optimal performance
- Adjustable speed control using PWM signals
- Serial debugging for real-time feedback

## Hardware Requirements
- ESP32 Board
- 4x Brushless Motors
- 4x ESCs
- Power Supply (Battery or External Source)
- Connection Wires

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ESC-Motor-Control.git
   ```
2. Open the project in the Arduino IDE.
3. Connect the components as per the wiring diagram.
4. Upload the code to your ESP32 board.

## Usage
### ESC Calibration
1. Power on the system.
2. The motors will enter the calibration process.
3. Wait for the process to complete before proceeding.

### Motor Control
- The system will run the motors at different speeds in sequence.
- Modify the `setSpeed()` function to adjust motor behavior.

## Code Explanation
- **Motor Class:** Handles individual motor control.
- **calibrateESCs():** Ensures proper ESC throttle range.
- **pulseMotors():** Sends speed pulses to all motors.
- **setup():** Initializes the ESCs and runs a test sequence.
- **loop():** Tests motor functionality through different speed levels.

## Contributing
Feel free to fork the repository and submit pull requests for improvements.
