import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import sys

files = sys.argv[1:]

fig1, ax = plt.subplots(2,2, sharey=True, sharex=True)
fig1.set_size_inches(16,10)
fig1.tight_layout()
fig1.subplots_adjust(left=0.08,bottom=0.08)



row_labels = ['key:string','key:long']
col_labels = ['found in data','not found in data']

for file in files:
    dataset = pd.read_csv(file)
    tag = str(file).removeprefix("outputs/search")
    fig_ax = ax[0,0] if "Long_in" in tag else (ax[0,1] if "Long_not" in tag else (ax[1,0] if "Str_in" in tag else ax[1,1]))
    c = "green" if "HashClosed" in tag else ("yellow" if "HashOpen" in tag else "red")
    label = "AVL-Tree" if "AVL" in tag else ("Open hash table" if "Open" in tag else "Closed hash table")
    alpha = 0.4 if "Open" in tag else (0.6 if "Closed" in tag else 1)
    sns.histplot(data=dataset,
                 x="time[ns]",
                 ax=fig_ax,
                 label=label,
                 color=c,
                 alpha=alpha,
                 binwidth=30)
    fig_ax.legend()
 
for i in range(2):
    fig1.text(0.01, 0.25 + 0.5*i, row_labels[i], va='center', rotation='vertical', fontsize=12)
    fig1.text(0.25 + 0.5*i, 0.01, col_labels[i], ha='center', fontsize=12)


plt.savefig("figures/multi_hist.pdf")
plt.show()