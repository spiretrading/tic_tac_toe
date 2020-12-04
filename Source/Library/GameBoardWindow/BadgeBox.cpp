#include <QGraphicsOpacityEffect>
#include "TicTacToe/Library/GameBoardWindow/BadgeBox.hpp"

using namespace TicTacToe;

BadgeBox::BadgeBox(State state, QWidget* parent)
  : QWidget(parent) {
  setStyleSheet("image: url(:/Icons/badge.png);");
  set_state(state);
}

BadgeBox::State BadgeBox::get_state() const {
  return m_state;
}

void BadgeBox::set_state(State state) {
  m_state = state;
  auto opacity_effect = new QGraphicsOpacityEffect(this);
  if(m_state == State::UNLOCKED) {
    opacity_effect->setOpacity(UNLOCKED_OPACITY);
  } else {
    opacity_effect->setOpacity(LOCKED_OPACITY);
  }
  setGraphicsEffect(opacity_effect);
}
