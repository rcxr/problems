package projecteuler.p12;

public class Main {

  private static final int FOUR_MILLION = 4000000;

  public static void main(String[] args) {
    int odd1;
    int odd2 = 1;
    int even = 2;
    int sum = 0;
    while (even < FOUR_MILLION) {
      sum += even;
      odd1 = odd2 + even;
      odd2 = even + odd1;
      even = odd1 + odd2;
    }
    System.out.println(sum);
  }
}
