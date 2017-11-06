package omegaUp.Escribir_al_reves;

import java.util.Scanner;

// https://omegaup.com/arena/problem/1-Escribir-al-reves
public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    char[] original = in.nextLine().toCharArray();
    char[] reversed = new char[original.length];
    for (int i = 0; i < original.length; ++i) {
      reversed[i] = original[original.length - 1 - i];
    }
    System.out.println(new String(reversed));
    in.close();
  }
}
