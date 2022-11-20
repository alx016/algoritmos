import random 
import matplotlib.pyplot as plt
import numpy as np

#Equation
x = np.linspace(-2, 0.5, 100)
y = 3*x ** 3 + 6*x**2 - 2*x - 1

aux = input('What are you looking for:\n Higher = 1\tLower=2\n')

m = []
for i in range(len(x)-1):
    m.append((y[i+1] - y[i])/(x[i+1] - x[i]))
# print(m)

if (aux == '1'):
    #higher number 
    list = []
    for i in range(len(x)-1):
        if (m[i-1]>0 and m[i]<0):
            list.append(x[i])
    # print(list)
    list.sort()

elif (aux == '2'):
    #lowest number
    list = []
    for i in range(len(x)-1):
        if (m[i]<0 and m[i+1]>0):
            list.append(x[i])
    # print(list)
    list.sort()
else:
    print('Error, invalid input.')

fig = plt.figure(figsize = (10, 5))
plt.plot(x, y, 'b', label = 'eq')
plt.axvline(list[-1], ls='--', color='r')
plt.show()  
