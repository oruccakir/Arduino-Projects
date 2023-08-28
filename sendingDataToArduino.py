import serial
arduinoData = serial.Serial("com7",9600)

while True:
    cmd = input("Please enter your command : ")
    cmd = cmd+'\r'
    arduinoData.write(cmd.encode())