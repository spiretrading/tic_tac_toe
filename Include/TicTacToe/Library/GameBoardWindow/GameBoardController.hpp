#ifndef TIC_TAC_TOE_GAME_BOARD_CONTROLLER_HPP
#define TIC_TAC_TOE_GAME_BOARD_CONTROLLER_HPP
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/GameBoardWindow/GameBoardWindow.hpp"
#include "TicTacToe/Library/GameModel.hpp"
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** The controller of the game board to execute the game logic. */
  class GameBoardController {
    public:

      /** Signals the game over with a winner of the game. */
      using GameOverSignal = Signal<void (Board::Token winner)>;

      /**
       * Constructs a game board controller.
       * @param x_badge_count The number of badges of player X.
       * @param o_badge_count The number of badges of player O.
       */
      GameBoardController(int x_badge_count, int o_badge_count);

      /** Returns the game board window. */
      GameBoardWindow& get_game_board_window();

      /** Connects a slot to the GameOverSignal. */
      boost::signals2::connection connect_game_over_signal(
        const GameOverSignal::slot_type& slot) const;

    private:
      mutable GameOverSignal m_game_over_signal;
      GameModel::State m_game_state;
      GameModel m_game_model;
      GameBoardWindow m_game_board_window;

      void on_game_board_clicked(int x, int y);
  };
}

#endif
