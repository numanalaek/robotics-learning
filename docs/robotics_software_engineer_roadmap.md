# ROADMAP ROBOTICS SOFTWARE ENGINEER

Structured roadmap to become a **Robotics Software Engineer** capable of building commercial robots from scratch to production.

```
                        ROBOTICS SOFTWARE ENGINEER
               ┌──────────────────┬──────────────────┐
               │                  │                  │
               ▼                  ▼                  ▼
          Modern C++         Modern Python     Software Engineering
          (Roadmap 1)        (Roadmap 2)        (Roadmap 3)
               │                  │                  │
               └──────────────────┴──────────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │  Robotics Core  │  ◄ Core Fundamental (Roadmap 4)
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ ROS2 Professional│ ◄ Framework (Roadmap 5)
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │   Production    │  ◄ Production Ready (Roadmap 6)
                    │   Robotics      │
                    └─────────────────┘
```

---

## ROADMAP 1: MODERN C++

**Target:** Become a C++ Engineer capable of building high-performance robot software.

### Topik
- Modern C++17/20
- STL (Standard Template Library)
- Memory Management (manual & smart pointers)
- Smart Pointers (unique_ptr, shared_ptr, weak_ptr)
- Concurrency & Multithreading
- CMake & Build Systems
- Design Patterns (Singleton, Factory, Observer, Strategy, dll)
- Debugging (GDB, Valgrind, AddressSanitizer)
- Performance Optimization (Profiling, Cache Optimization, SIMD)

### Output Target
- [ ] Able to create reusable C++ libraries
- [ ] Able to read & understand large C++ projects (ROS2, MoveIt, etc.)
- [ ] Ready to use **rclcpp** (ROS2 C++ client library)

---

## ROADMAP 2: MODERN PYTHON

**Target:** Become a Python Engineer capable of building modular & maintainable robot software.

### Topik
- Modern Python (3.10+): Type Hints, Dataclasses, Pattern Matching
- OOP & Clean Architecture
- Package Management (pip, poetry, uv)
- Virtual Environment (venv, conda, pixi)
- Testing (pytest, unittest, mock)
- AsyncIO & Concurrency
- Clean Architecture (Layered, Hexagonal)
- Linting & Formatting (ruff, black, mypy)

### Output Target
- [ ] Able to create Python packages *publishable* to PyPI
- [ ] Ready to use **rclpy** (ROS2 Python client library)

---

## ROADMAP 3: SOFTWARE ENGINEERING (Language-Agnostic)

**Target:** Able to design enterprise-grade industrial software.

### Architecture Patterns
- Layered Architecture
- Clean Architecture
- Hexagonal Architecture (Ports & Adapters)
- Onion Architecture

### OOP & Design Principles
- SOLID Principles
- Composition over Inheritance
- Interface Design & Dependency Injection
- Design Patterns:
  - Creational: Factory, Builder, Singleton
  - Behavioral: Strategy, Observer, State, Command
  - Structural: Adapter, Decorator, Facade

### Clean Code Practices
- Naming Conventions
- Function & Class Design
- Error Handling & Result Types
- Logging & Observability

### Testing Strategy
- Unit Testing (TDD)
- Integration Testing
- Regression Testing
- Property-Based Testing

### Debugging & Performance
- Debugging Techniques
- Logging & Structured Logging
- Profiling (CPU, Memory)
- Performance Analysis

### DevOps & Tooling
- Git (Branching Strategy, Conventional Commits)
- Docker & Containerization
- CI/CD (GitHub Actions, GitLab CI)
- Static Analysis & Security Scanning

### Output Target
- [ ] Able to design enterprise-grade software architecture

---

## ROADMAP 4: ROBOTICS CORE (FUNDAMENTAL)

> **Most Important** — Concepts here are universal for both C++ and Python.

### Robot Architecture
- Robot Class Design
- Hardware Abstraction Layer (HAL)
- Driver Development
- Sensor Layer Abstraction
- Controller Layer
- Safety Layer (Emergency Stop, Watchdog)

### Robot Mathematics
- Linear Algebra: Vector, Matrix, Eigen/NumPy
- Coordinate Frames & Transformations
- Quaternion & Rotation Representations
- Lie Groups & Lie Algebra (SE(3), SO(3))

