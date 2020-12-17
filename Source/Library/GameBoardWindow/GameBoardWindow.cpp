#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include "TicTacToe/Library/GameBoardWindow/GameBoardWindow.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace TicTacToe;

GameBoardWindow::GameBoardWindow(const Board& board, Board::Token turn, QWidget* parent)
    : QWidget(parent),
      m_game_panel(new GameBoardPanel(board, this)),
      m_x_badge_panel(new BadgePanel(Board::Token::X, 0, this)),
      m_o_badge_panel(new BadgePanel(Board::Token::O, 0, this)) {
  setStyleSheet("background-color: #FFFFFF;");
  auto v_layout = new QVBoxLayout(this);
  v_layout->setContentsMargins(0, 0, 0, 0);
  v_layout->setSpacing(0);
  v_layout->addSpacing(scale_height(50));
  auto player_turn_label = new QLabel(this);
  player_turn_label->setFixedHeight(scale_height(24));
  player_turn_label->setAlignment(Qt::AlignCenter);
  player_turn_label->setStyleSheet(QString(R"(
    background-color: #FFFFFF;
    color: #4B23A0;
    font-family: Open Sans;
    font-size: %1px;
    font-weight: bold;)").arg(scale_width(18)));
  v_layout->addWidget(player_turn_label);
  v_layout->addSpacing(scale_height(50));
  auto h_layout = new QHBoxLayout(this);
  h_layout->setContentsMargins(0, 0, 0, 0);
  h_layout->setSpacing(scale_width(50));
  h_layout->addSpacing(scale_width(68));
  h_layout->addWidget(m_x_badge_panel);
  h_layout->addWidget(m_game_panel);
  h_layout->addWidget(m_o_badge_panel);
  h_layout->addSpacing(scale_width(68));
  v_layout->addLayout(h_layout);
  v_layout->addSpacing(scale_height(86));
  setLayout(v_layout);
  set_turn(turn);
}

const BadgePanel& GameBoardWindow::get_x_badge_panel() const {
  return *m_x_badge_panel;
}

BadgePanel& GameBoardWindow::get_x_badge_panel() {
  return *m_x_badge_panel;
}

const BadgePanel& GameBoardWindow::get_o_badge_panel() const {
  return *m_o_badge_panel;
}

BadgePanel& GameBoardWindow::get_o_badge_panel() {
  return *m_o_badge_panel;
}

const GameBoardPanel& GameBoardWindow::get_panel() const {
  return *m_game_panel;
}

GameBoardPanel& GameBoardWindow::get_panel() {
  return *m_game_panel;
}

Board::Token GameBoardWindow::get_turn() const {
  return m_turn;
}

void GameBoardWindow::set_turn(Board::Token turn) {
  m_turn = turn;
  auto turn_label = static_cast<QLabel*>(layout()->itemAt(1)->widget());
  if(m_turn == Board::Token::X) {
    turn_label->setText(QObject::tr("PLAYER X'S TURN"));
  } else if(m_turn == Board::Token::O) {
    turn_label->setText(QObject::tr("PLAYER O'S TURN"));
  }
}
