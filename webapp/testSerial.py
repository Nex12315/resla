import serial, time

print("Running")

with serial.Serial("/dev/ttyUSB0", 115200, timeout=1) as esp:
    time.sleep(0.1)
    if esp.isOpen():
        print(f"{esp.port} connected!")
        try:
            while True:
                cmd = input("Enter command:")
                esp.write(cmd.encode())
                while esp.inWaiting() == 0:
                    pass
                if esp.inWaiting() > 0:
                    answer = esp.readline()
                    print(answer)
                    esp.flushInput()
        except KeyboardInterrupt:
            print("Exiting...")
