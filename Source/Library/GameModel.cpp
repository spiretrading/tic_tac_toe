#include "TicTacToe/Library/GameModel.hpp"

using namespace TicTacToe;

GameModel::GameModel() : 
  m_board{},
  m_state{State::INVALID},
  m_turn{Board::Token::X},
  m_moves{0} {
}

const Board& GameModel::get_board() const {
  return m_board;
}

Board::Token GameModel::get_turn() const {
  return m_turn;
}

GameModel::State GameModel::play_move(int x, int y) {
  if(m_state == State::END) {
    return State::END;
  }
  if(m_board.get_piece(x, y) != Board::Token::NONE) {
    return State::INVALID;
  }
  m_board.set_piece(x, y, m_turn);
  ++m_moves;
  if(m_moves >= Board::ROW_COUNT &&
      evaluate_winner(m_board) != Board::Token::NONE ||
      m_moves == Board::ROW_COUNT * Board::COLUMN_COUNT) {
    m_state = State::END;
  } else {
    m_state = State::CONTINUE;
    if(m_turn == Board::Token::X) {
      m_turn = Board::Token::O;
    } else if(m_turn == Board::Token::O) {
      m_turn = Board::Token::X;
    }
  }
  return m_state;
}
