#include "TicTacToe/Library/ApplicationController.hpp"
#include "TicTacToe/Library/DrawConditionWindow.hpp"
#include "TicTacToe/Library/TitleWindow.hpp"
#include "TicTacToe/Library/WinConditionWindow.hpp"

using namespace TicTacToe;

ApplicationController::ApplicationController()
  : m_x_badge_count(0),
    m_o_badge_count(0) {
  m_application_window.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
  auto layout = new QVBoxLayout(&m_application_window);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  m_application_window.setLayout(layout);
  m_application_window.show();
  show_title_window();
}

void ApplicationController::show_title_window() {
  m_x_badge_count = 0;
  m_o_badge_count = 0;
  auto title_window = new TitleWindow(&m_application_window);
  m_application_window.layout()->addWidget(title_window);
  title_window->connect_play_now_signal([this] {
    m_application_window.layout()->takeAt(0)->widget()->deleteLater();
    play();
  });
}

void ApplicationController::play() {
  m_game_board_controller.emplace(m_x_badge_count, m_o_badge_count);
  m_application_window.layout()->addWidget(
    &m_game_board_controller->get_game_board_window());
  m_game_board_controller->connect_game_over_signal(
    [this] (Board::Token winner) {
      m_application_window.layout()->takeAt(0);
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
  auto win_window = new WinConditionWindow(winner, &m_application_window);
  m_application_window.layout()->addWidget(win_window);
  win_window->connect_start_signal([this] {
    m_application_window.layout()->takeAt(0)->widget()->deleteLater();
    play();
  });
  win_window->connect_back_signal([this] {
    m_application_window.layout()->takeAt(0)->widget()->deleteLater();
    show_title_window();
  });
}

void ApplicationController::game_draw() {
  auto draw_window = new DrawConditionWindow(&m_application_window);
  m_application_window.layout()->addWidget(draw_window);
  draw_window->connect_start_signal([this] {
    m_application_window.layout()->takeAt(0)->widget()->deleteLater();
    play();
  });
  draw_window->connect_back_signal([this] {
    m_application_window.layout()->takeAt(0)->widget()->deleteLater();
    show_title_window();
  });
}
