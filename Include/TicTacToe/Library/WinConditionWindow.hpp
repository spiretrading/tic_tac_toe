#ifndef TIC_TAC_TOE_WIN_CONDITION_WINDOW_HPP
#define TIC_TAC_TOE_WIN_CONDITION_WINDOW_HPP
#include <QWidget>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** Displays the TicTacToe win condition window. */
  class WinConditionWindow : public QWidget {
    public:

      /** Signals that the Start new round button has been clicked. */
      using StartSignal = Signal<void ()>;

      /** Signals that the Back to main screen button has been clicked. */
      using BackSignal = Signal<void ()>;

      /**
       * Constructs a WinConditionWindow.
       * @param winner The winner of the game.
       * @param parent The parent window.
       */
      explicit WinConditionWindow(Board::Token winner,
        QWidget* parent = nullptr);

      /** Returns the winner. */
      Board::Token get_winner() const;

      /** Connects a slot to the start signal. */
      boost::signals2::connection connect_start_signal(
        const StartSignal::slot_type& slot) const;

      /** Connects a slot to the back signal. */
      boost::signals2::connection connect_back_signal(
        const BackSignal::slot_type& slot) const;

    private:
      mutable StartSignal m_start_signal;
      mutable BackSignal m_back_signal;
      Board::Token m_winner;
  };
}

#endif
