# Embedded-Prompt

# Embedded Command and Control Simulator

This is a simple, interactive C++ console application that mimics how commands are processed in an embedded command-and-control system.

## What It Does

The simulator accepts real-time user commands from the console, processes them based on the system's current state, and simulates hardware responses like starting a motor, setting a speed, or checking status.

Commands supported:
- `START` – Begin system operation
- `STOP` – Halt the system
- `SET_SPEED <value>` – Set a motor speed (e.g. `SET_SPEED 50`)
- `STATUS` – Check current system state and speed

Commands are case-sensitive for example, `start` won't work, but `START` will.
If you mistype a command, the program tries to help by suggesting what you may have meant.

## How It Works

- `main.cpp` – The core of the program that handles input and routes commands
- `CommandAndControl.cpp/hpp` – Parses commands and manages system-level logic
- `HardwareSimulator.cpp/hpp` – A lightweight fake hardware layer to simulate starting/stopping and speed control

### Requirements
- C++17 or higher
- CMake (recommended for building)
- A terminal or console that supports input
