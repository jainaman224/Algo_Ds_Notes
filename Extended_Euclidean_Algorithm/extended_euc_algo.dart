/* Extended Euclidean Algorithm 
  ==============================
  GCD of two numbers is the largest number that divides both of them.
  A simple way to find GCD is to factorize both numbers and multiply
  common factors.
  
     GCD(a,b) = ax + by
  If we can find the value of  x and y then we can easily find the 
  value of GCD(a,b) by replacing (x,y) with their respective values.
*/

void main(){
    int x = 0, y = 0, a = 98, b = 21;
    // function called for 98 and 21
    print(gcdFunction(a, b, x, y));
}

int gcdFunction(a,b,x,y){
    if (a == 0){
        x = 0;
        y = 0;
        return b;
    }
    int x1 = 0, y1 = 0;
    int gcd = gcdFunction(b % a, a, x1, y1);
    x = y1 - (b / a).round() * x1;
    y = x1;
    
    return gcd;

    
}


