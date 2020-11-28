#ifndef TIC_TAC_TOE_BOARD_HPP
#define TIC_TAC_TOE_BOARD_HPP
#include <array>
#include <cstdint>
#include <stdexcept>

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
       * Constructs a empty Board where all pieces are Toke::NONE.
       */
      Board();

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

      /** Tests a Board for coordinate-wise equality. */
      bool operator ==(const Board& board) const;

      /** Tests a Board for coordinate-wise inequality. */
      bool operator !=(const Board& board) const;

    private:

      /** Array of the board. */
      std::array<std::array<Token, COLUMN_COUNT>, ROW_COUNT> m_board;
  };

  /**
   * Returns the Board Token representing the winner (or NONE if no winner).
   * @param board The Board to evaluate.
   */
  Board::Token evaluate_winner(const Board& board);
}

#endif
