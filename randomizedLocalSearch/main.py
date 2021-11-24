import math
from Hotel import Hotel
import random
from matplotlib import pyplot as plt
import numpy as np
import names

# Create coordinate grid
fig = plt.figure(figsize=(10, 5))
x_ticks = np.arange(0, 20 + 1, 1)
y_ticks = np.arange(0, 10 + 1, 1)
plt.xticks(x_ticks)
plt.xlim([-1, 21])
plt.yticks(y_ticks)
plt.ylim([-1, 11])
plt.grid(alpha=0.4)

# Create 20 hotel objects, give them random coordinates, load them into an array
hotels = [Hotel("hotel 1", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 2", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 3", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 4", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 5", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 6", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 7", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 8", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 9", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 10", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 11", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 12", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 13", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 14", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 15", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 16", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 17", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 18", random.randint(0, 20), random.randint(0, 10)),
            Hotel("hotel 19", random.randint(0, 20), random.randint(0, 10)), Hotel("hotel 20", random.randint(0, 20), random.randint(0, 10))]

# Plot the 20 hotels at their randomly generated coordinates
for i in range(0, 20):
    plt.scatter(hotels[i].xPt, hotels[i].yPt, color='red', s=100)

# Array to store coordinates for each person
people = []

# plot 150 people at their randomly generated coordinate and load them into an array
for i in range(0, 150):
    xVal = random.randint(0, 20) # Randomize X
    yVal = random.randint(0, 10) # Randomize Y
    plt.scatter(xVal, yVal, color='blue', s=25) # Plot
    people.append((xVal, yVal)) # Add these random points to array

i = 0 # iterates through people
n = 0 # iterates through hotels
while i in range(0, 150):
    # Calculate euclidean distance for all people to all hotels
    eucDistance = math.sqrt((hotels[n].xPt - people[i][0]) ** 2 + (hotels[n].yPt - people[i][1]) ** 2)
    # Each hotel has its distance from each person loaded into an object specific array
    hotels[n].distance.append(eucDistance)

    if i == 149:
        i = -1
        n += 1

    if n == 20:
        break

    i += 1

# Algorithm to identify what hotel is closest to each person
mark = 0
for i in range(0, 150): #iterate through people
    closest = hotels[0].distance[0]
    for n in range(0, 20): #iterate through hotels
        if hotels[n].distance[i] < closest and hotels[n].capacity < 15: #mark what hotel is closest to person i with open rooms
            closest = hotels[n].distance[i]
            mark = n
    hotels[mark].capacity += 1 #add person i to the marked hotel
    print(names.get_full_name(), " at point ", people[i], " is staying at hotel ", (mark+1), " at point ", hotels[mark].coordinate, " current capacity: ", hotels[mark].capacity)
    plt.plot((people[i][0], hotels[mark].coordinate[0]), (people[i][1], hotels[mark].coordinate[1])) # plot line showing where person i will be staying

plt.show()
