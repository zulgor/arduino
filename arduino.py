import serial
import time
import requests

ser=serial.Serial('COM8',9600,timeout=None)
while True:
    v=ser.readline()
    data=(v.decode("utf-8")).strip()
    try:
        r = requests.get(url='http://20.198.64.187:5000/submit/' + str(int(time.time())) + '-' + data)
    except :
        print("cannot connect")
        exit()




