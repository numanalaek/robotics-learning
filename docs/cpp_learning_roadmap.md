# ROADMAP MODERN C++ (C++17/C++20)
====================================
Robotics Software Engineer Edition

## OVERVIEW
===========
Roadmap terstruktur untuk menguasai **Modern C++** sebagai Robotics Software Engineer — dari fundamental hingga siap menggunakan **rclcpp** (ROS 2) dan membangun software robot berperforma tinggi.

```
┌─────────────────────────────────────────────────────────────┐
│                    MODERN C++ FOR ROBOTICS                  │
├──────────────┬──────────────┬──────────────┬────────────────┤
│  CORE C++    │  MODERN C++  │  ENGINEERING │   ROBOTICS     │
│  (Phase 1-2) │  (Phase 3-4) │  (Phase 5-10)│  (Phase 11-12) │
└──────────────┴──────────────┴──────────────┴────────────────┘
```

**Progress Keseluruhan:** ~20–25%

---

## PILLAR 1 — CORE C++
=======================

### PHASE 1: C++ FUNDAMENTALS
**Tujuan:** Menguasai sintaks C++ secara mendalam.

**Program Structure**
- [x] main()
- [x] #include
- [x] namespace
- [x] Compilation Process
- [x] Header Files

**Variables & Data Types**
- [x] int, float, double, bool, char
- [x] std::string
- [x] auto, const, constexpr

**Input & Output**
- [x] std::cout, std::cin, std::endl
- [x] Stream Manipulators (fixed, setprecision, setw)

**Operators**
- [x] Arithmetic, Assignment, Comparison, Logical
- [x] Increment / Decrement, Ternary Operator

**Memory Fundamentals**
- [x] Variable Memory Layout
- [x] Address Operator (&), Pointer (*)
- [x] Memory Visualization
- [x] Reference (&), Const Reference
- [x] Pass by Value / Pointer / Reference / Const Reference

**Control Flow**
- [x] if, else if, else, switch
- [x] while, for, range-based for

**Functions**
- [x] Declaration, Definition, Return Value
- [x] Parameters, Function Overloading
- [x] Default Parameters

**Scope & Lifetime**
- [x] Global, Local, Block Scope
- [x] Variable & Object Lifetime
- [x] Construction / Destruction Order (LIFO)

---

### PHASE 2: OBJECT ORIENTED PROGRAMMING

**Class & Object**
- [x] Class, Object, Data Members
- [ ] Member Functions
- [x] struct vs class

**Constructor & Destructor**
- [ ] Constructor, Destructor
- [ ] Member Initializer List
- [x] Constructor Overloading
- [x] Default / Parameterized Constructor

**Access Control**
- [ ] public, private, protected

**Encapsulation**
- [ ] Getter, Setter, Invariant
- [ ] const Member Function

**Object Copying**
- [ ] Copy Constructor, Copy Assignment
- [ ] Shallow Copy, Deep Copy

**Composition**
- [ ] Has-a Relationship
- [ ] Class contains another class

**Inheritance**
- [ ] Base Class, Derived Class
- [ ] is-a Relationship, Protected Members

**Polymorphism**
- [ ] Virtual Function, override
- [ ] virtual Destructor
- [ ] Abstract Class, Pure Virtual Function
- [ ] Interface Design

---

## PILLAR 2 — MODERN C++ LANGUAGE & STL
=========================================

### PHASE 3: MODERN C++ LANGUAGE

**Modern Syntax**
- [x] auto, constexpr
- [ ] nullptr, enum class, using
- [ ] Structured Binding, inline

**References**
- [x] Reference (&), Const Reference
- [ ] Rvalue Reference (&&)

**Memory Management**
- [x] Stack Memory
- [ ] Heap Memory, new, delete
- [ ] Memory Ownership

**Smart Pointer**
- [ ] std::unique_ptr
- [ ] std::shared_ptr
- [ ] std::weak_ptr
- [ ] Ownership Concept

**Move Semantics**
- [ ] std::move
- [ ] Move Constructor, Move Assignment
- [ ] Rule of 3 / Rule of 5 / Rule of 0

**Modern String & Array Views**
- [ ] std::string_view
- [ ] std::span

**Lambda Expression**
- [ ] Basic Lambda, Parameters
- [ ] Capture by Value / Reference
- [ ] Generic Lambda, Callback

**Templates**
- [ ] Function Template, Class Template
- [ ] Template Parameters

**Exception Handling**
- [ ] try, throw, catch, noexcept

**Modern Error Handling**
- [ ] std::optional, std::variant

---

### PHASE 4: STL (STANDARD TEMPLATE LIBRARY)

