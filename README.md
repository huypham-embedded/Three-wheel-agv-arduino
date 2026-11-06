# Three-Wheel Differential-Drive AGV Prototype

**Personal Engineering Project | 2026 – Present**

## 1. Project Overview

This project focuses on developing a three-wheeled Autonomous Guided Vehicle (AGV) prototype using Arduino Uno.

The vehicle features a differential-drive configuration with two independently driven wheels and one passive support wheel.

The main objective is to develop fundamental knowledge of mobile robotics, embedded programming, DC motor control, and obstacle detection.

**Project Status:** In Progress

## 2. Hardware Components

| Component | Description |
|---|---|
| Microcontroller | Arduino Uno |
| Motor Driver | L298N Dual H-Bridge |
| DC Motors | 2 × TT Geared DC Motors (3–6V) |
| Distance Sensor | HC-SR04 Ultrasonic Sensor |
| Chassis | Three-wheel configuration |
| Power Supply | 4 × AA Battery Pack |

## 3. System Architecture

- Arduino Uno processes sensor data and generates motor control signals.
- L298N controls the direction and speed of the two DC motors.
- Two driven wheels provide forward, reverse, and rotational movement.
- One passive wheel supports the chassis.
- HC-SR04 measures the distance to obstacles in front of the vehicle.

## 4. Arduino Pin Configuration

| Device | Arduino Pin |
|---|---|
| ENA | D3 |
| IN1 | D5 |
| IN2 | D6 |
| IN3 | D9 |
| IN4 | D10 |
| ENB | D11 |
| HC-SR04 TRIG | D7 |
| HC-SR04 ECHO | D4 |

## 5. Implemented and Developing Features

- Forward and backward movement.
- Differential-drive rotational movement.
- PWM-based DC motor speed control.
- Ultrasonic distance measurement.
- Basic obstacle detection and avoidance logic.
- Hardware integration and troubleshooting.

Features are being tested and improved on the physical prototype.

## 6. Software and Technologies

- Arduino IDE
- Arduino C/C++
- PWM Motor Control
- Embedded Systems
- Ultrasonic Sensing
- Differential-Drive Robotics

## 7. Current Limitations

- No wheel encoders or closed-loop speed control.
- No PID-based motion control yet.
- Turning is currently based on timed motor operation.
- Ultrasonic sensing is limited to the forward direction.
- No localization, mapping, or autonomous path planning.

## 8. Future Development

1. Improve mechanical stability and load capacity.
2. Integrate wheel encoders.
3. Develop PID-based wheel speed control.
4. Study differential-drive kinematics and odometry.
5. Explore ROS 2 integration.
6. Develop autonomous navigation and obstacle avoidance.

## 9. Project Objectives

This prototype serves as a foundation for further research and development in mobile robotics, AGV/AMR systems, and autonomous vehicle technologies.

---

**Author:** Huy Pham  
**GitHub:** https://github.com/huypham-embedded
