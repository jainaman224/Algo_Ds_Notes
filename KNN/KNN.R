file <- readline(prompt = "Enter file link : ")
#http://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data
Iris_Data = read.csv(file, header = FALSE)
Iris_Data = Iris_Data[1:100, ]
names(Iris_Data) = c("sepal_length",
                     "sepal_width",
                     "petal_length",
                     "petal_width",
                     "species")


train_size = floor(0.50 * nrow(Iris_Data))
set.seed(1223)
train_index = sample(1:nrow(Iris_Data), size = train_size)

train_sample = Iris_Data[train_index, ]
test_sample = Iris_Data[-train_index, ]
train_label = train_sample[, 5]


# distance calculation method
distance <- function(train, test) {
  dist = 0
  
  for (i in 2:ncol(train) - 1) {
    dist = dist + (train[, i] - test[, i]) ^ {
      2
    }
  }
  return(sqrt(dist))
}


# KNN Method
KNN <- function(test, N) {
  dist_array = data.frame()
  for (i in 1:nrow(train_sample)) {
    dist_array[i, 1] = distance(train_sample[i, ], test[1, ])
    dist_array[i, 2] = train_index[i]
    
  }
  dist_array = dist_array[order(dist_array$V1), ]
  print(dist_array)
  labels = data.frame()
  for (i in 1:N) {
    labels[i, 1] = Iris_Data[dist_array[i, 2], 5]
    
  }
  table_data = table(labels)
  new_label = names(table_data)[which(table_data == max(table_data))]
  return(new_label)
}

test_data = test_sample[37, ]          # any random test sample
new_label = KNN(test_data, 25)         # 25 nearest neighbours
new_label                             # print the predicted new label
test_data[, 5] = new_label             # assign the predicted label
