#include "TicTacToe/Library/TitleWindow.hpp"

using namespace boost;
using namespace boost::signals2;
using namespace TicTacToe;

TitleWindow::TitleWindow(QWidget* parent)
  : QWidget(parent) {}

connection TitleWindow::connect_play_now_signal(
    const PlayNowSignal::slot_type& slot) const {
  return m_play_now_signal.connect(slot);
}
