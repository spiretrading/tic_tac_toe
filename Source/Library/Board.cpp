#include "TicTacToe/Library/Board.hpp"

using namespace TicTacToe;

Board::Token Board::get_piece(int x, int y) const {
  if(x < 0 || y < 0 || x >= ROW_COUNT || y >= COLUMN_COUNT) {
    throw std::out_of_range(
      "The x or y coordinate is outside of the board's range.");
  }
  return m_board[x][y];
}

void Board::set_piece(int x, int y, Token token) {
  if(x < 0 || y < 0 || x >= ROW_COUNT || y >= COLUMN_COUNT) {
    throw std::out_of_range(
      "The x or y coordinate is outside of the board's range.");
  }
  m_board[x][y] = token;
}


Board::Token TicTacToe::evaluate_winner(const Board& board) {
  /** Count of each row */
  auto rows = std::array<int, Board::ROW_COUNT>();

  /** Count of each column */
  auto columns = std::array<int, Board::COLUMN_COUNT>();

  /** Count on the diagonal */
  auto diagonal = 0;

  /** Count on the reverse diagonal */
  auto reverse_diagonal = 0;

  for(auto x = 0; x < Board::ROW_COUNT; ++x) {
    for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
      auto piece = board.get_piece(x, y);
      auto point = [&] {
        if(piece == Board::Token::NONE) {
          return 0;
        } else if(piece == Board::Token::X) {
          return 1;
        } else {
          return -1;
        }
      }();
      rows[x] += point;
      columns[y] += point;
      diagonal += [&] {
        if(x == y) {
          return point;
        } else {
          return 0;
        }
      }();
      reverse_diagonal += [&] {
        if(x == Board::COLUMN_COUNT - 1 - y) {
          return point;
        } else {
          return 0;
        }
      }();
    }
  }
  for(auto x = 0; x < Board::ROW_COUNT; ++x) {
    if(std::abs(rows[x]) == Board::ROW_COUNT) {
      return board.get_piece(x, 0);
    }
  }
  for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
    if(std::abs(columns[y]) == Board::COLUMN_COUNT) {
      return board.get_piece(0, y);
    }
  }
  if(std::abs(diagonal) == Board::ROW_COUNT) {
    return board.get_piece(0, 0);
  }
  if(std::abs(reverse_diagonal) == Board::ROW_COUNT) {
    return board.get_piece(0, Board::COLUMN_COUNT - 1);
  }
  return Board::Token::NONE;
}
