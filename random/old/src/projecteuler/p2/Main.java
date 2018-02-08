package projecteuler.p2;

/**
 * Project Euler
 * Problem 2
 * http://projecteuler.net/problem=2
 * 
 * @author rcxr
 */
public class Main {

  // The limit
  private static final int FOUR_MILLION = 4000000;

  public static void main(String[] args) {
    // The Fibonnaci sequence always follows the patter:
    // odd, odd, even, odd, odd, even, ..
    int odd1;
    int odd2 = 1;
    int even = 2;
    int sum = 0;
    // We are going to get three numbers in the sequence
    // every time we run this loop and we will add the
    // even valued number until we cross the limit
    while (even < FOUR_MILLION) {
      sum += even;
      odd1 = odd2 + even;
      odd2 = even + odd1;
      even = odd1 + odd2;
    }
    // We simply print the result
    System.out.println(sum);
  }
}
