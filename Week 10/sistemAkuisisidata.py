import serial
import csv
ser = serial.Serial('/dev/pts/6', 9600)
ser.flushInput()

while True:
    ser_bytes = ser.readline()
    decode_byte = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    # print(ser_bytes)
    print(decode_byte)
    with open("dataSensor.csv", "a") as file:
        writer = csv.writer(file, delimiter=',')
        writer.writerow([decode_byte])





