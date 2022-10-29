import RPi.GPIO as GPIO
import time

servoPin = 12
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPin, GPIO.OUT)

p = GPIO.PWM(servoPin, 50)
             
def turn_right():
    p.start(0)
    try:
        p.ChangeDutyCycle(2.5)
        print("Turning wheels right")
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")

def turn_left():
    p.start(0)
    try:
        p.ChangeDutyCycle(10)
        print("Turning wheels left")
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")

def reset_wheels():
    p.start(0)
    try:
        p.ChangeDutyCycle(7.5)
        print("Straightening wheels")
        time.sleep(1.5)
    except:
        print("Whoops, error with the controls")

def turn_wheels():
    p.start(0)
    for i in range(3):
        p.start(0)
        for j in range(3):
            p.start(0)
            p.ChangeDutyCycle(j * 2.5)
            print(f"Duty cycle is now: {j*2.5}")
            time.sleep(2.5)
            reset_wheels()
        p.ChangeDutyCycle(10 - i * 2.5)
        print(f"Duty cycle is now: {10-i*2.5}")
        time.sleep(2.5)
        reset_wheels()

def test_wheels():
    p.start(0)
    reset_wheels()
    try:
        for dc in range(100):
            p.ChangeDutyCycle(dc)
            time.sleep(0.5)
    except KeyboardInterrupt:
        print("Controls interrupted")
        p.stop()
        GPIO.cleanup()
    except:
        print("Whoops, something wrong with the controls!")
"""
while True:
    p.start(0)
    value = input(">")[0]
    if value == "q": # Stop
        reset_wheels()
    if value == "w": # Forward
        turn_right()
    if value == "s": # Backwards
        turn_left()
    if value == "x":
        break
"""

test_wheels()
p.stop()
GPIO.cleanup()
