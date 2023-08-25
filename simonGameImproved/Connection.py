
import serial



# Replace 'COMX' with the actual COM port your Arduino is connected to
arduino_port = 'COM7'  

# Serial communication setup
ser = serial.Serial(arduino_port, 9600)  # Make sure the baud rate matches the Arduino code

try:
    while True:
        data = ser.readline().decode().strip()  # Read data from the serial port
        print("Received:", data)  # Process or display the received data as needed
except KeyboardInterrupt:
    ser.close()  # Close the serial communication