### Motion & Kinematics
- Forward Kinematics (FK)
- Inverse Kinematics (IK) — Analytical & Numerical
- Velocity Kinematics (Jacobian)
- Acceleration & Dynamics
- Trajectory Generation (Polynomial, Spline, S-curve)

### Control Theory
- PID Control & Tuning
- State Machine (Finite State Machine)
- Behavior Trees (BT)
- Model Predictive Control (MPC) — *Advanced*

### Motion Planning & Navigation
- Graph Search: A*, Dijkstra, D*
- Sampling-Based: RRT, RRT*, PRM
- Optimization-Based: CHOMP, TrajOpt
- Path Following: Pure Pursuit, Stanley, MPC
- SLAM (EKF, GraphSLAM, LiDAR SLAM, Visual SLAM)
- Localization (AMCL, Particle Filter)

### Perception
- Camera Models & Calibration (Intrinsic/Extrinsic)
- LiDAR Processing (Point Cloud, PCL)
- IMU & Sensor Fusion (EKF, UKF, Factor Graphs)
- Encoder & Odometry

### Communication Protocols
- Serial: UART, SPI, I2C
- Fieldbus: CAN (CANopen, J1939), EtherCAT
- Network: TCP/IP, UDP, ROS2 DDS
- IoT/Industrial: MQTT, OPC-UA, Modbus

### Embedded Systems
- MCU: STM32 (HAL/LL), ESP32 (FreeRTOS/ESP-IDF)
- ARM Cortex-M Architecture
- RTOS: FreeRTOS, Zephyr, ThreadX
- Embedded Linux: Yocto, Buildroot
- Bare Metal vs RTOS vs Linux

### Output Target
- [ ] Able to design robot architecture from scratch (Hardware → Software)

---

## ROADMAP 5: ROS 2 PROFESSIONAL

> All previous knowledge converges here.

### ROS 2 Core Concepts
- Workspace & Package Structure (ament_cmake, ament_python)
- Node Lifecycle & Composition
- Communication: Topic, Service, Action
- QoS Policies (Reliability, Durability, History, Deadline)
- DDS Implementation (Fast DDS, Cyclone DDS, Zenoh)
- Discovery & Domain Partitions

### Execution Model
- Executors (Single-threaded, Multi-threaded, Static)
- Callback Groups (Mutually Exclusive, Reentrant)
- Timers & Rate Control
- Lifecycle Nodes (Managed Nodes)

### Robot Description & Simulation
- TF2 (Transform Tree, Static/Dynamic Broadcaster)
- URDF / xacro / SRDF
- Launch System (Launch Files, Substitutions, Conditions)
- Parameter System (YAML, Dynamic Reconfigure)

### Navigation & Manipulation
- **Nav2**: Behavior Trees, Plugins (Planner, Controller, Recovery)
- SLAM (slam_toolbox, Cartographer)
- Localization (AMCL, Nav2 Localization)
- **MoveIt 2**: Motion Planning, Kinematics, Collision Checking
- Simulation: Gazebo (Ignition/Garden/Harmonic), Isaac Sim
- Visualization: RViz2, Foxglove

### Output Target
- [ ] Able to build a complete robot using ROS 2 (Simulation → Real Robot)

---

## ROADMAP 6: PRODUCTION ROBOTICS

> **Rarely Taught** — Skills for commercial robots in a *production environment*.

### Linux & System Admin
- Ubuntu Server / Debian Hardening
- systemd (Service, Socket, Timer, Watchdog)
- Networking (Netplan, iptables, WireGuard, Tailscale)
- Permissions, udev rules, Real-time Kernel (PREEMPT_RT)

### Containerization & Deployment
- Docker (Multi-stage Build, BuildKit)
- Docker Compose (Development & Production)
- Cross-compilation (arm64/armhf)
- OTA / OTA Updates (RAUC, SWUpdate, Mender)

### Observability & Reliability
- Structured Logging (JSON, OpenTelemetry)
- Metrics (Prometheus, Grafana)
- Health Checks & Readiness Probes
- Distributed Tracing (Jaeger, Zipkin)
- Alerting & On-call

### Fleet Management
- Fleet Orchestration
- Remote Access & Debugging
- Configuration Management (Ansible, SaltStack)
- Multi-Robot Coordination