**Sequence Containers**
- [ ] std::array, std::vector
- [ ] std::list, std::deque

**Associative Containers**
- [ ] std::map, std::unordered_map
- [ ] std::set, std::unordered_set

**Container Adapters**
- [ ] std::queue, std::stack
- [ ] std::priority_queue

**Algorithms**
- [ ] std::sort, std::find, std::count
- [ ] std::for_each, std::transform
- [ ] std::min_element, std::max_element
- [ ] std::accumulate

**Utilities**
- [ ] std::pair, std::tuple
- [ ] std::optional, std::variant

**Time**
- [ ] std::chrono (Duration, Time Point)
- [ ] Time Measurement

**Iterators**
- [ ] Iterator Concept
- [ ] begin(), end(), const_iterator

---

## PILLAR 3 — ENGINEERING & TOOLING
====================================

### PHASE 5: PROJECT STRUCTURE

**Project Organization**
- [ ] Header (.hpp), Source (.cpp)
- [ ] Include Guard, #pragma once
- [ ] Namespace Organization
- [ ] Directory Structure, Dependency Management

**Interface & Implementation**
- [ ] Declaration vs Definition
- [ ] Separation of Interface / Implementation
- [ ] Translation Unit

**Coding Style**
- [x] Naming Convention, Function Design
- [x] Magic Number Avoidance
- [ ] Class Design, API Design
- [ ] Const Correctness

---

### PHASE 6: BUILD SYSTEM

**Compiler**
- [x] g++, C++ Standard Flag
- [x] -Wall, -Wextra

**Build Workflow**
- [x] Build Folder Concept, Executable Cleanup
- [ ] Debug Build, Release Build, Debug Symbols

**CMake**
- [ ] CMakeLists.txt, Project Definition
- [ ] Configure, Build, Install
- [ ] Target Management

**Libraries**
- [ ] Static Library, Shared Library
- [ ] Linking, Include Directories

---

### PHASE 7: MULTITHREADING & CONCURRENCY

**Thread**
- [ ] std::thread

**Synchronization**
- [ ] std::mutex
- [ ] std::lock_guard, std::unique_lock

**Communication**
- [ ] std::condition_variable
- [ ] std::future, std::async

**Atomic**
- [ ] std::atomic

**Concurrency Design**
- [ ] Data Race, Race Condition
- [ ] Thread Safety
- [ ] Producer-Consumer

---

### PHASE 8: DESIGN PRINCIPLES & PATTERNS

**Design Principles**
- [ ] SOLID
- [ ] High Cohesion, Low Coupling
- [ ] Dependency Inversion
- [ ] Composition over Inheritance

**Patterns**
- [ ] Factory Pattern
- [ ] Strategy Pattern
- [ ] Observer Pattern
- [ ] State Pattern
- [ ] Adapter Pattern
- [ ] Singleton (Understand Only)

---

### PHASE 9: DEBUGGING & TESTING

**Debugging**
- [ ] gdb (Breakpoint, Step, Watch, Stack Trace)
- [ ] VS Code Debugger

**Testing**
- [ ] Unit Testing, GoogleTest
- [ ] Test Fixture, Assertion

**Memory Debugging**
- [ ] AddressSanitizer
- [ ] UndefinedBehaviorSanitizer
- [ ] Memory Leak Detection

**Profiling**
- [ ] Performance Analysis
- [ ] CPU Profiling, Memory Profiling

---

### PHASE 10: BEST PRACTICES

**Code Quality**
- [~] const Correctness
- [ ] RAII, Exception Safety
- [ ] Clean Code, Defensive Programming

**Memory & Ownership**
- [x] Copy vs Reference
- [ ] Copy vs Move, Ownership
- [ ] Lifetime Management

**Performance**
- [~] Efficient Loop Design
- [ ] Memory Optimization
- [ ] Avoid Unnecessary Copy
- [ ] Cache Awareness

**Documentation**
- [ ] README, API Documentation
- [ ] Doxygen

---

## PILLAR 4 — C++ FOR ROBOTICS
================================

### PHASE 11: C++ FOR ROBOTICS

**Robot Software Architecture**
- [ ] Robot Class Design
- [ ] Hardware Abstraction Layer (HAL)
- [ ] Sensor Interface, Actuator Interface
- [ ] State Machine, Command Architecture

**Sensor & Actuator**
- [ ] Sensor Data Model, Sensor Polling
- [ ] Actuator Control, Safety Limit

**Communication**
- [ ] Serial / UART, TCP/IP, UDP
- [ ] CAN Bus

**Timing**
- [ ] Control Loop, Sampling Rate
- [ ] Timeout, Watchdog

