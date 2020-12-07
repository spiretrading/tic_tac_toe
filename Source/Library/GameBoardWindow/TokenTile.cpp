#include <QPushButton>
#include "TicTacToe/Library/GameBoardWindow/TokenTile.hpp"

using namespace boost;
using namespace boost::signals2;
using namespace TicTacToe;

TokenTile::TokenTile(QWidget* parent)
  : TokenTile(Board::Token::NONE, parent) {
}

TokenTile::TokenTile(Board::Token token, QWidget* parent)
  : QWidget(parent)
  , m_token(token) {
  setFixedSize(100, 100);
  auto button = new QPushButton(this);
  button->setGeometry(0, 0, width(), height());
  set_token(token);
  QObject::connect(button, &QPushButton::clicked,
    this, [&] { this->m_clickedSignal(); });
}

Board::Token TokenTile::get_token() const {
  return m_token;
}

void TokenTile::set_token(Board::Token token) {
  m_token = token;
  auto button = findChild<QPushButton*>();
  if(m_token == Board::Token::X) {
    button->setStyleSheet(R"(
      QPushButton {
        background-color: #F2F2FF;
        border-color: #F2F2FF;
        border-radius: 3px;
        border-style: solid;
        border-width: 1px;
        image: url(:/Icons/x.png);
        image-position: center;
        padding: 35px;
      })");
  } else if(m_token == Board::Token::O) {
    button->setStyleSheet(R"(
      QPushButton {
        background-color: #F2F2FF;
        border-color: #F2F2FF;
        border-radius: 3px;
        border-style: solid;
        border-width: 1px;
        image: url(:/Icons/o.png);
        image-position: center;
        padding: 35px;
      })");
  } else {
    button->setStyleSheet(R"(
      QPushButton {
        background-color: #E2E0FF;
        border-color: #E2E0FF;
        border-radius: 3px;
        border-style: solid;
        border-width: 1px;
      }
      QPushButton:hover {
        border-color: #4B23A0;
      })");
  }
}

connection TokenTile::connect_clicked_signal(
  const ClickedSignal::slot_type& slot) const {
  return m_clickedSignal.connect(slot);
}
