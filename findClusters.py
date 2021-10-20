# Algorithms Analysis
# Group Project 2
# Caleb Voorhees

import random
from matplotlib import pyplot
from matplotlib.pyplot import plot
import math


def divide_and_conquer():
    # create arrays for 100 X and Y values and fill each coordinate with a random value between 1 and 250
    xValues = [0] * 100
    for i in range(0, 100):
        xValues[i] = random.randint(1, 250)

    yValues = [0] * 100
    for i in range(0, 100):
        yValues[i] = random.randint(1, 250)

    # Build scatter plot using the randomly generated points
    pyplot.scatter(xValues, yValues)

    # Declare variables to track clusters
    n = 0
    marked = 0  # used to mark the first x and y value

    # Loop through the X and Y values
    while n in range(0, 100):
        # Calculate the euclidean distance between the marked point and all other points on graph
        eucDistance = math.sqrt((xValues[marked] - xValues[n])**2 + (yValues[marked] - yValues[n])**2)
        print(eucDistance)

        # If the marked point is within a euclidean distance of 25 from another point plot out its cluster
        if 25 >= eucDistance > 0:
            clusterXValues = [xValues[marked], xValues[n]]
            clusterYValues = [yValues[marked], yValues[n]]
            plot(clusterXValues, clusterYValues)
        # if marked point has been compared to all other points mark the next point
        if n == 99:
            n = -1
            marked += 1
        # if all points have been marked exit the loop
        if marked == 100:
            break
        # iterator
        n += 1

    # print out how many points are in clusters and show the graph
    pyplot.show()


divide_and_conquer()

