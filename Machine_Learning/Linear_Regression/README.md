# Linear Regression

## Brief Introduction

In the most layman terms, regression in general is to predict the outcome in the best possible way given the past data and its corresponding past outcomes.

In simplest terms, Linear regression is fitting data by a straight line ```y = mx + c``` ( highest power of x is one )

What linear regression does is simply tell us the value of the dependent variable for an arbitrary independent/explanatory variable. e.g. Twitter revenues based on number of Twitter users.

![Linear Regression](https://miro.medium.com/max/640/1*LEmBCYAttxS6uI6rEyPLMQ.png)

## Regression

Regression is a method of modeling a target value based on independent predictors. This method is mostly used for forecasting and finding out cause and effect relationship between variables.

Regression techniques mostly differ based on the number of independent variables and the type of relationship between the independent and dependent variables.

![Regression](https://uc-r.github.io/public/images/analytics/regression/sq.errors-1.png)

## Technical Aspect Of Linear Regression

Linear Regression is a Machine Learning algorithm that is used to predict the value of a quantitative variable.

Simple linear regression is actually a basic regression analysis where we have just 2 variables, an independent variable and a dependent variable. Based on the changes made to the independent variable, we predict the value of the dependent variable.

From a machine learning context, it is the simplest model one can try out on your data. If you have a hunch that the data follows a straight line trend, linear regression can give you quick and reasonably accurate results.

Visually, linear regression is a process of finding a flat shape that best fits in the cloud of observed data. The shape could be a point on the axis, a line in two dimensions, a plane in three dimensions, or a hyperplane in higher dimensions. Using linear regression to calculate a single point on an axis that is a best fit is the same as calculating the average.

## How We Do Linear regression

- We plot our dependent variable (y-axis) against the independent variable (x-axis)
- We try to plot a straight line and measure correlation
- We keep changing the direction of our straight line until we get the best correlation
- We extrapolate from this line to find new values on y-axis

## Equations For Linear Regression

### General Form

Y  = α<sub>0</sub>x<sub>0</sub> +  α<sub>1</sub>x<sub>1</sub> +  α<sub>2</sub>x<sub>2</sub> +  α<sub>3</sub>x<sub>3</sub> +  α<sub>4</sub>x<sub>4</sub> + ...

### For A Single Independent variable

Y  = α<sub>0</sub>x<sub>0</sub> +  α<sub>1</sub>x<sub>1</sub>

## Calculations

For the equation ```Y = a + bx```, where **Y** is dependent variable and **x** is independent variable.

The variables **a** and **b** are calculated as

![Equation](https://www.statisticshowto.datasciencecentral.com/wp-content/uploads/2009/11/linearregressionequations.bmp)

![Explanation](https://miro.medium.com/max/1728/1*CjTBNFUEI_IokEOXJ00zKw.gif)

## Core Components In Simple Linear Regression

- Continuous input variable
- Continuous response variable.
- The assumptions of linear regression being meet.

## Assumptions Of Linear Regression

- Linear association between input and output variable
- Normally distributed errors  
- Independence of error term with input.

## Pseudocode

```
1. START

2. Read Number of Data (n)

3. REPEAT for i ← 1 to n:
     Read Xi and Yi

4. Initialize:
     sumX ← 0
     sumX2 ← 0
     sumY ← 0
     sumXY ← 0

5. Calculate Required Sum

   REPEAT for i ← 1 to n:
     sumX ← sumX + Xi
     sumX2 ← sumX2 + Xi * Xi
     sumY ← sumY + Yi
     sumXY ← sumXY + Xi * Yi
   INCREMENT i

6. Calculate Required Constants m and c of y = c + mx:

   m ← (n * sumXY - sumX * sumY)/(n*sumX2 - sumX * sumX)
   c ← (sumY - b*sumX)/n

7. Display the values of m and c

8. STOP

```

## Linear Regression Using Least Square Method

```
1. Form normal equations:
     ∑y = nc + m∑x
     ∑xy = c∑x + m∑x2

2. Solve normal equations as simultaneous equations for m and c

3. Substitute the value of a and b in
   y = c + mx which is required line of best fit.
```

## A Glimpse Of Cost Function

The cost function helps us to figure out the best possible values for **m** and **c** which would provide the best fit line for the data points. Since we want the best values for **m** and **c**, we convert this search problem into a minimization problem where we would like to minimize the error between the predicted value and the actual value.

![Equation](https://miro.medium.com/max/608/1*wQCSNJ486WxL4mZ3FOYtgw.png)

We choose the above function to minimize. The difference between the predicted values and ground truth measures the error difference. We square the error difference and sum over all data points and divide that value by the total number of data points. This provides the average squared error over all the data points. Therefore, this cost function is also known as the Mean Squared Error(MSE) function. Now, using this MSE function we are going to change the values of **m** and **c** such that the MSE value settles at the minima.

## A Look On Gradient Descent

Gradient descent is a method of updating **m** and **c** to reduce the cost function(MSE). The idea is that we start with some values for **m** and **c** and then we change these values iteratively to reduce the cost. Gradient descent helps us on how to change the values.

![Gradient Descent](https://miro.medium.com/proxy/0*QwE8M4MupSdqA3M4.png)

To draw an analogy, imagine a pit in the shape of U and you are standing at the topmost point in the pit and your objective is to reach the bottom of the pit. There is a catch, you can only take a discrete number of steps to reach the bottom.

If you decide to take one step at a time you would eventually reach the bottom of the pit but this would take a longer time. If you choose to take longer steps each time, you would reach sooner but, there is a chance that you could overshoot the bottom of the pit and not exactly at the bottom.

In the gradient descent algorithm, the number of steps you take is the learning rate. This decides on how fast the algorithm converges to the minima.

## Visualization

![Visualization](https://forums.fast.ai/uploads/default/original/2X/7/788e1a31f23e07b9c77fc93573970c2a9b4668c7.gif)

## Major Uses Of Regression analysis

Three major uses for regression analysis are
- Determining the strength of predictors
- Forecasting an effect  
- Trend forecasting.

First, the regression might be used to identify the strength of the effect that the independent variable(s) have on a dependent variable. Typical examples are the strength of relationship between dose and effect, sales and marketing spending, or age and income.

Second, it can be used to forecast effects or impact of changes. That is, the regression analysis helps us to understand how much the dependent variable changes with a change in one or more independent variables. A typical example is, “How much additional sales income do I get for each additional $1000 spent on marketing?”

Third, regression analysis predicts trends and future values. The regression analysis can be used to get point estimates. A typical question is, “What will the price of gold be in 6 months?”

![Analysis](https://bioinfo.iric.ca/wpbioinfo/wp-content/uploads/2017/08/training.gif)

## Real World Applications Of Simple Linear Regression

- Linear Regression can be used to predict the sale of products in the future based on past buying behaviour.
- Economists use Linear Regression to predict the economic growth of a country or state.
- Sports analyst use linear regression to predict the number of runs or goals a player would score in the coming matches based on previous performances.
- An organization can use linear regression to figure out how much they would pay to a new joinee based on the years of experience.
- Linear regression analysis can help a builder to predict how much houses it would sell in the coming months and at what price.
- Petroleum prices can be predicted using Linear Regression.
- Housing price prediction: A builder can predict the price of a house based on features like the area of the house in square feet, number of bedrooms, the area in which the house is located, etc. He can also estimate the number of house it can sell based on past data.

## Conclusion

Linear Regression is an algorithm that every Machine Learning enthusiast must know and it is also the right place to start for people who want to learn Machine Learning as well. It is really a simple but useful algorithm.
