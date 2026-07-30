# ROBOT SOFTWARE ARCHITECTURE

Layered Architecture for Commercial Robots

## OVERVIEW

Layered robot software architecture — from **Hardware** to **Enterprise/Cloud Layer**. Each layer has separate responsibilities and communicates through defined interfaces.

```
┌─────────────────────────────────────────────────────────────┐
│                   ENTERPRISE / CLOUD LAYER                  │
├─────────────────────────────────────────────────────────────┤
│  Dashboard  │  Fleet Mgmt  │  ERP  │  MES  │  Database      │
│  MQTT       │  OTA Update                                   │
└─────────────────────────────────────────────────────────────┘
                           ▲
                           │
┌─────────────────────────────────────────────────────────────┐
│                    APPLICATION LAYER                        │
├─────────────────────────────────────────────────────────────┤
│  Mission Manager  │  Navigation  │  Perception              │
│  Robot Management │  Manual Op                              │
└─────────────────────────────────────────────────────────────┘
                           ▲
                           │
┌─────────────────────────────────────────────────────────────┐
│                   ROBOT MIDDLEWARE LAYER                    │
├─────────────────────────────────────────────────────────────┤
│  ROS 2  │  DDS  │  TF2  │  Lifecycle  │  Component          │
└─────────────────────────────────────────────────────────────┘
                           ▲
                           │
┌─────────────────────────────────────────────────────────────┐
│                  HARDWARE INTERFACE LAYER                   │
├─────────────────────────────────────────────────────────────┤
│  Device Drivers  │  Comm (EtherCAT, CAN, UART, SPI, I2C)    │
└─────────────────────────────────────────────────────────────┘
                           ▲
                           │
┌─────────────────────────────────────────────────────────────┐
│                     FIRMWARE LAYER                          │
├─────────────────────────────────────────────────────────────┤
│  Motion Control  │  Safety  │  Actuator Control             │
└─────────────────────────────────────────────────────────────┘
          roboti                 ▲
                           │
┌─────────────────────────────────────────────────────────────┐
│                      HARDWARE LAYER                         │
├─────────────────────────────────────────────────────────────┤
│  Main Controller  │  RT Controller  │  Actuators  │  Sensors│
│  Power System                                               │
└─────────────────────────────────────────────────────────────┘
```

---

## LAYER 1 — HARDWARE LAYER

Physical robot components.

### Main Controller

- NVIDIA Jetson (Orin, Xavier, Nano)
- Intel / AMD Industrial PC
- ARM SBC (Raspberry Pi, ODROID)
- Embedded PC

### Real-Time Controller

- STM32 (F4, H7, G4)
- TI C2000 (Delfino, Piccolo)
- NXP (i.MX RT, LPC)
- Safety PLC (Optional)

### Actuators

- Servo Motor
- BLDC Motor
- Servo Drive
- Linear Actuator
- Brake System

### Sensors

- LiDAR (2D, 3D)
- Camera (RGB, Depth, Thermal)
- IMU (Accelerometer, Gyroscope, Magnetometer)
- Encoder (Rotary, Linear)
- Ultrasonic
- Limit Switch
- Battery Sensor

### Power System

- LiFePO₄ Battery
- BMS (Battery Management System)
- Charging Dock
- DC/DC Converter
- Power Distribution

---

## LAYER 2 — FIRMWARE LAYER

Real-time control & safety running on microcontrollers.

### Motion Control

- PID Controller
- Differential Drive Controller
- Velocity Controller
- Position Controller
- Odometry Calculation

### Safety Control

- Emergency Stop
- Safety Monitoring
- Watchdog
- Collision Protection
- Fault Detection

### Actuator Control

- Lift Controller
- Battery Charging Controller
- Power Distribution
- IO Control

---

## LAYER 3 — HARDWARE INTERFACE LAYER

Hardware abstraction — drivers and communication protocols.

### Device Drivers

- Motor Driver Interface
- Encoder Driver
- LiDAR Driver
- Camera Driver
- IMU Driver
- Ultrasonic Driver
- Battery Driver
- Lift Driver
- Docking Driver
- IO Driver

### Hardware Communication

- EtherCAT
- CAN Bus (CANopen, J1939)
- RS485 / Modbus
- UART
- USB
- Ethernet
- SPI
- I2C

---

## LAYER 4 — ROBOT MIDDLEWARE LAYER

Communication framework and orchestration between software components.

### ROS 2 Communication

- Topics (Publish / Subscribe)
- Services (Request / Response)
- Actions (Goal / Result / Feedback)
- Parameters
- TF2 (Transform Tree)
- Lifecycle (Managed Nodes)
- DDS Communication
- Component Management (Node Composition)

---

## LAYER 5 — APPLICATION LAYER

Application logic and robot intelligence.

### Mission Manager

- Task Planner
- Workflow Engine
- Mission Scheduler
- Charging Manager

### Navigation System

- Localization (AMCL, EKF)
- SLAM (slam_toolbox, Cartographer)
- Mapping (Occupancy Grid, Costmap)
- Global Planner (Nav2, A*)
- Local Planner (DWB, TEB, MPC)
- Obstacle Avoidance

### Perception System

- LiDAR Processing (Point Cloud, PCL)
- Camera Vision (OpenCV, Deep Learning)
- Human Detection
- Pallet Detection
- Sensor Fusion

### Robot Management

- Battery Management
- Health Monitoring
- Diagnostics
- Logging
- Safety Manager

### Manual Operation

- Remote Control (Joystick, Keyboard)
- Maintenance Mode
- Manual Override

---

## LAYER 6 — ENTERPRISE / CLOUD LAYER

Fleet management, monitoring, and enterprise integration.

### Components

- Dashboard (Real-time Monitoring)
- Fleet Management (Multi-robot)
- ERP / MES Integration
- Database (Timeseries, SQL)
- MQTT Broker (Cloud Communication)
- OTA Update (RAUC, Mender, SWUpdate)

### Communication

- REST API
- WebSocket
- MQTT / OPC-UA
- Database Synchronization

---

## DATA FLOW

### Sensor Data (Bottom → Top)

```
Hardware Layer
    ↓ (Raw Sensor Data)
Firmware Layer
    ↓ (Filtered/Processed Data via UART/CAN)
Hardware Interface Layer
    ↓ (ROS 2 Drivers → Topics)
Robot Middleware (ROS 2)
    ↓ (Sensor Fusion, TF, Localization)
Application Layer
    ↓ (Mission Status, Telemetry, Diagnostics)
Enterprise / Cloud Layer
```

### Command / Control (Top → Bottom)

```
Enterprise / Cloud Layer
    ↓ (Mission Command, Goal, OTA Update)
Application Layer
    ↓ (Velocity Command, Waypoint, Action Goal)
Robot Middleware (ROS 2)
    ↓ (Cmd via Topics/Actions)
Hardware Interface Layer
    ↓ (Motor Command, Setpoint via CAN/UART)
Firmware Layer
    ↓ (PWM, Current Control)
Hardware Layer
```

---

## NOTES & PERSONAL REFLECTION

> *Architecture notes, design decisions, blockers, etc.*

```
Date: YYYY-MM-DD
Notes:
- ...
- ...
```

---

*Last Updated: 2026-07-26*
*Version: 2.0 (Restructured for readability)*
