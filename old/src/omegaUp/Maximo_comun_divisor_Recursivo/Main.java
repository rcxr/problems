package omegaUp.Maximo_comun_divisor_Recursivo;

import java.util.Scanner;

// https://omegaup.com/arena/problem/Maximo-comun-divisor-Recursivo
public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();
    in.close();
    while (0 != b) {
      int t = a % b;
      a = b;
      b = t;
    }
    System.out.println(a);
  }
}
