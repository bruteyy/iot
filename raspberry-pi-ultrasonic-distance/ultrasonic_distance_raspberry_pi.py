import RPi.GPIO as GPIO
import time

# GPIO pin numbers using BCM numbering
TRIG = 23
ECHO = 24

GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIG, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)

try:
    print("Ultrasonic Distance Measurement Started")

    while True:
        # Ensure trigger is LOW before sending a pulse
        GPIO.output(TRIG, False)
        time.sleep(0.05)

        # Send a 10 microsecond trigger pulse
        GPIO.output(TRIG, True)
        time.sleep(0.00001)
        GPIO.output(TRIG, False)

        # Wait for the echo pulse to start, with timeout
        pulse_start = time.time()
        timeout = pulse_start + 0.03
        while GPIO.input(ECHO) == 0 and time.time() < timeout:
            pulse_start = time.time()

        # Wait for the echo pulse to end, with timeout
        pulse_end = time.time()
        timeout = pulse_end + 0.03
        while GPIO.input(ECHO) == 1 and time.time() < timeout:
            pulse_end = time.time()

        # Calculate distance if a valid echo was received
        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150

        if distance > 0 and distance <= 400:
            print("Distance: {:.2f} cm".format(distance))
        else:
            print("No valid distance detected")

        time.sleep(0.5)

except KeyboardInterrupt:
    print("\nMeasurement stopped by user")

finally:
    GPIO.cleanup()
