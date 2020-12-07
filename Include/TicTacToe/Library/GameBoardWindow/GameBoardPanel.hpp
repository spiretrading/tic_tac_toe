#ifndef TIC_TAC_TOE_GAME_BOARD_PANEL_HPP
#define TIC_TAC_TOE_GAME_BOARD_PANEL_HPP
#include <QWidget>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** Displays a game board. */
  class GameBoardPanel : public QWidget {
    public:

      /**
       * Signals a tile has been clicked.
       * @param x The x-coordinate of the tile clicked.
       * @param x The y-coordinate of the tile clicked.
       */
      using ClickedSignal = Signal<void (int x, int y)>;

      /**
       * Constructs a GameBoardPanel displaying a given Board.
       * @param board The Board to display.
       * @param parent The parent widget.
       */
      explicit GameBoardPanel(const Board& board, QWidget* parent = nullptr);

      /** Indicates the displayed Board has been updated. */
      void refresh_board();

      /** Connects a slot to the ClickedSignal. */
      boost::signals2::connection connect_clicked_signal(
        const ClickedSignal::slot_type& slot) const;

    private:
      mutable ClickedSignal m_clickedSignal;
      const Board* m_board;
  };
}

#endif
