# 🤖 Robotics Learning

[![C++](https://img.shields.io/badge/C++-17/20-blue)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3-brightgreen)](https://python.org/)
[![ROS 2](https://img.shields.io/badge/ROS-2-22314E?logo=ros)](https://docs.ros.org/)
[![License](https://img.shields.io/badge/License-Educational-lightgrey)]()

> A structured learning repository for **Modern C++**, **Python**, **ROS 2**, and **Robotics Software Engineering**.

---

## 📋 Table of Contents

- [Learning Philosophy](#-learning-philosophy)
- [Roadmap](#-learning-roadmap)
- [Repository Structure](#-repository-structure)
- [Quick Start](#-quick-start)
- [Current Focus](#-current-focus)
- [Learning Goals](#-learning-goals)
- [License](#-license)

---

## 🎯 Learning Philosophy

Build a strong engineering foundation before moving to advanced robotics technologies.

- **Understand** concepts before memorizing syntax
- **Learn** step by step from fundamentals to professional development
- **Practice** every topic with hands-on examples
- **Build** small robotics-oriented projects to reinforce understanding
- **Document** everything for future reference

---

## 🗺️ Learning Roadmap

### Phase 1 — C++ Fundamentals
[`cpp/phase01_fundamentals/`](cpp/cpp-learning/phase01_fundamentals/)

```
✅ Program Structure    ✅ Variables & Data Types    ✅ Memory & Pointers
✅ Functions            ✅ References                ✅ Control Flow
✅ Scope & Lifetime
```

### Phase 2 — Object-Oriented Programming
[`cpp/phase02_object_oriented_programming/`](cpp/cpp-learning/phase02_object_oriented_programming/)

```
✅ Struct vs Class      ✅ Object & Copy            ✅ Constructor
✅ Destructor           ✅ Encapsulation            ✅ Getter & Setter
✅ Copy Constructor     ⬜ Copy Assignment          ⬜ Inheritance
⬜ Polymorphism         ⬜ Composition
```

### Phase 3 — Modern C++
```
⬜ Smart Pointers       ⬜ Move Semantics           ⬜ Templates
⬜ Lambda Expressions   ⬜ Exception Handling
```

### Phase 4 — STL
```
⬜ Containers           ⬜ Algorithms               ⬜ Iterators
⬜ Utilities
```

### Phase 5 — Software Engineering
```
⬜ Project Organization ⬜ CMake                    ⬜ Modular Design
⬜ Best Practices
```

### Phase 6 — Robotics Programming
```
⬜ Robot Architecture   ⬜ HAL                      ⬜ Sensor Interface
⬜ State Machine        ⬜ Robot Communication
```

### Phase 7 — ROS 2 Development
```
⬜ rclcpp               ⬜ Nodes                    ⬜ Topics
⬜ Services             ⬜ Actions                  ⬜ Lifecycle Nodes
```

### Phase 8 — Autonomous Robotics
```
⬜ Localization         ⬜ Mapping                  ⬜ Navigation
⬜ Computer Vision      ⬜ Sensor Fusion
```

---

## 📁 Repository Structure

```text
robotics/
│
├── cpp/cpp-learning/
│   ├── phase01_fundamentals/          ✅ C++ basics
│   ├── phase02_object_oriented_programming/  ✅ OOP
│   ├── phase03_modern_cpp/            ⬜ Modern C++
│   └── phase04_stl/                   ⬜ STL
│
├── python/                            🐍 Python robotics examples
│   ├── nuin_amr/
│   └── robot_monitor/
│
├── docs/                              📚 Documentation & roadmaps
│
└── README.md                          👈 You are here
```

---

## 🚀 Quick Start

```bash
# Clone
git clone https://github.com/your-username/robotics-learning.git
cd robotics-learning

# Run a C++ example
cd cpp/cpp-learning/phase02_object_oriented_programming/19_copy_constructor
g++ copy_constructor.cpp -o copy_constructor && ./copy_constructor

# Run a Python example
cd python/robot_monitor
python robot_control.py
```

---

## 🎯 Current Focus

**Phase 2 — Object-Oriented Programming**

Primary objectives:
- Master object-oriented programming in C++
- Understand object lifetime and memory management
- Learn modern software design principles
- Prepare for professional ROS 2 development

---

## 🏆 Learning Goals

After completing this repository, I expect to be able to:

- [ ] Understand Modern C++ (C++17/C++20)
- [ ] Design modular and maintainable C++ applications
- [ ] Read and understand large-scale C++ codebases
- [ ] Build robotics software using object-oriented design
- [ ] Develop professional ROS 2 applications
- [ ] Design software architecture for autonomous mobile robots
- [ ] Apply software engineering best practices in robotics
- [ ] Build complete robotics software projects from scratch

---

## 📄 License

This repository is intended for **educational purposes**.

Feel free to learn, fork, improve, and share.
