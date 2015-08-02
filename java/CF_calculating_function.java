// The problem is here: http://codeforces.com/problemset/problem/486/A

import java.math.BigInteger;
import java.util.Scanner;

public class CF_calculating_function
{
    private static BigInteger calculate_function(BigInteger n)
    {
        BigInteger b = new BigInteger("2");

        if (n.mod(b).equals(BigInteger.ZERO)) {
            BigInteger value = n.divide(b);
            return value;
        } else {
            BigInteger value = n;
            value = value.add(BigInteger.valueOf(1));
            value = value.divide(b);
            BigInteger zero = BigInteger.ZERO;
            value = zero.subtract(value);
            return value;
        }
    }

    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        BigInteger input = in.nextBigInteger();
        BigInteger fun_n = calculate_function(input);
        System.out.println(fun_n);
    }
}
