import serial
# import PRi.GPIO as GPIO
import time

port = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)

def reset_wheels():
    try:
        port.write(98)
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")


def turn_right():
    try:
        port.write(108)
        time.sleep(0.5)
    except:
        print("Whoops, error with the controls")


def turn_left():
    try:
        port.write(100)
        time.sleep(0.5)
    except:
        print("WHoops, error with the controls")


while True:
    value = input("Input something  ")
    if value == "a":
        turn_left()
    elif value == "s":
        reset_wheels()
    elif value == "d":
        turn_right()
    elif value == "f":
        port.write(98)
        print(port.read())
    elif value == "x":
        break

