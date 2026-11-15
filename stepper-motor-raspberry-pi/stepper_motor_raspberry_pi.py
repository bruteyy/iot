"""
Interface a Stepper Motor with Raspberry Pi
Motor   : 28BYJ-48 (5V unipolar stepper)
Driver  : ULN2003 driver board
Language: Python 3 (RPi.GPIO)

Connections (BCM numbering):
    ULN2003 IN1 -> GPIO17 (physical pin 11)
    ULN2003 IN2 -> GPIO18 (physical pin 12)
    ULN2003 IN3 -> GPIO27 (physical pin 13)
    ULN2003 IN4 -> GPIO22 (physical pin 15)
    ULN2003 GND -> Raspberry Pi GND (common ground)
    ULN2003 +5V -> External 5V supply (NOT the Pi 5V pin)
"""

import time
import RPi.GPIO as GPIO

# ---------------- Configuration ----------------
IN_PINS = [17, 18, 27, 22]      # IN1, IN2, IN3, IN4 (BCM numbers)
STEPS_PER_REV = 4096            # half-step mode, 28BYJ-48 (with 1:64 gearbox)
step_delay = 0.001              # seconds between steps (speed control)

# Half-step sequence: 8 phases, gives smoother motion and finer resolution
HALF_STEP_SEQ = [
    [1, 0, 0, 0],
    [1, 1, 0, 0],
    [0, 1, 0, 0],
    [0, 1, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 1, 1],
    [0, 0, 0, 1],
    [1, 0, 0, 1],
]

phase = 0   # remembers the current position in the sequence


def setup():
    """Configure GPIO pins as outputs and switch all coils off."""
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    for pin in IN_PINS:
        GPIO.setup(pin, GPIO.OUT)
        GPIO.output(pin, GPIO.LOW)


def release_coils():
    """Switch all coils off to avoid heating and save power."""
    for pin in IN_PINS:
        GPIO.output(pin, GPIO.LOW)


def step_motor(steps, clockwise=True):
    """Execute the given number of half-steps in the chosen direction."""
    global phase
    direction = 1 if clockwise else -1
    for _ in range(steps):
        phase = (phase + direction) % len(HALF_STEP_SEQ)
        for pin, value in zip(IN_PINS, HALF_STEP_SEQ[phase]):
            GPIO.output(pin, value)
        time.sleep(step_delay)
    release_coils()


def rotate_angle(angle, clockwise=True):
    """Rotate the shaft by an angle in degrees."""
    steps = int(round(angle / 360.0 * STEPS_PER_REV))
    direction = "clockwise" if clockwise else "anticlockwise"
    print(f"Rotating {angle} degrees {direction} ({steps} steps)")
    step_motor(steps, clockwise)
    print("Done.")


def read_number(prompt):
    """Read a positive number from the user."""
    try:
        value = float(input(prompt))
        if value <= 0:
            raise ValueError
        return value
    except ValueError:
        print("Invalid input. Enter a number greater than 0.")
        return None


def main():
    global step_delay
    setup()
    print("Stepper Motor Control (28BYJ-48 + ULN2003)")
    try:
        while True:
            print("\n1. Rotate clockwise by angle")
            print("2. Rotate anticlockwise by angle")
            print("3. One full revolution (clockwise)")
            print("4. Set speed (step delay in ms)")
            print("5. Exit")
            choice = input("Enter choice: ").strip()

            if choice == "1":
                angle = read_number("Angle in degrees: ")
                if angle:
                    rotate_angle(angle, True)
            elif choice == "2":
                angle = read_number("Angle in degrees: ")
                if angle:
                    rotate_angle(angle, False)
            elif choice == "3":
                rotate_angle(360, True)
            elif choice == "4":
                delay_ms = read_number("Step delay in ms (minimum 1): ")
                if delay_ms:
                    step_delay = max(delay_ms, 1) / 1000.0
                    print(f"Step delay set to {step_delay * 1000:.0f} ms")
            elif choice == "5":
                break
            else:
                print("Invalid choice.")
    except KeyboardInterrupt:
        print("\nStopped by user.")
    finally:
        release_coils()
        GPIO.cleanup()
        print("GPIO cleaned up. Bye!")


if __name__ == "__main__":
    main()
