#include <QLabel>
#include <QPushButton>
#include "TicTacToe/Library/TitleWindow.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace boost;
using namespace boost::signals2;
using namespace TicTacToe;

TitleWindow::TitleWindow(QWidget* parent)
    : QWidget(parent) {
  auto font = QFont("Open Sans");
  setFixedSize(scale(780, 514));
  setStyleSheet("background-color: #FFFFFF;");
  auto title_label = new QLabel(this);
  title_label->setText(QObject::tr("TIC TAC TOE"));
  title_label->setGeometry(QRect(translate(0, 100), scale(780, 61)));
  title_label->setAlignment(Qt::AlignCenter);
  title_label->setStyleSheet("color: #4B23A0;");
  font.setPixelSize(scale_width(45));
  font.setWeight(QFont::Bold);
  font.setLetterSpacing(QFont::AbsoluteSpacing, 0);
  title_label->setFont(font);
  auto description_label = new QLabel(this);
  description_label->setText(QObject::tr("A STRESS FREE GAME FOR TWO PLAYERS"));
  description_label->setGeometry(QRect(translate(0, 181), scale(780, 19)));
  description_label->setAlignment(Qt::AlignCenter);
  description_label->setStyleSheet("color: #333333;");
  font.setPixelSize(scale_width(14));
  font.setWeight(QFont::Normal);
  font.setLetterSpacing(QFont::AbsoluteSpacing, 1.6);
  description_label->setFont(font);
  auto footer_label = new QLabel(this);
  footer_label->setText(QObject::tr("Designed and developed by Spire."));
  footer_label->setGeometry(QRect(translate(0, 414), scale(780, 17)));
  footer_label->setAlignment(Qt::AlignCenter);
  footer_label->setStyleSheet("color: #8C8C8C;");
  font.setPixelSize(scale_width(12));
  font.setWeight(QFont::Normal);
  font.setLetterSpacing(QFont::AbsoluteSpacing, 0);
  footer_label->setFont(font);
  auto play_now_button = new QPushButton(this);
  play_now_button->setText(QObject::tr("PLAY NOW"));
  play_now_button->setGeometry(QRect(translate(290, 250), scale(200, 64)));
  font.setPixelSize(scale_width(20));
  font.setWeight(QFont::Light);
  font.setLetterSpacing(QFont::AbsoluteSpacing, scale_width(4.8));
  play_now_button->setFont(font);
  play_now_button->setStyleSheet(QString(R"(
    QPushButton {
      background-color: #4B23A0;
      border-radius: %1px;
      color: #FFFFFF;
      padding: 0px;
    }
    QPushButton:hover:!pressed {
      background-color: #684BC7;
    })").arg(scale_width(3)));
  connect(play_now_button, &QPushButton::clicked, this,
    [=] { m_play_now_signal(); });
}

connection TitleWindow::connect_play_now_signal(
    const PlayNowSignal::slot_type& slot) const {
  return m_play_now_signal.connect(slot);
}
