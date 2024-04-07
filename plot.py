import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys

collisions = pd.read_csv(sys.argv[1])

plt.figure(figsize = (10, 10))

data = collisions.to_numpy()

print(data)

plt.hist(data, bins = 'auto', log = True)

plt.show()
