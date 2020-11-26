#include "TicTacToe/Library/Board.hpp"

using namespace TicTacToe;

Board::Token Board::get_piece(int x, int y) const {
  if(x < 0 || y < 0 || x >= ROW_COUNT || y >= COLUMN_COUNT)
    throw std::out_of_range(
      "The x or y coordinate is outside of the board's range.");

  return board_[x][y];
}

void Board::set_piece(int x, int y, Token token) {
  if(x < 0 || y < 0 || x >= ROW_COUNT || y >= COLUMN_COUNT)
    throw std::out_of_range(
      "The x or y coordinate is outside of the board's range.");

  board_[x][y] = token;
}


Board::Token TicTacToe::evaluate_winner(const Board& board) {
  /** Count of each row */
  std::vector<int> rows(Board::ROW_COUNT, 0);

  /** Count of each column */
  std::vector<int> cols(Board::COLUMN_COUNT, 0);

  /** Count on the diagonal */
  auto diag = 0;

  /** Count on the reverse diagonal */
  auto reverse_diag = 0;

  for(auto x = 0; x < Board::ROW_COUNT; ++x) {
    for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
      auto piece = board.get_piece(x, y);
      auto point = (piece == Board::Token::NONE ? 0 : 
        (piece == Board::Token::X ? 1 : -1));
      rows[x] += point;
      cols[y] += point;
      diag += (x == y ? point : 0);
      reverse_diag += (x == Board::COLUMN_COUNT - 1 - y ? point : 0);
    }
  }

  for(auto x = 0; x < Board::ROW_COUNT; ++x) {
    if(abs(rows[x]) == Board::ROW_COUNT)
      return board.get_piece(x, 0);
  }

  for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
    if(abs(cols[y]) == Board::COLUMN_COUNT)
      return board.get_piece(0, y);
  }

  if(abs(diag) == Board::ROW_COUNT)
    return board.get_piece(0, 0);

  if(abs(reverse_diag) == Board::ROW_COUNT)
    return board.get_piece(0, Board::COLUMN_COUNT - 1);
  
  return Board::Token::NONE;
}
