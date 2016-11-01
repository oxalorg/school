import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
def animate(i):
    pullData = open("RoundRobin.log","r").read()
    dataArray = pullData.split('\n')
    xar = []
    yar = []
    for eachLine in dataArray:
        if len(eachLine)>1:
            x,y = eachLine.split(',')
            xar.append(float(x))
            yar.append(float(y))
    ax1.clear()
    ax1.plot(xar,yar)
ani = animation.FuncAnimation(fig, animate, interval=10000000000)
plt.xlabel('Time Slice')
plt.ylabel('Average Turn Around Time')
plt.title('Relation of TurnAroundTime and TimeSlice in RoundRobin')
plt.show()
