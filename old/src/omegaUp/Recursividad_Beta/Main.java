package omegaUp.Recursividad_Beta;

import java.util.Scanner;

// https://omegaup.com/arena/problem/Recursividad-Beta
public class Main {
  
  private static int f(int n) {
    if (1 <= n && n <= 60) {
      n = 15 < n ? f(n - 10) * 5 : n * 4;
    }
    System.out.println(n);
    return n;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    in.close();
    f(n);
  }
}
