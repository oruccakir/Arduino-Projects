
import serial
import time
try:
    from vpython import *
except ZeroDivisionError:
    print()

com = 'COM7'
arduinoData = serial.Serial(com,"9600")

# Sahneyi oluştur
scene = canvas(title='Küre Hareketi', width=1500, height=1500)

# Küreyi oluştur
ball = sphere(pos=vector(0, 0, 0), radius=0.4, color=color.blue)

# Hareket hızı
move_speed = 0.1

time.sleep(1)

prevx = 528
prevy = 511

while True:
    while arduinoData.in_waiting == 0:
        pass

    dataPacket = arduinoData.readline()
    dataPacket = str(dataPacket,"utf-8")
    dataPacket = dataPacket.strip("\r\n")
    dataArray = dataPacket.split(",")
    x = dataArray[0]
    y = dataArray[1]
    x = float(x)
    y = float(y)
    print("X : ",x," Y : ",y)
    rate(60)  # Sahneyi 60 FPS hızında güncelle
    if(y>prevy):
        ball.pos.x -= move_speed
    elif(y < prevy):
        ball.pos.x += move_speed

    if(x>prevx):
        ball.pos.y -= move_speed
    elif(x < prevx):
        ball.pos.y += move_speed
    
    prevx = x
    prevy = y
