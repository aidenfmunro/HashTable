import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys


collisions = pd.read_csv(sys.argv[1])

hash_name = collisions.columns[0]

plt.figure(figsize = (10, 10))

data = collisions[1::].to_numpy()

print(data)

bins = np.unique(data)

print(bins)

plt.hist(data, bins = bins, color = 'royalblue')

plt.xscale('log')

plt.ylabel("collision count per bucket")
plt.xlabel(hash_name)


plt.savefig('histograms/' + hash_name + ' (log) ' +'.png')