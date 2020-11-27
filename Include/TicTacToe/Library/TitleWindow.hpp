#ifndef TIC_TAC_TOE_TITLE_WINDOW_HPP
#define TIC_TAC_TOE_TITLE_WINDOW_HPP
#include <QWidget>
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** Displays the TicTacToe title window. */
  class TitleWindow : public QWidget {
    public:

      /** Signals that the PLAY NOW button has been clicked. */
      using PlayNowSignal = Signal<void ()>;

      /**
       * Constructs a TitleWindow.
       * @param parent The parent window.
       */
      explicit TitleWindow(QWidget* parent = nullptr);

      /** Connects a slot to the play now signal. */
      boost::signals2::connection connect_play_now_signal(
        const PlayNowSignal::slot_type& slot) const;

    private:
      mutable PlayNowSignal m_play_now_signal;
  };
}

#endif
