                                    ENTERPRISE / CLOUD LAYER
┌────────────────────────────────────────────────────────────────────────────┐
│ Dashboard │ Fleet Management │ ERP │ MES │ Database │ MQTT │ OTA Update   │
└────────────────────────────────────────────────────────────────────────────┘
                                       ▲
                                       │
──────────────────────────────────────────────────────────────────────────────
                              APPLICATION LAYER
──────────────────────────────────────────────────────────────────────────────

Mission Manager
│
├── Task Planner
├── Workflow Engine
├── Mission Scheduler
└── Charging Manager

Navigation System
│
├── Localization
├── SLAM
├── Mapping
├── Global Planner
├── Local Planner
└── Obstacle Avoidance

Perception System
│
├── LiDAR Processing
├── Camera Vision
├── Human Detection
├── Pallet Detection
└── Sensor Fusion

Robot Management
│
├── Battery Management
├── Health Monitoring
├── Diagnostics
├── Logging
└── Safety Manager

Manual Operation
│
├── Remote Control
├── Maintenance Mode
└── Manual Override

                                       ▲
                                       │
──────────────────────────────────────────────────────────────────────────────
                           ROBOT MIDDLEWARE LAYER
──────────────────────────────────────────────────────────────────────────────

ROS 2 Communication

├── Topics
├── Services
├── Actions
├── Parameters
├── TF2
├── Lifecycle
├── DDS Communication
└── Component Management

                                       ▲
                                       │
──────────────────────────────────────────────────────────────────────────────
                          HARDWARE INTERFACE LAYER
──────────────────────────────────────────────────────────────────────────────

Device Drivers

├── Motor Driver Interface
├── Encoder Driver
├── LiDAR Driver
├── Camera Driver
├── IMU Driver
├── Ultrasonic Driver
├── Battery Driver
├── Lift Driver
├── Docking Driver
└── IO Driver

Hardware Communication

├── EtherCAT
├── CAN Bus
├── RS485 / Modbus
├── UART
├── USB
├── Ethernet
├── SPI
└── I2C

                                       ▲
                                       │
──────────────────────────────────────────────────────────────────────────────
                            FIRMWARE LAYER
──────────────────────────────────────────────────────────────────────────────

Motion Control

├── PID Controller
├── Differential Drive Controller
├── Velocity Controller
├── Position Controller
└── Odometry Calculation

Safety Control

├── Emergency Stop
├── Safety Monitoring
├── Watchdog
├── Collision Protection
└── Fault Detection

Actuator Control

├── Lift Controller
├── Battery Charging Controller
├── Power Distribution
└── IO Control

                                       ▲
                                       │
──────────────────────────────────────────────────────────────────────────────
                              HARDWARE LAYER
──────────────────────────────────────────────────────────────────────────────

Main Controller

├── NVIDIA Jetson
├── Intel / AMD Industrial PC
└── ARM SBC

Real-Time Controller

├── STM32
├── TI C2000
├── NXP
└── Safety PLC (Optional)

Actuators

├── Servo Motor
├── BLDC Motor
├── Servo Drive
├── Linear Actuator
└── Brake System

Sensors

├── LiDAR
├── Camera
├── IMU
├── Encoder
├── Ultrasonic
├── Limit Switch
└── Battery Sensor

Power System

├── LiFePO₄ Battery
├── BMS
├── Charging Dock
├── DC/DC Converter
└── Power Distribution
