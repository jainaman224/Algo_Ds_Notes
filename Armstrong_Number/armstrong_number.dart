
// dart file

import 'dart:math' as math;

class ArmstrongNumbers {
  bool isArmstrongNumber (int number) {

    num ret = 0;
    int pow = number.toString().length;

    for (int i = 0, j = number; i < pow; i++) {
      ret += math.pow(j % 10, pow);
      j = j ~/ 10;
    }
    
    return ret == number;
  }
}
