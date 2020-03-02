//Simpson's Rule in c++
//It is used to calculate numerical approximation of definite integral
//In this rule, number of intervals must be EVEN

#include <iostream>
using namespace std;

//Function to calculate f(x) where f(x) = x * x
float func(float x){
    return x*x;
}

//Function to calculate approximate integral
float simpsons (float lb, float ub, int n){
    float h = (ub - lb) / n;
    float result = 0;
    for (int i = 0; i <= n; i++){
        if(i == 0 || i == n)
            result = result + func(lb + i * h);
        else if( i % 2 != 0)
            result = result + 4 * func(lb + i * h);
        else
            result = result + 2 * func(lb + i * h);
    }
    result = result * (h / 3);
    return result;
}

int main() {
    float lower_limit, upper_limit, output;
    int intervals;
    cout << "Enter lower limit = ";
    cin >> lower_limit;
    cout << "Enter upper limit = ";
    cin >> upper_limit;
    cout<< "Enter number of intervals = ";
    cin >> intervals;
    if(intervals % 2 == 0){
        output = simpsons(lower_limit, upper_limit, intervals);
        cout << "Output = " << output;
    }
    else
        cout << "Interval must be even.";
    return 0;
}

//output -
//Enter lower limit = 4
//Enter upper limit = 5.2
//Enter number of intervals = 6
//Output = 25.536
