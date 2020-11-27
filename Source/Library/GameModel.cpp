#include "TicTacToe/Library/GameModel.hpp"

using namespace TicTacToe;

GameModel::GameModel() : 
  m_board(),
  m_turn(Board::Token::X),
  m_state(State::INVALID),
  m_moves(0) {
}

const Board& GameModel::get_board() const {
  return m_board;
}

Board::Token GameModel::get_turn() const {
  return m_turn;
}

GameModel::State GameModel::play_move(int x, int y) {
  if(m_state != State::END) {
    if(m_board.get_piece(x, y) == Board::Token::NONE) {
      m_board.set_piece(x, y, m_turn);
      ++m_moves;
      auto turn = [&] {
        if(m_turn == Board::Token::X) {
          m_turn = Board::Token::O;
        } else if(m_turn == Board::Token::O) {
          m_turn = Board::Token::X;
        }
      };
      auto continue_play = [&] {
        m_state = State::CONTINUE;
        turn();
      };
      if(m_moves >= Board::ROW_COUNT) {
        auto winner = evaluate_winner(m_board);
        if(winner != Board::Token::NONE) {
          m_state = State::END;
        } else {
          if(m_moves == Board::ROW_COUNT * Board::COLUMN_COUNT) {
            m_state = State::END;
          } else {
            continue_play();
          }
        }
      } else {
        continue_play();
      }
    } else {
      m_state = State::INVALID;
    }
  }
  return m_state;
}
