# Stepper Motor Interfacing with Raspberry Pi

## Problem Statement
Design a system to interface a stepper motor with a Raspberry Pi for precise motor control, with proper communication, power management and step sequence execution.

## Aim
To design a system that interfaces a stepper motor with a Raspberry Pi for precise motor control, with proper communication, power management and step sequence execution.

## Components
| Component | Quantity |
|-----------|----------|
| Raspberry Pi (any model with a 40-pin header) | 1 |
| 28BYJ-48 stepper motor (5V) | 1 |
| ULN2003 driver board | 1 |
| External 5V power supply (at least 500 mA) | 1 |
| Jumper wires | as needed |

## Connections
| ULN2003 pin | Raspberry Pi |
|-------------|--------------|
| IN1 | GPIO17 (physical pin 11) |
| IN2 | GPIO18 (physical pin 12) |
| IN3 | GPIO27 (physical pin 13) |
| IN4 | GPIO22 (physical pin 15) |
| GND | GND (common ground with the external supply) |
| +5V | External 5V supply (+) |

## Communication
The Raspberry Pi sends digital HIGH/LOW signals on four GPIO pins. The ULN2003 (a Darlington transistor array) amplifies these signals to drive the four motor coils.

## Power management
- The motor draws more current than a GPIO pin can supply (a pin gives only a few mA), so the **ULN2003 board is powered from an external 5V supply, not from the Pi's pins**.
- The external supply's **GND must be connected to the Pi's GND** (common ground), or the signals will not work.
- After every move, all coils are switched off (`release_coils()`) so the motor and driver do not heat up and no power is wasted.

## Step sequence
The program uses the **half-step sequence** (8 phases), which gives smoother motion and finer resolution than full-step.

| Phase | IN1 | IN2 | IN3 | IN4 |
|-------|-----|-----|-----|-----|
| 1 | 1 | 0 | 0 | 0 |
| 2 | 1 | 1 | 0 | 0 |
| 3 | 0 | 1 | 0 | 0 |
| 4 | 0 | 1 | 1 | 0 |
| 5 | 0 | 0 | 1 | 0 |
| 6 | 0 | 0 | 1 | 1 |
| 7 | 0 | 0 | 0 | 1 |
| 8 | 1 | 0 | 0 | 1 |

- Going through the phases in order (1 to 8) turns the shaft clockwise. Going in reverse order turns it anticlockwise.
- The 28BYJ-48 needs **4096 half-steps** for one full revolution (including its 1:64 gearbox), so `steps = angle / 360 x 4096`.
- The delay between steps (default 1 ms) sets the speed. Going below 1 ms can make the motor skip steps.

## Working
1. GPIO pins are set up as outputs, all LOW.
2. The user picks an option from the menu: rotate clockwise or anticlockwise by an angle, one full revolution, or set the speed.
3. The angle is converted to a number of steps and the sequence is executed step by step.
4. The coils are released after the move.
5. On exit (or Ctrl+C), the coils are switched off and `GPIO.cleanup()` is called.

## How to run
1. Make the connections as per the table above and power the ULN2003 board from the external 5V supply.
2. Copy `stepper_motor_raspberry_pi.py` to the Raspberry Pi.
3. Run:
   ```
   python3 stepper_motor_raspberry_pi.py
   ```
4. Choose an option from the menu and watch the shaft rotate.

## Sample output
```
Stepper Motor Control (28BYJ-48 + ULN2003)

1. Rotate clockwise by angle
2. Rotate anticlockwise by angle
3. One full revolution (clockwise)
4. Set speed (step delay in ms)
5. Exit
Enter choice: 1
Angle in degrees: 90
Rotating 90.0 degrees clockwise (1024 steps)
Done.
```
