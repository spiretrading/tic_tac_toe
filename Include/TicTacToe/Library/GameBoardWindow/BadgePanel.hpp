#ifndef TIC_TAC_TOE_BADGE_PANEL_HPP
#define TIC_TAC_TOE_BADGE_PANEL_HPP
#include <QWidget>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/GameBoardWindow/BadgeBox.hpp"

namespace TicTacToe {

  /** Displays the player name and a grid of badges. */
  class BadgePanel : public QWidget {
    public:

      /**
       * Constructs a BadgePanel.
       * @param side Whether the panel displays badges for player X or O.
       * @param score The number of badges that are unlocked.
       * @param parent The parent widget.
       */
      explicit BadgePanel(Board::Token side, int score,
        QWidget* parent = nullptr);

      /** Returns the number of unlocked badges. */
      int get_score() const;

      /** Sets the number of unlocked badges. */
      void set_score(int score);
  };
}

#endif
