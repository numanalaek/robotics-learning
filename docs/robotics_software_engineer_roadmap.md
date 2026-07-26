# ROADMAP ROBOTICS SOFTWARE ENGINEER
=========================================

## OVERVIEW
===========
Roadmap terstruktur untuk menjadi **Robotics Software Engineer** yang mampu membangun robot komersial dari nol hingga produksi.

┌─────────────────────────────────────────────────────────────────┐
│                     ROBOTICS SOFTWARE ENGINEER                  │
├──────────────┬──────────────┬──────────────────────────────────┤
│  Modern C++  │ Modern Python │   Software Engineering         │
│  (Roadmap 1) │  (Roadmap 2)  │      (Roadmap 3)                │
└──────┬───────┴───────┬───────┴──────────────┬─────────────────┘
       │               │                      │
       └───────────────┴──────────────────────┘
                           │
                           ▼
                  ┌─────────────────┐
                  │  Robotics Core  │  ◄── Core Fundamental (Roadmap 4)
                  └────────┬────────┘
                           │
                           ▼
                  ┌─────────────────┐
                  │  ROS2 Professional │ ◄── Framework (Roadmap 5)
                  └────────┬────────┘
                           │
                           ▼
                  ┌─────────────────┐
                  │ Production      │  ◄── Production Ready (Roadmap 6)
                  │   Robotics      │
                  └─────────────────┘

---

## ROADMAP 1: MODERN C++
=========================
**Target:** Menjadi C++ Engineer yang mampu membangun software robot berperforma tinggi.

### TOPICS
- Modern C++17/20
- STL (Standard Template Library)
- Memory Management (manual & smart pointers)
- Smart Pointers (unique_ptr, shared_ptr, weak_ptr)
- Concurrency & Multithreading
- CMake & Build Systems
- Design Patterns (Singleton, Factory, Observer, Strategy, dll)
- Debugging (GDB, Valgrind, AddressSanitizer)
- Performance Optimization (Profiling, Cache Optimization, SIMD)

### OUTPUT TARGET
- [ ] Mampu membuat library C++ reusable
- [ ] Mampu membaca & memahami project C++ besar (ROS2, MoveIt, dll)
- [ ] Siap menggunakan **rclcpp** (ROS2 C++ client library)

---

## ROADMAP 2: MODERN PYTHON
===========================
**Target:** Menjadi Python Engineer yang mampu membangun software robot modular & maintainable.

### TOPICS
- Modern Python (3.10+): Type Hints, Dataclasses, Pattern Matching
- OOP & Clean Architecture
- Package Management (pip, poetry, uv)
- Virtual Environment (venv, conda, pixi)
- Testing (pytest, unittest, mock)
- AsyncIO & Concurrency
- Clean Architecture (Layered, Hexagonal)
- Linting & Formatting (ruff, black, mypy)

### OUTPUT TARGET
- [ ] Mampu membuat package Python yang *publishable* ke PyPI
- [ ] Siap menggunakan **rclpy** (ROS2 Python client library)

---

## ROADMAP 3: SOFTWARE ENGINEERING (Language-Agnostic)
=======================================================
**Target:** Mampu mendesain software skala industri (Enterprise-grade).

### ARCHITECTURE PATTERNS
- Layered Architecture
- Clean Architecture
- Hexagonal Architecture (Ports & Adapters)
- Onion Architecture

### OOP & DESIGN PRINCIPLES
- SOLID Principles
- Composition over Inheritance
- Interface Design & Dependency Injection
- Design Patterns:
  - Creational: Factory, Builder, Singleton
  - Behavioral: Strategy, Observer, State, Command
  - Structural: Adapter, Decorator, Facade

### CLEAN CODE PRACTICES
- Naming Conventions
- Function & Class Design
- Error Handling & Result Types
- Logging & Observability

### TESTING STRATEGY
- Unit Testing (TDD)
- Integration Testing
- Regression Testing
- Property-Based Testing

### DEBUGGING & PERFORMANCE
- Debugging Techniques
- Logging & Structured Logging
- Profiling (CPU, Memory)
- Performance Analysis

### DEVOPS & TOOLING
- Git (Branching Strategy, Conventional Commits)
- Docker & Containerization
- CI/CD (GitHub Actions, GitLab CI)
- Static Analysis & Security Scanning

### OUTPUT TARGET
- [ ] Mampu mendesain arsitektur software enterprise-grade

---

## ROADMAP 4: ROBOTICS CORE (FUNDAMENTAL)
=========================================
> **Paling Penting** — Konsep di sini berlaku universal untuk C++ maupun Python.

### ROBOT ARCHITECTURE
- Robot Class Design
- Hardware Abstraction Layer (HAL)
- Driver Development
- Sensor Layer Abstraction
- Controller Layer
- Safety Layer (Emergency Stop, Watchdog)

