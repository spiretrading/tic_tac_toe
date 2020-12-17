#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "TicTacToe/Library/DrawConditionWindow.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace boost::signals2;
using namespace TicTacToe;

DrawConditionWindow::DrawConditionWindow(QWidget* parent)
    : QWidget(parent) {
  setFixedSize(scale(780, 514));
  setStyleSheet("background-color: #FFFFFF;");
  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addSpacing(scale_height(100));
  auto exclamation_label = new QLabel(QObject::tr("OOPS, TOO BAD"), this);
  exclamation_label->setFixedHeight(scale_height(38));
  exclamation_label->setAlignment(Qt::AlignCenter);
  exclamation_label->setStyleSheet(R"(
    background-color: #FFFFFF;
    color: #4B23A0;)");
  auto font = QFont("Open Sans");
  font.setLetterSpacing(QFont::AbsoluteSpacing, scale_width(1.6));
  font.setPixelSize(scale_width(28));
  exclamation_label->setFont(font);
  layout->addWidget(exclamation_label);
  layout->addSpacing(scale_height(10));
  auto draw_label = new QLabel(QObject::tr("IT ENDED DRAW"), this);
  draw_label->setFixedHeight(scale_height(61));
  draw_label->setAlignment(Qt::AlignCenter);
  draw_label->setStyleSheet(QString(R"(
    background-color: #FFFFFF;
    color: #4B23A0;
    font-family: Open Sans;
    font-size: %1px;
    font-weight: bold;)").arg(scale_width(45)));
  layout->addWidget(draw_label);
  layout->addSpacing(scale_height(80));
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
  layout->addSpacing(scale_height(125));
  setLayout(layout);
  connect(start_button, &QPushButton::clicked,
    this, [this] { m_start_signal(); });
  connect(back_button, &QPushButton::clicked,
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
