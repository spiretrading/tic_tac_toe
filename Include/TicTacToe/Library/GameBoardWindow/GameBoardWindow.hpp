#ifndef TIC_TAC_TOE_GAME_BOARD_WINDOW_HPP
#define TIC_TAC_TOE_GAME_BOARD_WINDOW_HPP
#include <QWidget>
#include "TicTacToe/Library/GameBoardWindow/BadgePanel.hpp"
#include "TicTacToe/Library/GameBoardWindow/GameBoardPanel.hpp"
#include "TicTacToe/Library/Board.hpp"

namespace TicTacToe {

  /** Displays the game board window. */
  class GameBoardWindow : public QWidget {
    public:

      /**
       * Constructs a GameBoardWindow.
       * @param board The Board to display.'
       * @param turn Specifics which player's turn it is.
       * @param parent The parent widget.
       */
      GameBoardWindow(const Board& board, Board::Token turn,
        QWidget* parent = nullptr);

      /** Returns player X's badge panel. */
      const BadgePanel& get_x_badge_panel() const;

      /** Returns player X's badge panel. */
      BadgePanel& get_x_badge_panel();

      /** Returns player O's badge panel. */
      const BadgePanel& get_o_badge_panel() const;

      /** Returns player O's badge panel. */
      BadgePanel& get_o_badge_panel();

      /** Returns game board panel. */
      const GameBoardPanel& get_panel() const;

      /** Returns game board panel. */
      GameBoardPanel& get_panel();

      /** Returns which player's turn it is. */
      Board::Token get_turn() const;

      /** Sets which player's turn it is. */
      void set_turn(Board::Token turn);
  };
}

#endif
