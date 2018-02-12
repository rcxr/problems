// https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check

#include "bits/stdc++.h"

enum TileType { EMPTY, WHITE_PAWN, WHITE_ROOK, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, BLACK_ROOK, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, OTHER };

struct Tile {
public:
  explicit Tile(char c) {
    switch(c) {
      case '#': type = EMPTY; break;
      case 'P': type = WHITE_PAWN; break;
      case 'R': type = WHITE_ROOK; break;
      case 'B': type = WHITE_BISHOP; break;
      case 'Q': type = WHITE_QUEEN; break;
      case 'K': type = WHITE_KING; break;
      case 'r': type = BLACK_ROOK; break;
      case 'b': type = BLACK_BISHOP; break;
      case 'q': type = BLACK_QUEEN; break;
      case 'k': type = BLACK_KING; break;
      default: type = OTHER; break;
    }
  }

  void setType(TileType type) { this->type = type; }
  bool isEmpty() const { return EMPTY == type; }
  bool isWhitePawn() const { return WHITE_PAWN == type; }
  bool isWhiteRook() const { return WHITE_ROOK == type; }
  bool isWhiteBishop() const { return WHITE_BISHOP == type; }
  bool isWhiteQueen() const { return WHITE_QUEEN == type; }
  bool isWhiteKing() const { return WHITE_KING == type; }
  bool isBlackRook() const { return BLACK_ROOK == type; }
  bool isBlackBishop() const { return BLACK_BISHOP == type; }
  bool isBlackQueen() const { return BLACK_QUEEN == type; }
  bool isBlackKing() const { return BLACK_KING == type; }

private:
  TileType type;
};

std::vector<std::vector<Tile>> readBoard() {
  char c;
  std::vector<std::vector<Tile>> board(8);

  for (auto i = 0; i < 8; ++i) {
    for (auto j = 0; j < 8; ++j) {
      std::cin >> c;
      board[i].emplace_back(c);
    }
  }

  return board;
}

std::vector<std::vector<Tile>> cloneBoard(std::vector<std::vector<Tile>> const& board) {
  std::vector<std::vector<Tile>> other(8);
  for (auto i = 0; i < 8; ++i) {
    for (auto j = 0; j < 8; ++j) {
      other[i].push_back(board[i][j]);
    }
  }
  return other;
}

bool isBlackKing(std::vector<std::vector<Tile>> const& board, int row, int col) {
  return 0 <= row && row < 8 && 0 <= col && col < 8 && board[row][col].isBlackKing();
}

std::pair<int, int> findBlackKing(std::vector<std::vector<Tile>> const& board) {
  for (auto i = 0; i < 8; ++i) {
    for (auto j = 0; j < 8; ++j) {
      if (board[i][j].isBlackKing()) {
        return std::make_pair(i, j);
      }
    }
  }
  throw "invalid board";
}

std::pair<int, int> findWhiteKing(std::vector<std::vector<Tile>> const& board) {
  for (auto i = 0; i < 8; ++i) {
    for (auto j = 0; j < 8; ++j) {
      if (board[i][j].isWhiteKing()) {
        return std::make_pair(i, j);
      }
    }
  }
  throw "invalid board";
}

