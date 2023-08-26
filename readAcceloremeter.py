""""
import serial
import time
arduinoPort = "com7"
arduinoData = serial.Serial(arduinoPort,"9600")
time.sleep(1)
while True:
    while(arduinoData.in_waiting() == 0):
        pass
    dataPacket = arduinoData.readline()
    print(dataPacket)
"""
import serial
import time
arduinoPort = "com7"
arduinoData = serial.Serial(arduinoPort,"9600")
time.sleep(1)
while True:
    while(arduinoData.in_waiting== 0):
        pass
    dataPacket = arduinoData.readline()
    dataPacket = str(dataPacket,'utf-8')
    dataPacket = dataPacket.strip('\r\n')
    dataArray = dataPacket.split(",")
    x = float(dataArray[0])
    y = float(dataArray[1])
    z = float(dataArray[2])

    print("X = ",x," Y = ",y," Z = ",z)