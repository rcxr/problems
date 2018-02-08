package projecteuler.p3;

/**
 * Project Euler
 * Problem 3
 * http://projecteuler.net/problem=3
 * 
 * @author rcxr
 */
public class Main {

  // We will use dynamic-programming for remembering the
  // last prime that is candidate to be a divisor
  private static final long FIRST_PRIME = 3l;
  // The initial value of the number to analyze
  // as we remove small prime factors from it the
  // number will rapidly shrink
  private static final long COMPOSITE = 600851475143l;

  public static void main(String[] args) {
    long d = getLargestPrime(FIRST_PRIME, COMPOSITE);
    System.out.println(d);
  }

  /**
   * The smallest divisor is a prime.
   * The largest divisor is the complement of the smallest divisor.
   * The largest prime is always present in the largest divisor.
   * Therefore it's equivalent to get the largest prime from
   * the largest divisor than to get the prime from the actual
   * number.
   * It's faster to find small divisors than big ones. We can use
   * this to get the smallest one and from there deduce the biggest
   * one. 
   * @param prime We remember what is the last prime divisor that
   *   divides the original number. By remembering this number
   *   we improve performance since we don't need to travel again
   *   through all the numbers for finding the smallest divisor
   * @param composite The number to analyze
   * @return
   */
  private static long getLargestPrime(long prime, long composite) {
    // Get the smallest prime divisor
    prime = getSmallestPrime(prime, composite);
    if (prime == composite) {
      // If the smallest divisor is equals to the composite
      // we are done. We return
      return prime;
    } else {
      // If not we remove the divisor from the number to analyze
      // and kick-off another iteration of the algorithm 
      return getLargestPrime(prime, composite / prime);
    }
  }

  /**
   * We use brute force to find the smallest divisor (that is
   * also the smallest prime divisor)
   * @param prime We remember what is the last prime divisor that
   *   divides the original number. By remembering this number
   *   we improve performance since we don't need to travel again
   *   through all the numbers for finding the smallest divisor
   * @param composite The number to analyze
   * @return
   */
  private static long getSmallestPrime(long prime, long composite) {
    while (0 != composite % prime) {
      // We can increase the number by two since we know
      // there are no even primes other than the number "2"
      prime += 2;
    }
    return prime;
  }
}
