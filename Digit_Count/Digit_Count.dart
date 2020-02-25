import 'dart:io';

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

  print("Enter Number: ");
  var num = stdin.readLineSync();
  int x = int.parse(num);
  CountDigit(x);
}