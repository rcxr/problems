package acm.timus.p1033;

import java.util.Scanner;

/**
 * Timus Online Judge
 * Problem 1033. Labyrinth
 * http://acm.timus.ru/problem.aspx?space=1&num=1033
 * 
 * @author rcxr
 */
public class Main {

  private static final char MONOLITH = '#';

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    // Reading the labyrinth dimension
    int n = Integer.valueOf(in.nextLine());

    char[][] labyrinth = new char[n][];
    // Reading the labyrinth
    for (int i = 0; i < n; i++) {
      labyrinth[i] = in.nextLine().toCharArray();
    }
    // Matrix that records the "visit" status
    // of the cells
    boolean[][] visited = new boolean[n][n];
    // We are going to kick-off a recursive
    // algorithm on the upper-left and down-right
    // corners. This algorithm is going to
    // "visit" the cells only once and count
    // the number of visible walls
    int walls = visit(labyrinth, visited, 0, 0, n)
      + visit(labyrinth, visited, n - 1, n - 1, n);
    // Once we got the number of walls we remove
    // the four walls that correspond to the two
    // opposite corners and we multiply by 9, the
    // wall area
    System.out.println((walls - 4) * 9);
  }

  /**
   * This algorithm is going to attempt to visit the cell.
   * If the cell is a monolith or is out of bounds this means
   * that we have crossed a wall, we increase the wall counter
   * and return.
   * If the cell is not a monolith and has not been visited
   * then we visit it and move on to all it neighbors.
   * If the cell has already been visited then there is nothing
   * else to do, we simply go back.
   * @param labyrinth The labyrinth
   * @param visited Matrix that records the visits
   *   for the empty cells
   * @param i Current position (x)
   * @param j Current position (y)
   * @param n Labyrinth dimension
   * @return The number of visible walls for all the non-visited
   *   cells that could be reached from the current position
   */
  private static int visit(char[][] labyrinth, boolean[][] visited, int i, int j, int n) {
    if (i < 0 || j < 0 || i == n || j == n || labyrinth[i][j] == MONOLITH) {
      // If we are now out of bounds or in a monolith cell this means
      // that we have crossed a wall. We count the wall and return
      return 1;
    } else if (visited[i][j]) {
      // If this is not a monolith, then we didn't cross a wall
      // If the free cell has already been visited we can go back,
      // there is nothing else to do
      return 0;
    } else {
      // If the free cell has not been visited then we visit it
      // and kick-off the algorithm for all its neighbors
      visited[i][j] = true;
      return visit(labyrinth, visited, i + 1, j, n)
        + visit(labyrinth, visited, i, j + 1, n)
        + visit(labyrinth, visited, i - 1, j, n)
        + visit(labyrinth, visited, i, j - 1, n);
    }
  }
}
