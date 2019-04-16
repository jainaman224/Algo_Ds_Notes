## Bisection Method
In mathematics, the bisection method is a root-finding method that applies to any continuous functions for which one knows two values with opposite signs. The method consists of repeatedly bisecting the interval defined by these values and then selecting the subinterval in which the function changes sign, and therefore must contain a root.
## Steps

* The Bisection Method is given an initial interval [a..b] that contains a root
(We can use the property sign of f(a) ≠ sign of f(b) to find such an initial interval)
* The Bisection Method will cut the interval into 2 halves and check which half interval contains a root of the function
* The Bisection Method will keep cut the interval in halves until the resulting interval is extremely small
* The root is then approximately equal to any value in the final (very small) interval.

### Example:
Suppose the interval [a..b] is as follows:
 
 ![](https://github.com/p-rit/Images/blob/master/Bisection_method_images/1.PNG )

We cut the interval [a..b] in the middle: m = (a+b)/2
 
 ![](https://github.com/p-rit/Images/blob/master/Bisection_method_images/2.PNG )

Because sign of f(m) ≠ sign of f(a) , we proceed with the search in the new interval [a..b]:

 ![](https://github.com/p-rit/Images/blob/master/Bisection_method_images/3.PNG )

We can use this statement to change to the new interval:

    b = m;        

In the above example, we have changed the end point b to obtain a smaller interval that still contains a root
In other cases, we may need to changed the end point b to obtain a smaller interval that still contains a root

Here is an example where you have to change the end point a:

Initial interval [a..b]:

 ![](https://github.com/p-rit/Images/blob/master/Bisection_method_images/4.PNG )
 
After cutting the interval in half, the root is contained in the right-half, so we have to change the end point a:

 ![](https://github.com/p-rit/Images/blob/master/Bisection_method_images/5.PNG )

## Pseudocode


    Given: interval [a..b] such that: sign of f(a) ≠ sign of f(b)     

    repeat (until the interval [a..b] is "very small")
   
    {
           a+b
        m = -----;      // m = midpoint of interval [a..b]
            2

      if ( sign of f(m) ≠ sign of f(b) )
      {
         use interval [m..b]  in the next iteration(i.e.: replace a with m)
      }
      else
      {
         use interval [a..m]  in the next iteration (i.e.: replace b with m)
      }
     }

    Approximate root = (a+b)/2;    (any point between [a..b] will do because the interval [a..b] is very small)  

## References
* [Bisection Method](https://en.wikipedia.org/wiki/Bisection_method)
* [Lecture notes](http://www.mathcs.emory.edu/~cheung/Courses/170/Syllabus/07/bisection.html)
