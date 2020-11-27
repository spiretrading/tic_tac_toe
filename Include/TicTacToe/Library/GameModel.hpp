#ifndef TIC_TAC_TOE_GAME_MODEL_HPP
#define TIC_TAC_TOE_GAME_MODEL_HPP
#include "TicTacToe/Library/Board.hpp"

namespace TicTacToe {

  /**
   * Manages the state of a tic-tac-toe game. The GameBoard initially
   * represents a new game of tic-tac-toe and methods are provided to play
   * a move on the tic-tac-toe Board as well as get the current state of the
   * Board.
   */
  class GameModel {
    public:

      /** Represents the state of a tic-tac-toe game. */
      enum class State {

        /** The move played was invalid. */
        INVALID,

        /** The game continues. */
        CONTINUE,

        /**
         * The game has concluded, either there is a winner or the game is a
         * draw.
         */
        END
     };

      /**
       * Constructs a GameModel with an empty board and where it is X's turn to
       * play.
       */
      GameModel();

      /** Returns the state of the Board. */
      const Board& get_board() const;

      /** Returns whose turn it is to play a move. */
      Board::Token get_turn() const;

      /**
       * Updates the model by playing a move.
       * @param x The x-coordinate of the move to play.
       * @param y The y-coordinate of the move to play.
       * @return A code indicating the state of the game after the move.
       * @throws std::out_of_range if the x or y coordinate is outside of the
       *         board's range.
       */
      State play_move(int x, int y);

    private:

      /** The game board. */
      Board m_board;
      /** The state of the game. */
      State m_state;
      /** The current turn to play a move. */
      Board::Token m_turn;
      /** The number of moves */
      int m_moves;
  };
}

#endif