**Mathematics**
- [ ] Vector, Matrix
- [ ] Coordinate Transform, Quaternion

**Real-Time Programming**
- [ ] Deterministic Programming
- [ ] Memory Allocation Strategy
- [ ] Thread-Safe Design
- [ ] Real-Time Constraints

---

### PHASE 12: ROS 2 PREPARATION

**ROS 2 C++ Concepts**
- [ ] rclcpp Coding Style
- [ ] Node Architecture
- [ ] Publisher, Subscriber
- [ ] Service, Action

**Callbacks**
- [ ] Callback Design
- [ ] Timer Callback, Subscription Callback

**Memory**
- [ ] Shared Pointer Usage
- [ ] Ownership in ROS 2

**Architecture**
- [ ] Node Composition
- [ ] Lifecycle Node
- [ ] Executor, Callback Groups

---

## MASTER TARGET CHECKLIST
==========================

### CORE
- [ ] Menguasai C++ Fundamentals & OOP
- [ ] Menguasai Modern C++ (C++17/C++20) — Move Semantics, Smart Pointers, Lambdas
- [ ] Menguasai STL (Containers, Algorithms, Utilities)
- [ ] Paham Memory Management, Ownership, dan Lifetime

### ENGINEERING
- [ ] Mampu menggunakan CMake & Build System
- [ ] Mampu Debug & Test (gdb, GoogleTest, Sanitizers)
- [ ] Mampu menulis Clean Code & menerapkan Design Patterns
- [ ] Paham Multithreading & Concurrency

### ROBOTICS
- [ ] Mampu membuat project C++ modular
- [ ] Mampu membaca project C++ skala besar (ROS 2, MoveIt)
- [ ] Mampu membuat architecture software robot (HAL, State Machine)
- [ ] Paham Real-Time Programming & Time-Critical Code

### ROS 2
- [ ] Siap mempelajari ROS 2 menggunakan **rclcpp**
- [ ] Paham Node, Publisher, Subscriber, Service, Action di C++

---

## LEARNING PATH RECOMMENDATION (12 BULAN)
===========================================

| Bulan | Fokus Utama                          | Output Target                            |
|-------|---------------------------------------|-------------------------------------------|
| 1     | Phase 1: C++ Fundamentals             | Console apps, paham pointer & reference   |
| 2     | Phase 2: OOP                          | Class design, inheritance, polymorphism   |
| 3     | Phase 3: Modern C++ Language          | Smart pointers, move semantics, lambdas   |
| 4     | Phase 4: STL                          | Efficient data structures & algorithms    |
| 5     | Phase 5-6: Project Structure + CMake  | Library C++ dengan CMake build            |
| 6     | Phase 7: Multithreading               | Thread-safe concurrent code               |
| 7     | Phase 8-9: Patterns + Testing         | GoogleTest + Design Pattern project       |
| 8     | Phase 10: Best Practices              | Clean Code, RAII, Performance optimization |
| 9     | Phase 11: C++ for Robotics            | Robot HAL + Control Loop in C++           |
| 10    | Phase 12: ROS 2 Preparation           | rclcpp Node with Pub/Sub                  |
| 11    | Integrasi C++ + ROS 2                 | Build ROS 2 package C++                   |
| 12    | **Capstone**                          | **Robot software library in C++**         |

---

## PROGRESS TRACKER
====================

| Pillar | Phase | Progress |
|--------|-------|----------|
| **Core C++** | 1. C++ Fundamentals | ██████████ 100% |
| | 2. OOP | ██░░░░░░░░ ~20% |
| **Modern C++ & STL** | 3. Modern C++ Language | ██░░░░░░░░ ~15% |
| | 4. STL | ░░░░░░░░░░ 0% |
| **Engineering & Tooling** | 5. Project Structure | ████░░░░░░ ~35% |
| | 6. Build System | ██░░░░░░░░ ~20% |
| | 7. Multithreading | ░░░░░░░░░░ 0% |
| | 8. Design Patterns | ░░░░░░░░░░ 0% |
| | 9. Debugging & Testing | ░░░░░░░░░░ 0% |
| | 10. Best Practices | ███░░░░░░░ ~30% |
| **C++ for Robotics** | 11. C++ for Robotics | ░░░░░░░░░░ 0% |
| | 12. ROS 2 Preparation | ░░░░░░░░░░ 0% |

---

## NOTES & PERSONAL REFLECTION
===============================
> *Catatan pribadi, blockers, insights, link referensi penting, dll.*

```
Tanggal: YYYY-MM-DD
Catatan:
- ...
- ...
```

---

*Last Updated: 2026-07-26*
*Version: 2.0 (Restructured for readability)*