import serial
import time
import csv
import matplotlib
matplotlib.use("tkAgg")
import matplotlib.pyplot as plt
import numpy


ser = serial.Serial('/dev/pts/2', 9600)
ser.flushInput()

plot_window = 50
y_var = numpy.array(numpy.zeros([plot_window]))

plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(y_var)

while True:
    try:
        data = ser.readline()
        decoded_data=float(data[0:len(data)-2].decode("utf-8"))
        print(decoded_data)
        with open("test_data_3.csv","a") as f:
            writer = csv.writer(f, delimiter=",")
            writer.writerow([time.time(), decoded_data])
        
        y_var = numpy.append(y_var,decoded_data)
        y_var = y_var[1:plot_window+1]
        line.set_ydata(y_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
    except:
        print("Keyboard Interrupt")
        break