bool isCheckPositionForBlack(std::vector<std::vector<Tile>> const& board) {
  auto kingPosition = findWhiteKing(board);

  // Left
  int offset = 1;
  while (0 <= kingPosition.second - offset) {
    auto const& tile = board[kingPosition.first][kingPosition.second - offset];
    if (tile.isBlackRook() || tile.isBlackQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Right
  offset = 1;
  while (kingPosition.second + offset < 8) {
    auto const& tile = board[kingPosition.first][kingPosition.second + offset];
    if (tile.isBlackRook() || tile.isBlackQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Left-up diagonal
  offset = 1;
  while (0 <= kingPosition.first - offset && 0 <= kingPosition.second - offset) {
    auto const& tile = board[kingPosition.first - offset][kingPosition.second - offset];
    if (tile.isBlackBishop() || tile.isBlackQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Right-up diagonal
  offset = 1;
  while (0 <= kingPosition.first - offset && kingPosition.second + offset < 8) {
    auto const& tile = board[kingPosition.first - offset][kingPosition.second + offset];
    if (tile.isBlackBishop() || tile.isBlackQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  return false;
}

bool isCheckPositionForWhite(std::vector<std::vector<Tile>> const& board) {
  auto kingPosition = findBlackKing(board);

  // Left
  int offset = 1;
  while (0 <= kingPosition.second - offset) {
    auto const& tile = board[kingPosition.first][kingPosition.second - offset];
    if (tile.isWhiteRook() || tile.isWhiteQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Right
  offset = 1;
  while (kingPosition.second + offset < 8) {
    auto const& tile = board[kingPosition.first][kingPosition.second + offset];
    if (tile.isWhiteRook() || tile.isWhiteQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Left-up diagonal
  offset = 1;
  while (0 <= kingPosition.first - offset && 0 <= kingPosition.second - offset) {
    auto const& tile = board[kingPosition.first - offset][kingPosition.second - offset];
    if (tile.isWhiteBishop() || tile.isWhiteQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  // Right-up diagonal
  offset = 1;
  while (0 <= kingPosition.first - offset && kingPosition.second + offset < 8) {
    auto const& tile = board[kingPosition.first - offset][kingPosition.second + offset];
    if (tile.isWhiteBishop() || tile.isWhiteQueen()) {
      return true;
    }
    if (!tile.isEmpty()) {
      break;
    }
    ++offset;
  }

  return false;
}

bool isCheckPositionForWhiteKnight(std::vector<std::vector<Tile>> const& board, int col) {
  return isBlackKing(board, 1, col - 2)
    || isBlackKing(board, 1, col + 2)
    || isBlackKing(board, 2, col - 1)
    || isBlackKing(board, 2, col + 1);
}

bool isCheckPositionForWhiteBishop(std::vector<std::vector<Tile>> const& board, int col) {
  int offset = 1;
  // Left diagonal
  while (0 <= col - offset) {
    if (board[offset][col - offset].isBlackKing()) {
      return true;
    }
    if (!board[offset][col - offset].isEmpty()) {
      break;
    }
    ++offset;
  }
  offset = 1;
  // Right diagonal
  while (col + offset < 8) {
    if (board[offset][col + offset].isBlackKing()) {
      return true;
    }
    if (!board[offset][col + offset].isEmpty()) {
      break;
    }
    ++offset;
  }
  return false;
}

bool isCheckPositionForWhiteRook(std::vector<std::vector<Tile>> const& board, int col) {
  // Left
  int currentRow = 0;
  int currentCol = col - 1;
  while (0 <= currentCol) {
    if (board[currentRow][currentCol].isBlackKing()) {
      return true;
    }
    if (!board[currentRow][currentCol].isEmpty()) {
      break;
    }
    --currentCol;
  }
  // Right
  currentCol = col + 1;
  while (currentCol < 8) {
    if (board[currentRow][currentCol].isBlackKing()) {
      return true;
    }
    if (!board[currentRow][currentCol].isEmpty()) {
      break;
    }
    ++currentCol;
  }
  // Down
  currentRow = 2;
  currentCol = col;
  while (currentRow < 8) {
    if (board[currentRow][currentCol].isBlackKing()) {
      return true;
    }
    if (!board[currentRow][currentCol].isEmpty()) {
      break;
    }
    ++currentRow;
  }
  return false;
}

int findPromotionColumn(std::vector<std::vector<Tile>> const& board) {
  for (auto i = 0; i < 8; ++i) {
    if (board[0][i].isEmpty() && board[1][i].isWhitePawn()) {
      auto other = cloneBoard(board);
      other[0][i].setType(WHITE_PAWN);
      other[1][i].setType(EMPTY);
      if (!isCheckPositionForBlack(other)) {
        return i;
      }
    }
  }
  throw "invalid board";
}

int countCheckPromotions(std::vector<std::vector<Tile>>& board) {
  auto col = findPromotionColumn(board);
  board[1][col].setType(EMPTY);

  if (isCheckPositionForWhite(board)) {
    return 4;
  }
  if (isCheckPositionForWhiteKnight(board, col)) {
    return 1;
  }
  if (isCheckPositionForWhiteRook(board, col) || isCheckPositionForWhiteBishop(board, col)) {
    return 2;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    auto board = readBoard();
    std::cout << countCheckPromotions(board) << std::endl;
  }
  return 0;
}