### ROBOT MATHEMATICS
- Linear Algebra: Vector, Matrix, Eigen/NumPy
- Coordinate Frames & Transformations
- Quaternion & Rotation Representations
- Lie Groups & Lie Algebra (SE(3), SO(3))

### MOTION & KINEMATICS
- Forward Kinematics (FK)
- Inverse Kinematics (IK) — Analytical & Numerical
- Velocity Kinematics (Jacobian)
- Acceleration & Dynamics
- Trajectory Generation (Polynomial, Spline, S-curve)

### CONTROL THEORY
- PID Control & Tuning
- State Machine (Finite State Machine)
- Behavior Trees (BT)
- Model Predictive Control (MPC) — *Advanced*

### MOTION PLANNING & NAVIGATION
- Graph Search: A*, Dijkstra, D*
- Sampling-Based: RRT, RRT*, PRM
- Optimization-Based: CHOMP, TrajOpt
- Path Following: Pure Pursuit, Stanley, MPC
- SLAM (EKF, GraphSLAM, LiDAR SLAM, Visual SLAM)
- Localization (AMCL, Particle Filter)

### PERCEPTION
- Camera Models & Calibration (Intrinsic/Extrinsic)
- LiDAR Processing (Point Cloud, PCL)
- IMU & Sensor Fusion (EKF, UKF, Factor Graphs)
- Encoder & Odometry

### COMMUNICATION PROTOCOLS
- Serial: UART, SPI, I2C
- Fieldbus: CAN (CANopen, J1939), EtherCAT
- Network: TCP/IP, UDP, ROS2 DDS
- IoT/Industrial: MQTT, OPC-UA, Modbus

### EMBEDDED SYSTEMS
- MCU: STM32 (HAL/LL), ESP32 (FreeRTOS/ESP-IDF)
- ARM Cortex-M Architecture
- RTOS: FreeRTOS, Zephyr, ThreadX
- Embedded Linux: Yocto, Buildroot
- Bare Metal vs RTOS vs Linux

### OUTPUT TARGET
- [ ] Mampu mendesain arsitektur robot dari nol (Hardware → Software)

---

## ROADMAP 5: ROS 2 PROFESSIONAL
================================
> Semua ilmu sebelumnya berkumpul di sini.

### ROS 2 CORE CONCEPTS
- Workspace & Package Structure (ament_cmake, ament_python)
- Node Lifecycle & Composition
- Communication: Topic, Service, Action
- QoS Policies (Reliability, Durability, History, Deadline)
- DDS Implementation (Fast DDS, Cyclone DDS, Zenoh)
- Discovery & Domain Partitions

### EXECUTION MODEL
- Executors (Single-threaded, Multi-threaded, Static)
- Callback Groups (Mutually Exclusive, Reentrant)
- Timers & Rate Control
- Lifecycle Nodes (Managed Nodes)

### ROBOT DESCRIPTION & SIMULATION
- TF2 (Transform Tree, Static/Dynamic Broadcaster)
- URDF / xacro / SRDF
- Launch System (Launch Files, Substitutions, Conditions)
- Parameter System (YAML, Dynamic Reconfigure)

### NAVIGATION & MANIPULATION
- **Nav2**: Behavior Trees, Plugins (Planner, Controller, Recovery)
- SLAM (slam_toolbox, Cartographer)
- Localization (AMCL, Nav2 Localization)
- **MoveIt 2**: Motion Planning, Kinematics, Collision Checking
- Simulation: Gazebo (Ignition/Garden/Harmonic), Isaac Sim
- Visualization: RViz2, Foxglove

### OUTPUT TARGET
- [ ] Mampu membangun robot lengkap menggunakan ROS 2 (Simulasi → Real Robot)

---

## ROADMAP 6: PRODUCTION ROBOTICS
=================================
> **Rarely Taught** — Skill untuk robot komersial di *production environment*.

### LINUX & SYSTEM ADMIN
- Ubuntu Server / Debian Hardening
- systemd (Service, Socket, Timer, Watchdog)
- Networking (Netplan, iptables, WireGuard, Tailscale)
- Permissions, udev rules, Real-time Kernel (PREEMPT_RT)

### CONTAINERIZATION & DEPLOYMENT
- Docker (Multi-stage Build, BuildKit)
- Docker Compose (Development & Production)
- Cross-compilation (arm64/armhf)
- OTA / OTA Updates (RAUC, SWUpdate, Mender)

### OBSERVABILITY & RELIABILITY
- Structured Logging (JSON, OpenTelemetry)
- Metrics (Prometheus, Grafana)
- Health Checks & Readiness Probes
- Distributed Tracing (Jaeger, Zipkin)
- Alerting & On-call

