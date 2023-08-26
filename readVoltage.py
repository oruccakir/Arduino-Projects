import serial
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from vpython import *
tube = cylinder(color=color.red,radius = 1,length = 5,axis = vector(0,1,0))
lab = label(text = "5 volts",box = False)
arduinoPort = "com7"
arduinoData = serial.Serial(arduinoPort,"9600")
time.sleep(1)


while True:
    while arduinoData.in_waiting== 0:
        pass
    dataPacket = arduinoData.readline()
    dataPacket = str(dataPacket,'utf-8')
    dataPacket = int(dataPacket.strip('\r\n'))
    potVal = dataPacket
    vol = (5./1023.)*potVal
    if(vol == 0):
        vol = 0.01
    tube.length = vol
    vol = round(vol,1)
    lab.text = str(vol)