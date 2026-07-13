# Smart Dustbin

A simple Arduino-based smart trash can project that opens automatically when motion is detected and indicates when the bin is full.

## Features
- Detects motion near the bin using an ultrasonic sensor
- Opens the lid with a servo motor
- Shows fill level with LEDs
- Prints status information over the serial monitor

## Hardware
- Arduino board
- HC-SR04 ultrasonic sensors
- Servo motor
- LED indicators
- Jumper wires and breadboard

## Files
- [PoubelleIntelligente.ino](PoubelleIntelligente.ino) - main Arduino sketch

## How it works
1. The main ultrasonic sensor detects a nearby hand or object.
2. The servo motor rotates to open the lid for a few seconds.
3. The level sensor checks whether the bin is nearly full.
4. A red LED lights up when the bin is full; otherwise the green LED stays on.

## Usage
1. Upload the sketch to your Arduino board.
2. Connect the sensors, servo, and LEDs as defined in the code.
3. Open the serial monitor to observe the detection and level status.