### FLEET MANAGEMENT
- Fleet Orchestration
- Remote Access & Debugging
- Configuration Management (Ansible, SaltStack)
- Multi-Robot Coordination

### SECURITY
- TLS/mTLS (DDS Security, Zenoh)
- Authentication & Authorization (OAuth2, OIDC, SPIFFE)
- Secure Boot & TPM
- SBOM & Vulnerability Scanning (Syft, Grype, Trivy)

### AI / PERCEPTION (Production Grade)
- OpenCV & Classical CV
- ONNX Runtime / TensorRT / OpenVINO
- Model Optimization (Quantization, Pruning, Distillation)
- Dataset Management & Annotation (CVAT, Label Studio)
- MLOps for Robotics (MLflow, DVC, ClearML)

### OUTPUT TARGET
- [ ] Siap membangun & mendeploy robot komersial ke *production fleet*

---

## LEARNING PATH RECOMMENDATION (12 BULAN)
==========================================

| Bulan | Fokus Utama                    | Output Target                    |
|-------|--------------------------------|----------------------------------|
| 1-2   | Modern C++ + Modern Python     | Library C++ + Package Python     |
| 3     | Software Engineering           | Clean Architecture Project       |
| 4-5   | Robotics Core (Math + Motion)  | Robot Simulator Mini Project     |
| 6-7   | ROS 2 Core + Nav2 + MoveIt     | Robot Navigasi + Manipulasi      |
| 8     | Embedded + Communication       | MCU Driver + ROS2 Bridge         |
| 9     | Perception + Sensor Fusion     | Sensor Fusion Pipeline           |
| 10    | Production Linux + Docker      | Deploy ke Robot Real (Jetson/PC) |
| 11    | Fleet + OTA + Monitoring       | Fleet Dashboard + OTA Demo       |
| 12    | Capstone Project               | **Robot Komersial End-to-End**   |

---

## RECOMMENDED RESOURCES
=========================

### BOOKS
- **C++**: *Effective Modern C++* (Meyers), *C++ Templates* (Vandevoorde)
- **Python**: *Effective Python* (Slatkin), *Architecture Patterns with Python* (Percival)
- **Software Arch**: *Clean Architecture* (Martin), *Software Architecture Patterns* (Richards)
- **Robotics**: *Modern Robotics* (Lynch & Park), *Probabilistic Robotics* (Thrun)
- **Control**: *Feedback Control of Dynamic Systems* (Franklin)
- **ROS 2**: *ROS 2 Humble Documentation*, *ROS 2 Design Patterns* (Silva)
- **Embedded**: *Real-Time C++* (Kormanyos), *Mastering STM32* (Carminen)

### COURSES & CERTS
- **ROS 2**: The Construct, Articulated Robotics (YouTube)
- **Control**: Underactuated Robotics (MIT 6.832), Control Bootcamp (Data-Book)
- **Planning**: Motion Planning (CMU 16-735), Robotic Manipulation (MIT 6.800)
- **Embedded**: Embedded Linux (Chris Simmonds), FreeRTOS Tutorial

### HANDS-ON PROJECTS
1. **C++ Library** → Math/Kinematics Library + Unit Test + CI
2. **Python Package** → Robot Interface Package + PyPI Publish
3. **Mini Robot Sim** → 2D Differential Drive + EKF SLAM (Python/C++)
4. **ROS 2 Mobile Robot** → Nav2 + SLAM + Behavior Tree
5. **ROS 2 Manipulator** → MoveIt 2 + Pick & Place + Perception
6. **Embedded Bridge** → STM32/ESP32 Firmware + Micro-ROS
7. **Production Deploy** → Docker + systemd + OTA + Monitoring Stack

---

## PROGRESS TRACKER
===================

| Roadmap                      | Status       | Progress | Target Date |
|------------------------------|--------------|----------|-------------|
| 1. Modern C++                | [ ] Not Started | [====    ] 40% | YYYY-MM-DD  |
| 2. Modern Python             | [ ] Not Started | [===     ] 30% | YYYY-MM-DD  |
| 3. Software Engineering      | [ ] Not Started | [==      ] 20% | YYYY-MM-DD  |
| 4. Robotics Core             | [ ] Not Started | [=       ] 10% | YYYY-MM-DD  |
| 5. ROS 2 Professional        | [ ] Not Started | [        ] 0%  | YYYY-MM-DD  |
| 6. Production Robotics       | [ ] Not Started | [        ] 0%  | YYYY-MM-DD  |

---

## NOTES & PERSONAL REFLECTION
==============================
> *Catatan pribadi, blockers, insights, link referensi penting, dll.*

```
Tanggal: YYYY-MM-DD
Catatan:
- ...
- ...

Tanggal: YYYY-MM-DD
Catatan:
- ...
```

---

*Last Updated: 2026-07-26*
*Version: 2.0 (Restructured for readability)*