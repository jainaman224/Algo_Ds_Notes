# -*- coding: utf-8 -*-

import pandas as pd
from numpy import log

# Download tennis.csv from Kaggle and then run these commands
#tennis = pd.read_csv('play_tennis.csv')
#tennis

#tennis[tennis.columns[len(tennis.columns)-5]].value_counts()

# Breaking down the calculation behind finding out the most valuable column or the first split in the decision tree

# Function to find entropy of splitting node.
def entropy(yes,no):                  # yes = probability of 'Yes' in this dataset. no = probability of 'No' in this dataset.
    s = yes + no
    if yes == 0:                     # If there are no 'Yes' data.
        return -(no/s*log(no/s))
    elif no == 0:
        return -(yes/s*log(yes/s))
    return -((no/s*log(no/s)) + (yes/s*log(yes/s)))

# Function to find out most valuable column by calculating highest information gain iteratively.
def best_split(data):
    info_gain = []
    yes_count = data[data.columns[len(data.columns)-1]].value_counts()['Yes']   # No. of 'Yes'
    no_count = data[data.columns[len(data.columns)-1]].value_counts()['No']     # No. of 'No'
    parent = entropy(yes = yes_count,no = no_count)               # Calculating the entropy of the 
    for i in data.columns[1:-1]:
        name_list = data.groupby(i).count()[data.columns[len(data.columns)-1]].index.tolist()  # Get the unique indices in a column
        no_list = data.groupby(i).count()[data.columns[len(data.columns)-1]].tolist() # Get the count of each unique index under that column.
        child = 0
        for j in range(len(name_list)):  # Calculate entropy for each child node.
            
            try:
                yes_count1 = data[data[i]==name_list[j]][data.columns[len(data.columns)-1]].value_counts()['Yes']
            except:
                yes_count1 = 0
            try:
                no_count1 = data[data[i]==name_list[j]][data.columns[len(data.columns)-1]].value_counts()['No']
            except:
                no_count1 = 0
            entropy_branch = entropy(yes = yes_count1,no = no_count1)
            weight = no_list[j]/sum(no_list)      # Weight = no. of examples in that branch/total in parent
            child = child + entropy_branch*weight    # Calculating weighted entropy.
        info_gain.append(parent - child)
    print(info_gain)
    return data.columns[info_gain.index(max(info_gain)) + 1]       # Because we ignored the insignificant 'day' column

# Executing on tennis dataset
best_split(tennis)

# A more generalized version of the above algorithm : Finding best_split for a general, random dataset

def entropy(unique):
    s = sum(unique)
    entropy = 0
    for i in unique:
        if i!=0:
            entropy = entropy - i/s*log(i/s)
    return entropy


def best_split(data,feature_cols = None,target = None):
    info_gain = []
    if feature_cols == None:      # If not specified
        feature_cols = data.columns[0:len(data.columns)-1].tolist()     # Takes the entire feature column set without filtering
    if target == None:            # If not specified
        target=X.columns[len(X.columns)-1]                 # Takes the last column only
    label_count = data[target].value_counts()        # Counts no. of unique labels in that column (Frequency of 'Yes' and 'No')
    unique_val_index = label_count.index.tolist()          # Gets a list of indices under target column
    unique_val_count = label_count.tolist()                # Frequency of occurrence of each index under target column.
    parent = entropy(unique_val_count)
    for i in feature_cols:
        name_list = data.groupby(i).count()[target].index.tolist()    # Get the unique indices in a column
        no_list = data.groupby(i).count()[target].tolist()    # Get the count of each unique index under that column.
        child = 0
        for j in range(len(name_list)):
            new_unique_val_count = []
            for k in unique_val_index:           # Basically, for k in ['Yes','No']
                try:
                    count = data[data[i]==name_list[j]][target].value_counts()[k]
                    new_unique_val_count.append(count)
                except:
                    new_unique_val_count.append(0)
            entropy_branch = entropy(new_unique_val_count)
            weight = no_list[j]/sum(no_list)
            child = child + entropy_branch*weight
        info_gain.append(parent - child)
    sort_index = np.argsort(np.array(info_gain)).tolist()
    sort_index.reverse()                   # Reverse the sorted list
    return np.array(feature_cols)[sort_index][0]     # The first column name must be the one with the highest info_gain.

# Testing effectiveness on tennis dataset.
best_split(tennis,['humidity','temp', 'wind','outlook'],'play')

