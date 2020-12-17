#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "TicTacToe/Library/WinConditionWindow.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace boost::signals2;
using namespace TicTacToe;

WinConditionWindow::WinConditionWindow(Board::Token winner, QWidget* parent)
    : QWidget(parent),
      m_winner(winner) {
  setFixedSize(scale(780, 514));
  setStyleSheet("background-color: #FFFFFF;");
  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addSpacing(scale_height(80));
  auto congratulations_label = new QLabel(QObject::tr("CONGRATULATIONS"), this);
  congratulations_label->setFixedHeight(scale_height(38));
  congratulations_label->setAlignment(Qt::AlignCenter);
  congratulations_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;)");
  auto font = QFont("Open Sans");
  font.setLetterSpacing(QFont::AbsoluteSpacing, scale_width(1.6));
  font.setPixelSize(scale_width(28));
  congratulations_label->setFont(font);
  layout->addWidget(congratulations_label);
  layout->addSpacing(scale_height(10));
  auto winner_label = new QLabel(this);
  winner_label->setFixedHeight(scale_height(61));
  winner_label->setAlignment(Qt::AlignCenter);
  winner_label->setText(QObject::tr("PLAYER %1 WON").arg([winner] {
    if(winner == Board::Token::X) {
      return "X";
    } else {
      return "O";
    }
  }()));
  winner_label->setStyleSheet(QString(R"(
    background-color: #FFFFFF;
    color: #4B23A0;
    font-family: Open Sans;
    font-size: %1px;
    font-weight: bold;)").arg(scale_width(45)));
  layout->addWidget(winner_label);
  layout->addSpacing(scale_height(50));
  auto badge_widget = new QWidget(this);
  badge_widget->setFixedSize(scale(60, 60));
  badge_widget->setStyleSheet("image: url(:/Icons/badge.png);");
  layout->addWidget(badge_widget, 0, Qt::AlignCenter);
  layout->addSpacing(scale_height(50));
  auto start_button = new QPushButton(QObject::tr("Start new round"), this);
  start_button->setFixedSize(scale(180, 40));
  start_button->setStyleSheet(QString(R"(
    QPushButton {
      background-color: #FFFFFF;
      color: #333333;
      border: None;
      font-family: Open Sans;
      font-size: %1px;
      padding: 0px;
    }
    QPushButton:hover:!pressed {
      border: %2px solid #333333;
      border-radius: %3px;
    })").arg(scale_width(18)).arg(scale_width(1)).arg(scale_width(3)));
  layout->addWidget(start_button, 0, Qt::AlignCenter);
  layout->addSpacing(scale_height(20));
  auto back_button = new QPushButton(QObject::tr("Back to main screen"), this);
  back_button->setFixedSize(scale(180, 40));
  back_button->setStyleSheet(QString(R"(
    QPushButton {
      background-color: #FFFFFF;
      color: #333333;
      border: None;
      font-family: Open Sans;
      font-size: %1px;
      padding: 0px;
    }
    QPushButton:hover:!pressed {
      border: %2px solid #333333;
      border-radius: %3px;
    })").arg(scale_width(14)).arg(scale_width(1)).arg(scale_width(3)));
  layout->addWidget(back_button, 0, Qt::AlignCenter);
  layout->addSpacing(scale_height(65));
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
