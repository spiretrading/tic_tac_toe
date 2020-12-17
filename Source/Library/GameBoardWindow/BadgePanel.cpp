#include <QLabel>
#include <QVBoxLayout>
#include "TicTacToe/Library/GameBoardWindow/BadgePanel.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace TicTacToe;

BadgePanel::BadgePanel(Board::Token side, int score, QWidget* parent) :
  QWidget(parent),
  m_score(score) {
  setFixedWidth(scale_width(120));
  setStyleSheet("background-color: #FFFFFF;");
  auto panel_layout = new QVBoxLayout();
  panel_layout->setContentsMargins(0, 0, 0, 0);
  panel_layout->setSpacing(0);
  auto string_side = QString();
  if(side == Board::Token::X) {
    string_side = "X";
  } else if(side == Board::Token::O) {
    string_side = "O";
  }
  auto player_label = new QLabel(QObject::tr("PLAYER ") + string_side);
  player_label->setFixedHeight(scale_height(34));
  player_label->setAlignment(Qt::AlignCenter);
  player_label->setStyleSheet(QString(R"(
    background-color: #F5B43C;
    border-radius: %1px;
    color: #FFFFFF;
    font-family: Open Sans;
    font-size: %2px;)").arg(scale_width(3)).arg(scale_width(20)));
  panel_layout->addWidget(player_label);
  panel_layout->addSpacing(scale_height(15));
  m_badges_layout = new QGridLayout();
  m_badges_layout->setContentsMargins(0, 0, 0, 0);
  m_badges_layout->setHorizontalSpacing(scale_width(15));
  m_badges_layout->setVerticalSpacing(scale_height(15));
  for(auto i = 0; i < m_score; ++i) {
    auto badge = new BadgeBox(BadgeBox::State::UNLOCKED);
    badge->setFixedSize(scale(30, 30));
    m_badges_layout->addWidget(badge, i / 3, i % 3);
  }
  for(auto i = m_score; i < MAX_SCORE; ++i) {
    auto badge = new BadgeBox(BadgeBox::State::LOCKED);
    badge->setFixedSize(scale(30, 30));
    m_badges_layout->addWidget(badge, i / 3, i % 3);
  }
  panel_layout->addLayout(m_badges_layout);
  panel_layout->addStretch(1);
  setLayout(panel_layout);
}

int BadgePanel::get_score() const {
  return m_score;
}

void BadgePanel::set_score(int score) {
  m_score = score;
  for(auto i = 0; i < m_score; ++i) {
    static_cast<BadgeBox*>(m_badges_layout->itemAt(i)->widget())->set_state(
      BadgeBox::State::UNLOCKED);
  }
  for(auto i = m_score; i < MAX_SCORE; ++i) {
    static_cast<BadgeBox*>(m_badges_layout->itemAt(i)->widget())->set_state(
      BadgeBox::State::LOCKED);
  }
}
