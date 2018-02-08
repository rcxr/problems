#include <vector>
#include <iostream>

using namespace std;

class Grid {
public:
  explicit Grid(vector<vector<bool>> const& matrix) : matrix(matrix), n(matrix.size()) {
    // Initialize cache and visited matrix
    for (auto i = 0; i < n; ++i) {
      vector<vector<int>> row;
      for (auto j = 0; j < n; ++j) {
        vector<int> array = { -1, -1 };
        row.push_back(array);
      }
      cache.push_back(row);
    }

    // Fill cache
    fillCache(0, 0, 0);
  }

  bool pathExists(int x, int y, int k) const {
    auto parity = k % 2;
    // Return true if the cell is not a wall
    // and
    // if optimal path corresponding to the parity of k is better or equal to k
    return -1 < cache[x][y][parity] && cache[x][y][parity] <= k;
  }

private:
  void fillCache(int x, int y, int cost) {
    // Out of bounds
    if (x < 0 || y < 0 || n <= x || n <= y) {
      return;
    }

    // Wall
    if (matrix[x][y]) {
      return;
    }

    auto parity = cost % 2;

    // Better cached cost
    if (-1 < cache[x][y][parity] && cache[x][y][parity] <= cost) {
      return;
    }

    // Cache it
    cache[x][y][parity] = cost;

    // Recurse
    fillCache(x + 1, y + 1, cost + 1);
    fillCache(x - 1, y + 1, cost + 1);
    fillCache(x - 1, y - 1, cost + 1);
    fillCache(x + 1, y - 1, cost + 1);
    fillCache(x - 1, y, cost + 1);
    fillCache(x, y - 1, cost + 1);
    fillCache(x + 1, y, cost + 1);
    fillCache(x, y + 1, cost + 1);
  }

  int const n;
  vector<vector<bool>> const matrix;
  vector<vector<vector<int>>> cache;
};

int main() {
  vector<vector<bool>> matrix;

  // Read matrix dimension
  int n;
  cin >> n;

  // Read square matrix (nxn)
  for (auto i = 0; i < n; ++i) {
    vector<bool> row(n);
    for (auto j = 0; j < n; ++j) {
      bool cell;
      cin >> cell;
      row[j] = cell;
    }
    matrix.push_back(row);
  }

  // Initialize grid
  Grid grid(matrix);

  // Read number of test cases
  cin >> n;

  // Run n test cases
  while (n--) {
    int x, y, k;
    cin >> x >> y >> k;
    // Determine whether path exists
    cout << grid.pathExists(x, y, k) << endl;
  }
  return 0;
}
