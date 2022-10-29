import RPi.GPIO as GPIO
import time

servoPin = 21
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPin, GPIO.OUT)

p = GPIO.PWM(servoPin, 50)

p.start(0)

def turn_right():
    reset_wheels()
    try:
        p.ChangeDutyCycle(2.5)
        print("Turning wheels right")
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")

def turn_left():
    reset_wheels()
    try:
        p.ChangeDutyCycle(10)
        print("Turning wheels left")
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")

def reset_wheels():
    try:
        p.ChangeDutyCycle(7.5)
        print("Straightening wheels")
        time.sleep(1.5)
    except:
        print("Whoops, error with the controls")
"""
def test_wheels():
    p.start(0)
    reset_wheels()
    try:
        p.ChangeDutyCycle(12.5)
        print("Duty cycle is now: 12.5")
        time.sleep(2.5)
    except:
        print("Whoops, something wrong with controls")
"""

p.stop()
GPIO.cleanup()
