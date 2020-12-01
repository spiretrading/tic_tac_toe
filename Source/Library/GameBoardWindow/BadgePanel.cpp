#include "TicTacToe/Library/GameBoardWindow/BadgePanel.hpp"

using namespace TicTacToe;

BadgePanel::BadgePanel(Board::Token side, int score, QWidget* parent)
  : QWidget(parent) {}

int BadgePanel::get_score() const {
  return 0;
}

void BadgePanel::set_score(int score) {}