### Security
- TLS/mTLS (DDS Security, Zenoh)
- Authentication & Authorization (OAuth2, OIDC, SPIFFE)
- Secure Boot & TPM
- SBOM & Vulnerability Scanning (Syft, Grype, Trivy)

### AI / Perception (Production Grade)
- OpenCV & Classical CV
- ONNX Runtime / TensorRT / OpenVINO
- Model Optimization (Quantization, Pruning, Distillation)
- Dataset Management & Annotation (CVAT, Label Studio)
- MLOps for Robotics (MLflow, DVC, ClearML)

### Output Target
- [ ] Ready to build & deploy commercial robots to a *production fleet*

---

## LEARNING PATH RECOMMENDATION (12 BULAN)

| Bulan | Fokus Utama                    | Output Target                    |
|-------|-------------------------------|----------------------------------|
| 1-2   | Modern C++ + Modern Python     | Library C++ + Package Python     |
| 3     | Software Engineering           | Clean Architecture Project       |
| 4-5   | Robotics Core (Math + Motion)  | Robot Simulator Mini Project     |
| 6-7   | ROS 2 Core + Nav2 + MoveIt     | Robot Navigation + Manipulation  |
| 8     | Embedded + Communication       | MCU Driver + ROS2 Bridge         |
| 9     | Perception + Sensor Fusion     | Sensor Fusion Pipeline           |
| 10    | Production Linux + Docker      | Deploy to Real Robot (Jetson/PC) |
| 11    | Fleet + OTA + Monitoring       | Fleet Dashboard + OTA Demo       |
| 12    | Capstone Project               | **Commercial Robot End-to-End** |

---

## RECOMMENDED RESOURCES

### Books
- **C++**: *Effective Modern C++* (Meyers), *C++ Templates* (Vandevoorde)
- **Python**: *Effective Python* (Slatkin), *Architecture Patterns with Python* (Percival)
- **Software Arch**: *Clean Architecture* (Martin), *Software Architecture Patterns* (Richards)
- **Robotics**: *Modern Robotics* (Lynch & Park), *Probabilistic Robotics* (Thrun)
- **Control**: *Feedback Control of Dynamic Systems* (Franklin)
- **ROS 2**: *ROS 2 Humble Documentation*, *ROS 2 Design Patterns* (Silva)
- **Embedded**: *Real-Time C++* (Kormanyos), *Mastering STM32* (Carminen)

### Courses & Certs
- **ROS 2**: The Construct, Articulated Robotics (YouTube)
- **Control**: Underactuated Robotics (MIT 6.832), Control Bootcamp (Data-Book)
- **Planning**: Motion Planning (CMU 16-735), Robotic Manipulation (MIT 6.800)
- **Embedded**: Embedded Linux (Chris Simmonds), FreeRTOS Tutorial

### Hands-On Projects
1. **C++ Library** → Math/Kinematics Library + Unit Test + CI
2. **Python Package** → Robot Interface Package + PyPI Publish
3. **Mini Robot Sim** → 2D Differential Drive + EKF SLAM (Python/C++)
4. **ROS 2 Mobile Robot** → Nav2 + SLAM + Behavior Tree
5. **ROS 2 Manipulator** → MoveIt 2 + Pick & Place + Perception
6. **Embedded Bridge** → STM32/ESP32 Firmware + Micro-ROS
7. **Production Deploy** → Docker + systemd + OTA + Monitoring Stack

---

## PROGRESS TRACKER

| Roadmap                      | Progress |
|------------------------------|----------|
| 1. Modern C++                | ████░░░░░░ ~48% |
| 2. Modern Python             | ░░░░░░░░░░ 0% |
| 3. Software Engineering      | ░░░░░░░░░░ 0% |
| 4. Robotics Core             | ░░░░░░░░░░ 0% |
| 5. ROS 2 Professional        | ░░░░░░░░░░ 0% |
| 6. Production Robotics       | ░░░░░░░░░░ 0% |

---

## NOTES & PERSONAL REFLECTION

> *Personal notes, blockers, insights, important reference links, etc.*

```
Date: YYYY-MM-DD
Notes:
- ...
- ...
```

---

*Last Updated: 2026-07-28*
*Version: 2.0 (Restructured for readability)*