package projecteuler.p24;

import java.util.LinkedList;
import java.util.List;

/**
 * Project Euler
 * Problem 24
 * http://projecteuler.net/thread=24
 * 
 * @author rcxr
 */
public class Main {

  public static void main(String[] args) {
    int n = 999999;
    int factorial = 3628800;
    List<Integer> digits = new LinkedList<Integer>();
    int i;
    for (i = 0; i < 10; i++) {
      digits.add(i);
    }
    do {
      factorial /= i--;
      System.out.print(digits.remove(n / factorial));
      n %= factorial;
    } while (0 != i);
  }
}
