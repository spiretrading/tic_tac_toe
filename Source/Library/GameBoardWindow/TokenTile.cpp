#include <QPushButton>
#include "TicTacToe/Library/GameBoardWindow/TokenTile.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace boost;
using namespace boost::signals2;
using namespace TicTacToe;

TokenTile::TokenTile(QWidget* parent)
    : TokenTile(Board::Token::NONE, parent) {}

TokenTile::TokenTile(Board::Token token, QWidget* parent)
    : QWidget(parent),
      m_token(token) {
  setFixedSize(scale(100, 100));
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
    button->setStyleSheet(QString(R"(
      QPushButton {
        background-color: #F2F2FF;
        border-color: #F2F2FF;
        border-radius: %1px;
        border-style: solid;
        border-width: %2px;
        image: url(:/Icons/x.png);
        image-position: center;
        padding: %3px;
      })").arg(scale_width(3)).arg(scale_width(1)).arg(scale_width(35)));
  } else if(m_token == Board::Token::O) {
    button->setStyleSheet(QString(R"(
      QPushButton {
        background-color: #F2F2FF;
        border-color: #F2F2FF;
        border-radius: %1px;
        border-style: solid;
        border-width: %2px;
        image: url(:/Icons/o.png);
        image-position: center;
        padding: %3px;
      })").arg(scale_width(3)).arg(scale_width(1)).arg(scale_width(35)));
  } else {
    button->setStyleSheet(QString(R"(
      QPushButton {
        background-color: #E2E0FF;
        border-color: #E2E0FF;
        border-radius: %1px;
        border-style: solid;
        border-width: %2px;
      }
      QPushButton:hover {
        border-color: #4B23A0;
      })").arg(scale_width(3)).arg(scale_width(1)));
  }
}

connection TokenTile::connect_clicked_signal(
    const ClickedSignal::slot_type& slot) const {
  return m_clickedSignal.connect(slot);
}
