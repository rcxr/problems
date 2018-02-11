// https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check

#include "bits/stdc++.h"

enum TileType { WHITE_PAWN, WHITE_ROOK, WHITE_BISHOP, WHITE_QUEEN, BLACK_KING, OTHER, EMPTY };

struct Tile {
  explicit Tile(char c) {
    switch(c) {
      case 'P':
        type = WHITE_PAWN;
        break;
      case 'Q':
        type = WHITE_QUEEN;
        break;
      case 'B':
        type = WHITE_BISHOP;
        break;
      case 'R':
        type = WHITE_ROOK;
        break;
      case 'k':
        type = BLACK_KING;
        break;
      case '#':
        type = EMPTY;
        break;
      default:
        type = OTHER;
        break;
    }
  }

  void setType(TileType type) {
    this->type = type;
  }

  bool isEmpty() const {
    return EMPTY == type;
  }

  bool isWhitePawn() const {
    return WHITE_PAWN == type;
  }

  bool isWhiteRook() const {
    return WHITE_ROOK == type;
  }

  bool isWhiteBishop() const {
    return WHITE_BISHOP == type;
  }

  bool isWhiteQueen() const {
    return WHITE_QUEEN == type;
  }

  bool isBlackKing() const {
    return BLACK_KING == type;
  }

  TileType type;
};

int findPromotionColumn(std::vector<std::vector<Tile>> const& board) {
  for (auto i = 0; i < 8; ++i) {
    if (board[0][i].isEmpty() && board[1][i].isWhitePawn()) {
      return i;
    }
  }
  throw "invalid board";
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

bool isCheckPosition(std::vector<std::vector<Tile>> const& board) {
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

bool isCheckPositionForKnight(std::vector<std::vector<Tile>> const& board, int col) {
  return isBlackKing(board, 1, col - 2)
    || isBlackKing(board, 1, col + 2)
    || isBlackKing(board, 2, col - 1)
    || isBlackKing(board, 2, col + 1);
}

bool isCheckPositionForBishop(std::vector<std::vector<Tile>> const& board, int col) {
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

bool isCheckPositionForRook(std::vector<std::vector<Tile>> const& board, int col) {
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

int countCheckPromotions(std::vector<std::vector<Tile>>& board) {
  auto col = findPromotionColumn(board);
  board[1][col].setType(EMPTY);

  if (isCheckPosition(board)) {
    return 4;
  }
  if (isCheckPositionForKnight(board, col)) {
    return 1;
  }
  if (isCheckPositionForRook(board, col) || isCheckPositionForBishop(board, col)) {
    return 2;
  }
  return 0;
}

std::vector<std::vector<Tile>> readBoard() {
  char c;
  std::vector<std::vector<Tile>> board(8);

  for (auto i = 0; i < 8; ++i) {
    for (auto j = 0; j < 8; ++j) {
      std::cin >> c;
      board[i].push_back(Tile(c));
    }
  }

  return board;
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
