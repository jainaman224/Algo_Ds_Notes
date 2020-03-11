from numpy import mean,std,cov
from numpy.linalg import eig
import scipy.linalg as la
import numpy as np
import pandas
from sklearn.model_selection import train_test_split   # Data splitting for train and test
from sklearn.preprocessing import StandardScaler   # Scaling the data



class PCA:
    # Initialize
    def __init__(self, n_components=None, whiten=False):
        self.n_components = n_components
        self.whiten = bool(whiten)

    # .fit()
    def fit(self, X):
        r,c = X.shape

       # Subtracting mean to center the data/Mean normalization
        self.mn = mean(X,axis=0)
        X = X - self.mn

        # Feature scaling if necessary
        if self.whiten:
            self.stdv = std(X,axis=0)
            X = X/self.stdv

        # MAIN : PERFORMING SVD/EIGEN DECOMPOSITION OF X
        # Step 1:
        A = np.array(X)
        C = cov(A.T)        # Calculating covariance matrix

        # Calculating eigen values and eigen vectors
        self.eigval, self.eigvect = eig(C)

        # Step 2:
        # Truncating for dimensionality reduction
        if self.n_components is not None:
            self.eigval = self.eigval[:self.n_components]
            self.eigvect = self.eigvect[:, :self.n_components]

        # Step 3:
        # Sorting the eigen values and vectors in descending order
        desc_ord = np.flip(np.argsort(self.eigval))    # Indices returned are for ascending order. Flipping to return indices in descending order.
        self.eigval = self.eigval[desc_ord]
        self.eigvect = self.eigvect[:, desc_ord]
        
        return self

    # Transforming the original matrix(of features) to the reduced form.
    # .transform()
    def transform(self, X):
         X = X - self.mn
         if self.whiten:
             X = X/self.stdv
         return X @ self.eigvect           # Step 4

    # Defining the property explained_variance_ratio. This is not a method
    # .explained_variance_ratio
    @property
    def variance_ratio(self):
        return (self.eigval/np.sum(self.eigval))*100   # How much each eigen value contributes to the variance in the data.

# Test
# Input - Output :

# Input
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'Class']
dataset = pd.read_csv(url, names=names)
X = dataset.drop('Class', 1)      # Features
y = dataset['Class']       # Labels

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)


pca = PCA(whiten=True)     
X_train = pca.fit(X_train)
X_train = pca.transform(X_train)
X_test = pca.transform(X_test)
explained_variance = pca.variance_ratio
print(explained_variance)

# Output
'''
0.722265
0.239748
0.0333812
0.0046056'''
