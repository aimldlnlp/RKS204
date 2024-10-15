# Line Following Robot with Intersection Handling

**Course:** RKS204: Robotics Experiment 1

This project implements a line-following robot using multiple IR sensors for detecting the path and intersections. The robot is controlled by two motors, enabling it to move along a predefined line, adjusting its direction based on real-time sensor feedback. The robot can also handle intersections, making decisions to move left or right when encountering them.

## Features:

- **IR Sensor-Based Line Following:**  
  Utilizes 6 IR sensors to detect the black line on a white surface. Sensors provide real-time feedback to ensure accurate following of the line.
  
- **Intersection Handling:**  
  The robot is capable of recognizing intersections where multiple sensors detect black simultaneously. Based on the sensor readings, it can decide to turn left or right and continue following the path after crossing the intersection.
  
- **Motor Control:**  
  The robot is driven by two DC motors, where speed and direction can be independently controlled for each motor. This allows for smooth movement and accurate turns.
  
- **Proportional Motor Speed Adjustment:**  
  The robot adjusts motor speed based on sensor inputs to stay centered on the line. If the robot starts veering off to the left or right, the motors will adjust to correct the trajectory.

## Hardware Components:

- **IR Sensors:**  
  6 analog IR sensors (A0 - A6) are used to detect the presence of a black line or intersection. These sensors provide analog values that are used to determine the robot's position relative to the line.
  
- **Motors and Motor Driver:**  
  Two DC motors are controlled using a motor driver. The direction and speed of each motor can be set independently to enable smooth movement and sharp turns.

## Code Overview:

- **Sensor Initialization:**  
  The robot reads the values from the IR sensors and determines whether each sensor is detecting a black or white surface by comparing the values to a predefined threshold.
  
- **Motor Control:**  
  The motor control functions set the direction (forward, backward, stop) and speed for both motors. This allows the robot to perform various maneuvers like moving straight, turning, and stopping.
  
- **Intersection Detection and Handling:**  
  When all front sensors detect a black line, the robot recognizes an intersection. It then performs the appropriate turn (left or right) by adjusting motor direction and speed until it re-centers on the path.
