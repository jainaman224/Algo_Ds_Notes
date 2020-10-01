/*
 * If the problem is :
 * 1->		x ≡ 2 mod 3
 * 2->		x ≡ 3 mod 4
 * 3->		x ≡ 4 mod 5
 *
 * then the divisor array in the driver function will be : {3, 4, 5}
 * and the remainder array will be : {2, 3, 4}
 *
 * Therefore the program output is : 59 (Minimum number that satisifies 1, 2, 3).
 */

import java.lang.*;

class Chinese_Remainder_Theorem {
	//Inverse calculation using extended Euclidean Algorithm(Iterative Method)
	public static long inverse(long a, long m) {
		long m0, x0, x1, q, t;
		m0 = m;
		x0 = 0;
		x1 = 1;
		if (m == 1)
			return 0;

		while (a > 1)
		{
			q = a / m;
			t = m;
			m = a % m;
			a = t;
			t = x0;
			x0 = x1 - q * x0;
			x1 = t;
		}

		if (x1 < 0)
		    x1 += m0;

		return x1;
	}

	//Main Logic function
	public static long findMinimumDividend(long[] divisor, long[] remainder) {
        long product, result, partialProduct;
        int i, len = divisor.length;

        product = 1;

        for (i = 0; i < len; i++)
            product *= divisor[i];

        result = 0;

        for (i = 0; i < len; i++)
        {
            partialProduct = product / divisor[i];
            result += remainder[i] * inverse(partialProduct, divisor[i]) * partialProduct;
        }
        return (result % product);
    }

	// Driver function
	// Answer for this problem : 3371
	public static void main(String[] args) {
		long result;
		long[] divisor = { 3, 4, 5, 7, 11 };
        long[] remainder = { 2, 3, 1, 4, 5 };
        result = findMinimumDividend(divisor, remainder);
        System.out.println("Minimum value of dividend is : " + result);
	}
}
