

CountDigit(int Num) {
  int ans = 0;
  var temp = Num;
  while(Num != 0) {
    ans++;
    Num = Num~/10;     // if you use Num/10 it will throw error on runtime
  }
  print('$temp has $ans Digits');
}


void main() { 
  
  CountDigit(6789);
}