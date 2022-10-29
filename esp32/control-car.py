import serial

ser = serial.Serial("/dev/ttyUSB0", 115200)

while True:
    value = input("Type command: ")
    value = value[0]
    value = ord(value)
    try:
        ser.write(value)
    except:
        print("Could not write to serial!")

    if value == ord("x"):
        break

