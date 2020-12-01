#include "TicTacToe/Library/GameBoardWindow/BadgeBox.hpp"

using namespace TicTacToe;

BadgeBox::BadgeBox(State state, QWidget* parent)
  : QWidget(parent) {}

BadgeBox::State BadgeBox::get_state() const {
  return BadgeBox::State::UNLOCKED;
}

void BadgeBox::set_state(State state) {}
