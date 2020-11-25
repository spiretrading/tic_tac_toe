#include "TicTacToe/Library/Board.hpp"

using namespace TicTacToe;

Board::Token Board::get_piece(int x, int y) const {
  return Token::NONE;
}

void Board::set_piece(int x, int y, Token token) {}

bool Board::operator ==(const Board& board) const {
  return true;
}

bool Board::operator !=(const Board& board) const {
  return true;
}

Board::Token TicTacToe::evaluate_winner(const Board& board) {
  return Board::Token::NONE;
}
