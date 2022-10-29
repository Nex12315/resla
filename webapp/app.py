from flask import Flask, render_template
import serial
import time
import picamera

# with serial.Serial("/dev/ttyUSB0", 115200, timeout=1) as esp:
#     time.sleep(0.1)
#     if esp.isOpen():
#         print(f"{esp.port} connected!")
#         try:
#             while True:
#                 cmd = input("Enter command:")
#                 esp.write(cmd.encode())
#                 while esp.inWaiting() == 0:
#                     pass
#                 if esp.inWaiting() > 0:
#                     answer = esp.readline()
#                     print(answer)
#                     esp.flushInput()
#         except KeyboardInterrupt:
#             print("Exiting...")


app = Flask(__name__, template_folder="templates")
LEFT, RIGHT, FORWARD, BACKWARD, STRAIGHT, STOP = "left", "right", 'forward', 'backward', 'straight', "stop"
AVAILABLE_COMMANDS = {
    "Left": LEFT,
    "Right": RIGHT,
    "Forward": FORWARD,
    "Backward": BACKWARD,
    "Straight": STRAIGHT,
    "Stop": STOP
}


@app.route('/')
def execute():
    return render_template("main.html", commands=AVAILABLE_COMMANDS)


@app.route('/<cmd>')
def command(cmd=None):
    # if cmd1 == STRAIGHT:
    #     camera_command = cmd1
    #     response = "Resetting ..."
    # else:
    #     # camera_command = cmd[0].upper()
    #     camera_command = cmd1
    #     response = "Moving {}".format(cmd1.capitalize())
    with serial.Serial("/dev/ttyUSB0", 921600, timeout=1) as esp:
        time.sleep(0.1)
        if esp.isOpen():
            print(f"{esp.port} connected!")
            response = "Moving {}".format(cmd.capitalize())
            try:
                #while True:
                servo_command = cmd
                if servo_command != "":
                    esp.write(servo_command.encode())
                    while esp.inWaiting() == 0:
                        pass
                    if esp.inWaiting() > 0:
                        answer = esp.readline()
                        print(answer)
                        esp.flushInput()
            except KeyboardInterrupt:
                print("Exiting...")
    print(servo_command)
    return response, 200, {'Content-Type': 'text/plain'}

"""
@app.route('/<cmd>')
def command(cmd=None):
     if cmd == STRAIGHT:
         camera_command = "X"
         response = "Resetting ..."
     else:
         camera_command = cmd[0].upper()
         camera_command = cmd
         response = "Moving {}".format(cmd.capitalize())
         if camera_command == STRAIGHT:
             # reset_wheels()
             response = "Moving {}".format(cmd.capitalize())
         elif camera_command == LEFT:
             # turn_left()
             response = "Moving {}".format(cmd.capitalize())
         elif camera_command == RIGHT:
             # turn_right()
             response = "Moving {}".format(cmd.capitalize())
     return response, 200, {'Content-Type': 'text/plain'}
"""

if __name__ == '__main__':
    app.run(debug=True)
