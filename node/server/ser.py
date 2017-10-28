import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1411', 9600)
time.sleep(1)
ser.setDTR(True)
time.sleep(1)
ser.write('1'.encode())
ser.close() 
