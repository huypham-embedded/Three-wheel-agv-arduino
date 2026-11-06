# Three-Wheel Differential-Drive AGV Prototype

**Personal Engineering Project | 2026 – Present**

## 1. Project Overview

This project involves the design, assembly, and programming of a three-wheeled Autonomous Guided Vehicle (AGV) prototype using an Arduino Uno.

The vehicle uses a differential-drive configuration consisting of two independently driven wheels and one passive support wheel.

The project aims to explore fundamental concepts in mobile robotics, embedded systems, DC motor control, and ultrasonic-based obstacle detection.

**Project Status:** Prototype Successfully Assembled and Operational.

## 2. Hardware Components

| Component | Description | Quantity |
|---|---|---:|
| Microcontroller | Arduino Uno (ATmega328P) | 1 |
| Motor Driver | L298N Dual H-Bridge | 1 |
| DC Motors | TT Geared DC Motors (3–6V) | 2 |
| Distance Sensor | HC-SR04 Ultrasonic Sensor | 1 |
| Chassis | Three-wheel configuration | 1 |
| Drive Wheels | Motor-driven wheels | 2 |
| Passive Wheel | Support / Caster Wheel | 1 |
| Power Supply | 4-cell AA Battery Pack | 1 |

## 3. System Architecture

The AGV consists of three main subsystems:

**Control System**
- Arduino Uno acts as the main controller.
- Processes sensor signals and generates motor control commands.

**Drive System**
- L298N controls the direction and speed of two DC geared motors.
- Two independently driven wheels enable forward, backward, and rotational movements.
- One passive wheel provides additional mechanical support.

**Sensing System**
- HC-SR04 ultrasonic sensor measures the distance to obstacles.
- Distance measurements are used for basic obstacle detection and avoidance.

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

## 5. Implemented Features

The following functions have been implemented in the prototype:

- Forward and backward movement.
- Differential-drive rotational movement.
- PWM-based DC motor speed control.
- Ultrasonic distance measurement.
- Basic obstacle detection.
- Basic obstacle avoidance using stop, reverse, and turning movements.
- Hardware integration and motor control testing.

## 6. Software and Technologies

- Arduino IDE
- Arduino C/C++
- Embedded Systems
- PWM Motor Control
- DC Motor Control
- HC-SR04 Ultrasonic Sensing
- Differential-Drive Robotics

## 7. Current Limitations

- No wheel encoders or closed-loop speed control.
- No PID-based motor speed control.
- Turning angles are currently controlled using timed motor operation.
- Ultrasonic sensing is limited to the forward direction.
- No localization, mapping, or autonomous path planning.
- Obstacle avoidance reliability requires further systematic testing.

## 8. Future Development

1. Improve mechanical stability and load capacity.
2. Integrate wheel encoders for speed measurement.
3. Develop PID-based wheel speed control.
4. Study differential-drive kinematics and odometry.
5. Explore MATLAB/Simulink simulation.
6. Explore ROS 2 integration.
7. Develop more advanced autonomous navigation and obstacle avoidance.

## 9. Project Objectives

This prototype provides a practical foundation for further research and development in mobile robotics, AGV/AMR systems, embedded control, and autonomous vehicle technologies.

The project will be progressively improved through mathematical modeling, simulation, hardware experiments, and performance evaluation.

## 10. AGV Demonstration Video

Watch the three-wheel AGV prototype in operation:

[Watch AGV Demonstration on YouTube](https://youtu.be/_m0BC94dcjY?si=p_J5lVcKwSrPkRpP)

---

**Author:** Huy Pham

**GitHub:** https://github.com/huypham-embedded

**Repository:** https://github.com/huypham-embedded/Three-wheel-agv-arduino
