# Microwave Oven Controller

## Overview
This project implements a **microwave oven controller** using an embedded system. The system manages different cooking modes, user input through a matrix keypad, and time control using timers. The display is handled via a character LCD.

## Features
- **Multiple Cooking Modes**: Micro, Grill, and Convection
- **User Interface**:
  - Matrix Keypad for input
  - LCD for displaying menus and status
- **Timers for Time Management**
- **Safety Features**:
  - Door status detection
  - Buzzer alerts

## Components Used
- **Microcontroller**: (Specify the microcontroller model)
- **LCD Display**: Character LCD
- **Matrix Keypad**: 4x3 or 4x4 Keypad
- **Timers**: Timer0 and Timer2 for time tracking
- **Buzzer & Fan**: Controlled via GPIO
- **Door Sensor**: Reads door status for safety

## File Structure


## How It Works
1. **Power On**: The system initializes and displays the power-on screen.
2. **Menu Navigation**: The user selects the cooking mode using the keypad.
3. **Time & Temperature Setting**: The user inputs cooking time and temperature.
4. **Start Cooking**: The system starts the selected mode and counts down the time.
5. **Pause/Stop**: The user can pause or stop cooking at any time.
6. **Buzzer Alerts**: The system beeps at the end of cooking or if an error occurs (e.g., door open).

## Installation & Usage
### Hardware Setup
1. Connect the LCD, keypad, buzzer, fan, and door sensor to the microcontroller.
2. Ensure the power supply is stable.

### Software Compilation
1. Use an **embedded C compiler** (such as MPLAB XC8).
2. Compile and upload the firmware to the microcontroller.

### Operation
1. Power on the system.
2. Use the keypad to select the mode and set cooking parameters.
3. Press "Start" to begin cooking.
4. Monitor the display for status updates.
5. Press "Stop" to cancel the operation if needed.

## Future Enhancements
- Add **touch-based** controls.
- Implement **Wi-Fi/Bluetooth** connectivity for remote operation.
- Introduce **automatic weight-based cooking**.

## License
This project is open-source under the **MIT License**. Feel free to modify and distribute.

---

Let me know if you want any modifications! 🚀
