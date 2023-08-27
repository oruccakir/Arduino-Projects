import serial
from vpython import *
import time
arduinoData = serial.Serial("COM7","9600")
time.sleep(1)

bulb = sphere(radius = 1, color = color.red)
cyl = cylinder(radius = .75, color = color.red,axis = vector(0,1,0),length = 6)

while True:
    while arduinoData.in_waiting == 0:
        pass
    dataPacket = arduinoData.readline()
    dataPacket = str(dataPacket,'utf-8')
    dataPacket = dataPacket.strip('\r\n')
    dataArray = dataPacket.split(",")
    temperature = float(dataArray[0])
    humidity = float(dataArray[1])
    print("Temperature : ",temperature)
    print("Humidity : ",humidity)
    len = (4.5/115)*temperature +1.5
    cyl.length = len