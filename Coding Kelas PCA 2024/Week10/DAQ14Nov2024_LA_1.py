import serial
import csv
import time
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('/dev/pts/2', 9600)
ser.flushInput()

plot_window = 50
y_var = np.array(np.zeros([plot_window]))

plt.ion()
fig, ax = plt.subplots()
line , = ax.plot(y_var)

while True:
    data=ser.readline()
    decoded_data = float(data[0:len(data)-2].decode("utf-8"))
    print(decoded_data)

    with open('data.csv', mode='a') as data_file:
        writer = csv.writer(data_file,delimiter=',')
        writer.writerow([time.time(),decoded_data])

    y_var = np.append(y_var,decoded_data)
    y_var = y_var[1:plot_window+1]
    line.set_ydata(y_var)
    ax.relim()
    ax.autoscale_view()
    fig.canvas.draw()
    fig.canvas.flush_events()


