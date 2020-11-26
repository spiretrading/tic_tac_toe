#ifndef TIC_TAC_TOE_BOARD_HPP
#define TIC_TAC_TOE_BOARD_HPP
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace TicTacToe {

  /** Models a tic-tac-toe game board. */
  class Board {
    public:

      /** The number of rows on the board. */
      static constexpr auto ROW_COUNT = 3;

      /** The number of columns on the board. */
      static constexpr auto COLUMN_COUNT = 3;

      /** Represents a game piece. */
      enum class Token : std::uint8_t {

        /** An blank/empty square. */
        NONE,

        /** An X piece. */
        X,

        /** An O piece. */
        O
      };

      /**
       * Returns the piece at a given position.
       * @param x The x coordinate of the board position.
       * @param y The y coordinate of the board position.
       * @return The Token at the given coordinate.
       * @throws std::out_of_range if the x or y coordinate is outside of the
       *         board's range.
       */
      Token get_piece(int x, int y) const;

      /**
       * Places a Token on the board at a given position.
       * @param x The x coordinate of the board position.
       * @param y The y coordinate of the board position.
       * @param token The Token to place.
       * @throws std::out_of_range if the x or y coordinate is outside of the
       *         board's range.
       */
      void set_piece(int x, int y, Token token);

    private:

      /** Array of the board. */
      std::vector<std::vector<Token>> board_ = std::vector<std::vector<Token>>(
        ROW_COUNT, std::vector<Token>(COLUMN_COUNT, Token::NONE));
  };

  /**
   * Returns the Board Token representing the winner (or NONE if no winner).
   * @param board The Board to evaluate.
   */
  Board::Token evaluate_winner(const Board& board);
}

#endif
