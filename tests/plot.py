import numpy as np
import matplotlib.pyplot as plt

sol = np.loadtxt("solution.txt")
grid = np.loadtxt("grid.txt")

plt.plot(grid, sol)
plt.savefig("plot.png")