import java.lang.Math;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;
import java.math.MathContext;
import java.math.RoundingMode;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int T;
        T = in.nextInt();
        while(T>0) {
            T--;
            int b = in.nextInt();
            BigInteger a = BigInteger.valueOf(2);
            BigInteger c = a.pow(b);
            System.out.println(c);
        }
        in.close();
    }

}
