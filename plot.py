import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys

collisions = pd.read_csv(sys.argv[1])

plt.figure(figsize = (10, 10))

data = collisions.to_numpy()

print(data)

bins = np.unique(data)

plt.hist(data, bins = bins, color = 'skyblue', edgecolor = 'black')

plt.xscale('log')

plt.xlabel("collision count per bucket")

plt.show()