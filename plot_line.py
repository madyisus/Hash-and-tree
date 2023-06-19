import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import sys

files = sys.argv[1:]

fig = plt.figure(0,figsize=(12,6))
ax = fig.add_subplot(111)

for file in files:
    data = pd.read_csv(file,header=0)
    tag = str(file).removeprefix("outputs/insertion").removesuffix("_results.csv")
    linestyle = "-" if "Str" in tag else "-."
    color = "red" if "AVL" in tag else ("blue" if "Open" in tag else "green")
    data.plot(ax=ax,
              x="n",
              y="time[ms]",
              ls = linestyle,
              color = color,
              marker = "s",
              ms=3,
              label=tag)

ax.set_ylabel("time [ms]")
fig.tight_layout()
plt.legend()
plt.show()
