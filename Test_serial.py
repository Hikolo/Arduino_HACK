import serial
import sys

serial = serial.Serial("/dev/ttyACM0", 9600)
s = [0]
i = 0
while True:
    a = input("What do you want? \n")
    serial.write(a.encode())
    read_serial = serial.readline()
    s[0] = read_serial
    print (read_serial.decode())
    read_serial = serial.readline()
    print (i)
    print (read_serial.decode())
    i += 1
