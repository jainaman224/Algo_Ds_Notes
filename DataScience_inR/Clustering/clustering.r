#Load packages
#cluster: it contains method for Cluster analysis
library(cluster)
#factoextra:Provides some easy-to-use functions to extract and visualize
#the output of multivariate data analyse
library(factoextra)
## Loading required package: ggplot2
## Welcome! Want to learn more? See two factoextra-related books at https://goo.gl/ve3WBa
#Provides implementation of DBSCAN
library(dbscan)
#Provides various Functions for Data Science
library(tidyverse)
## -- Attaching packages ----------------------------------------------------------------- tidyverse 1.3.0 --
## v tibble 3.0.0 v dplyr 0.8.5
## v tidyr 1.0.2 v stringr 1.4.0
## v readr 1.3.1 v forcats 0.5.0
## v purrr 0.3.4
## -- Conflicts -------------------------------------------------------------------- tidyverse_conflicts() --
## x dplyr::filter() masks stats::filter()
## x dplyr::lag() masks stats::lag()
#Data Preprossing
#Load the iris dataset
data("iris")
#The na.omit R function removes all incomplete cases of a data object
iris = na.omit(iris)
#Removing the labels in dataset
d = iris[,1:4]
#Kmeans
#Perform k-means clustering on a data matrix.
#Syntax:kmeans(x, centers, iter.max = 10, nstart = 1,

#algorithm = c("Hartigan-Wong", "Lloyd", "Forgy",
# "MacQueen"), trace=FALSE)
k1 = kmeans(d,centers = 4)
#Provides ggplot2-based elegant visualization of partitioning methods including kmeans
fviz_cluster(k1, data = d,geom = "point")
#Provides the contingency table for iris labels and kmeans clusters
table(iris$Species,k1$cluster)
##
## 1 2 3 4
## setosa 0 0 33 17
## versicolor 48 2 0 0
## virginica 14 36 0 0
cat("The no. of elements in each cluster are",table(k1$cluster))
## The no. of elements in each cluster are 62 38 33 17
#Dbscan
#Calculates k-nearest neighbor distances
# The plot can be used to help find a suitable value for the eps neighborhood for DBSCAN
kNNdistplot(d, k=2) #D is datapoints and K is number of nearest neighbors used
#abline :This function adds one or more straight lines through the current plot.
abline(h=0.55,col="Red")

#Fast reimplementation of the DBSCAN (Density-based spatial clustering of applications with noise)
#clustering algorithm using a kd-tree
db = dbscan(d, eps = 0.55,minPts = 2)
#This function produces a two-dimensional scatter plot with added convex hulls for clusters.
hullplot(d, db$cluster) #Second argument represents the clusters