#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "TicTacToe/Library/DrawConditionWindow.hpp"

using namespace boost::signals2;
using namespace TicTacToe;

DrawConditionWindow::DrawConditionWindow(QWidget* parent)
    : QWidget(parent) {
  setFixedSize(780, 514);
  setStyleSheet("background-color: #FFFFFF;");
  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addSpacing(100);
  auto exclamation_label = new QLabel(QObject::tr("OOPS, TOO BAD"), this);
  exclamation_label->setFixedHeight(38);
  exclamation_label->setAlignment(Qt::AlignCenter);
  exclamation_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;)");
  auto font = QFont("Open Sans");
  font.setLetterSpacing(QFont::AbsoluteSpacing, 1.6);
  font.setPixelSize(28);
  exclamation_label->setFont(font);
  layout->addWidget(exclamation_label);
  layout->addSpacing(10);
  auto draw_label = new QLabel(QObject::tr("IT ENDED DRAW"), this);
  draw_label->setFixedHeight(61);
  draw_label->setAlignment(Qt::AlignCenter);
  draw_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;
    font-family: Open Sans;
    font-size: 45px;
    font-weight: bold;)");
  layout->addWidget(draw_label);
  layout->addSpacing(80);
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
  layout->addSpacing(125);
  setLayout(layout);
  QObject::connect(start_button, &QPushButton::clicked,
    this, [this] { m_start_signal(); });
  QObject::connect(back_button, &QPushButton::clicked,
    this, [this] { m_back_signal(); });
}

connection DrawConditionWindow::connect_start_signal(
    const StartSignal::slot_type& slot) const {
  return m_start_signal.connect(slot);
}

connection DrawConditionWindow::connect_back_signal(
    const BackSignal::slot_type& slot) const {
  return m_back_signal.connect(slot);
}
