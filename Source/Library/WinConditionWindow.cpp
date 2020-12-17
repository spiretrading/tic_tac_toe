#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "TicTacToe/Library/WinConditionWindow.hpp"

using namespace boost::signals2;
using namespace TicTacToe;

WinConditionWindow::WinConditionWindow(Board::Token winner, QWidget* parent)
    : QWidget(parent),
      m_winner(winner) {
  setFixedSize(780, 514);
  setStyleSheet("background-color: #FFFFFF;");
  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addSpacing(80);
  auto congratulations_label = new QLabel(QObject::tr("CONGRATULATIONS"), this);
  congratulations_label->setFixedHeight(38);
  congratulations_label->setAlignment(Qt::AlignCenter);
  congratulations_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;)");
  auto font = QFont("Open Sans");
  font.setLetterSpacing(QFont::AbsoluteSpacing, 1.6);
  font.setPixelSize(28);
  congratulations_label->setFont(font);
  layout->addWidget(congratulations_label);
  layout->addSpacing(10);
  auto winner_label = new QLabel(this);
  winner_label->setFixedHeight(61);
  winner_label->setAlignment(Qt::AlignCenter);
  winner_label->setText(QObject::tr("PLAYER %1 WON").arg([winner] {
    if(winner == Board::Token::X) {
      return "X";
    } else {
      return "O";
    }
  }()));
  winner_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;
    font-family: Open Sans;
    font-size: 45px;
    font-weight: bold;)");
  layout->addWidget(winner_label);
  layout->addSpacing(50);
  auto badge_widget = new QWidget(this);
  badge_widget->setFixedSize(60, 60);
  badge_widget->setStyleSheet("image: url(:/Icons/badge.png);");
  layout->addWidget(badge_widget, 0, Qt::AlignCenter);
  layout->addSpacing(50);
  auto start_button = new QPushButton(QObject::tr("Start new round"), this);
  start_button->setFixedSize(180, 40);
  start_button->setStyleSheet(R"(
    QPushButton {
      background-color: #FFFFFF;
      color: #333333;
      border: None;
      font-family: Open Sans;
      font-size: 18px;
      padding: 0px;
    }
    QPushButton:hover:!pressed {
      border: 1px solid #333333;
      border-radius: 3px;
    })");
  layout->addWidget(start_button, 0, Qt::AlignCenter);
  layout->addSpacing(20);
  auto back_button = new QPushButton(QObject::tr("Back to main screen"), this);
  back_button->setFixedSize(180, 40);
  back_button->setStyleSheet(R"(
    QPushButton {
      background-color: #FFFFFF;
      color: #333333;
      border: None;
      font-family: Open Sans;
      font-size: 14px;
      padding: 0px;
    }
    QPushButton:hover:!pressed {
      border: 1px solid #333333;
      border-radius: 3px;
    })");
  layout->addWidget(back_button, 0, Qt::AlignCenter);
  layout->addSpacing(65);
  setLayout(layout);
  connect(start_button, &QPushButton::clicked,
    this, [this] { m_start_signal(); });
  connect(back_button, &QPushButton::clicked,
    this, [this] { m_back_signal(); });
}

Board::Token WinConditionWindow::get_winner() const {
  return m_winner;
}

connection WinConditionWindow::connect_start_signal(
    const StartSignal::slot_type& slot) const {
  return m_start_signal.connect(slot);
}

connection WinConditionWindow::connect_back_signal(
    const BackSignal::slot_type& slot) const {
  return m_back_signal.connect(slot);
}
