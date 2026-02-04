# Battery Runtime Scheduler for Wearable Devices

## Overview

This project provides a C implementation of a greedy algorithm to compute
the minimum total runtime required to execute tasks on a wearable device
with limited battery capacity.

Each task consumes battery at a constant rate, while the device can recharge
during idle periods. The objective is to schedule charging optimally so that
all tasks are completed in minimum time without violating battery constraints.

This project is developed as part of a technical assessment for the
System Framework Engineer Internship.

---

## Features

- Simulates battery charging and discharging
- Ensures battery never drops below zero
- Prevents battery from exceeding maximum capacity
- Calculates minimum idle time required
- Handles fractional charging durations
- Detects impossible task sequences

---

## Prerequisites

Before running this project, ensure you have:

- GCC Compiler
- Linux / macOS / Windows (with MinGW)

To check GCC installation:

```bash
gcc --version
Setup Instructions
Clone the Repository
git clone https://github.com/ajjushaik7861-ai/battery-runtime-scheduler-wearable-battery-task-system-framework-task1
cd battery-runtime-scheduler-wearable-battery-task-system-framework-task1
Compilation
Compile the program using:

gcc src/task1.c -o task1 -lm
Note: The -lm flag is required for linking the math library.

Execution Steps
Run the executable:

./task1
You will be prompted to enter:

Battery capacity (mAh)

Initial battery level (mAh)

Charging rate (mAh/sec)

Number of tasks

Duration and drain rate for each task

Input Format
batteryCapacity
initialBattery
chargeRate
n
duration1 drainRate1
duration2 drainRate2
...
durationN drainRateN
Where:

batteryCapacity → Maximum battery capacity

initialBattery → Initial battery level

chargeRate → Charging speed during idle

n → Number of tasks

duration → Task execution time

drainRate → Battery consumption rate

Output Format
Prints the minimum total runtime rounded to one decimal place

Prints -1 if the task sequence cannot be completed

Example Output:

Minimum Runtime: 17.5 seconds
Algorithm Description
The solution uses a greedy simulation approach.

For each task:

Calculate required energy:
energy = duration × drainRate

If required energy exceeds battery capacity, return -1.

If current battery is insufficient:

Calculate missing energy

Charge for the minimum required time

Execute the task and update:

Battery level

Total runtime

Charging is performed only when necessary, ensuring minimum idle time.

This guarantees an optimal solution.

Time and Space Complexity
Time Complexity: O(n)

Space Complexity: O(1)

Where n is the number of tasks.

Assumptions
Battery charging and discharging are continuous.

Charging and drain rates remain constant.

Idle time can be fractional.

All input values are valid and non-negative.

Tasks must be executed in the given order.

Battery level never exceeds its maximum capacity.

Key Design Decisions
Greedy Charging Strategy
Charging is performed only when battery is insufficient to minimize idle time.

Double Precision Arithmetic
double is used to handle fractional charging durations accurately.

Simulation-Based Approach
Battery level and runtime are updated step-by-step for correctness.

Final Rounding
The final result is rounded to one decimal place as required.

Project Structure
battery-runtime-scheduler/
├── src/
│   └── task1.c
├── tests/
│   └── sample_input.txt
└── README.md
Testing
You can test the program using:

./task1 < tests/sample_input.txt
This allows automated testing with predefined inputs.

Limitations
Does not support parallel task execution

Assumes ideal charging and discharging behavior

No hardware-specific power losses considered

Author
MD ABDUL AZEEZ


