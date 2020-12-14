#include "TicTacToe/Library/GameBoardWindow/GameBoardController.hpp"

using namespace boost::signals2;
using namespace TicTacToe;

GameBoardController::GameBoardController(int x_badge_count, int o_badge_count)
    : m_x_badge_count(x_badge_count),
      m_o_badge_count(o_badge_count),
      m_game_state(GameModel::State::CONTINUE),
      m_game_board_window(m_game_model.get_board(), Board::Token::X) {
  init_game_board();
  show_game_board();
}

connection GameBoardController::connect_game_over_signal(
    const GameOverSignal::slot_type& slot) const {
  return m_game_over_signal.connect(slot);
}

void GameBoardController::init_game_board() {
  m_game_board_window.get_x_badge_panel().set_score(m_x_badge_count);
  m_game_board_window.get_o_badge_panel().set_score(m_o_badge_count);
  m_game_board_window.get_panel().connect_clicked_signal([this] (int x, int y) {
    on_game_board_clicked(x, y);
  });
}

void GameBoardController::show_game_board() {
  m_game_board_window.show();
  m_game_board_window.activateWindow();
}

void GameBoardController::on_game_board_clicked(int x, int y) {
  if(m_game_state == GameModel::State::END) {
    return;
  }
  auto game_state = m_game_model.play_move(x, y);
  if(game_state == GameModel::State::INVALID) {
    return;
  }
  m_game_board_window.get_panel().refresh_board();
  m_game_board_window.set_turn(m_game_model.get_turn());
  if(game_state == GameModel::State::END) {
    m_game_state = game_state;
    m_game_over_signal(evaluate_winner(m_game_model.get_board()));
  }
}
