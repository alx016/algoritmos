import random 
import matplotlib.pyplot as plt
import numpy as np

#Equation
x = np.linspace(-2, 0.5, 100)
y = 3*x ** 3 + 6*x**2 - 2*x - 1

aux = input('What are you looking for:\n Higher = 1\tLower=2\n')

if (aux == '1'):
    #higher number
    greatest = 0
    for i in range(4):
        num = random.randrange(0,100,1)

        while (y[num]<y[num+1]):
            greatest = y[num+1]
            num = num + 1
elif (aux == '2'):
    #lowest number
    greatest = 0
    for i in range(4):
        num = random.randrange(0,100,1)
        print (num)
        while (y[num]>y[num+1]):
            greatest = y[num+1]
            num = num + 1
else:
    print('Error, invalid input.')

fig = plt.figure(figsize = (10, 5))
plt.plot(x, y, 'b', label = 'eq')
plt.axvline(x[num], ls='--', color='r')
plt.show()
