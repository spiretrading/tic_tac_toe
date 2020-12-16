#include "TicTacToe/Library/ApplicationController.hpp"

using namespace TicTacToe;

ApplicationController::ApplicationController()
  : m_x_badge_count(0),
    m_o_badge_count(0) {
  show_title_window();
}

void ApplicationController::show_title_window() {
  m_x_badge_count = 0;
  m_o_badge_count = 0;
  m_title_window = std::make_unique<TitleWindow>();
  m_title_window->connect_play_now_signal([this] {
    m_title_window.reset();
    play();
  });
  m_title_window->show();
}

void ApplicationController::play() {
  m_game_board_controller = std::make_unique<GameBoardController>(
    m_x_badge_count, m_o_badge_count);
  m_game_board_controller->connect_game_over_signal(
    [this] (Board::Token winner) {
      m_game_board_controller.reset();
      game_over(winner);
    });
}

void ApplicationController::game_over(Board::Token winner) {
  if(winner == Board::Token::NONE) {
    game_draw();
  } else {
    game_win(winner);
  }
}

void ApplicationController::game_win(Board::Token winner) {
  if(winner == Board::Token::X) {
    ++m_x_badge_count;
    if(m_x_badge_count > 9) {
      m_x_badge_count = 1;
      m_o_badge_count = 0;
    }
  } else if(winner == Board::Token::O) {
    ++m_o_badge_count;
    if(m_o_badge_count > 9) {
      m_x_badge_count = 0;
      m_o_badge_count = 1;
    }
  }
  m_win_window = std::make_unique<WinConditionWindow>(winner);
  m_win_window->connect_start_signal([this] {
    m_win_window.reset();
    play();
  });
  m_win_window->connect_back_signal([this] {
    m_win_window.reset();
    show_title_window();
  });
  m_win_window->show();
}

void ApplicationController::game_draw() {
  m_draw_window = std::make_unique<DrawConditionWindow>();
  m_draw_window->connect_start_signal([this] {
    m_draw_window.reset();
    play();
  });
  m_draw_window->connect_back_signal([this] {
    m_draw_window.reset();
    show_title_window();
  });
  m_draw_window->show();
}
