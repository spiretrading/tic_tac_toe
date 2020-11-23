#include <doctest/doctest.h>
#include "TicTacToe/Library/Board.hpp"

using namespace TicTacToe;

TEST_SUITE("Board") {
  TEST_CASE("initial_board") {
    auto board = Board();
    for(auto x = 0; x < Board::ROW_COUNT; ++x) {
      for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
        REQUIRE(board.get_piece(0, 0) == Board::Token::NONE);
      }
    }
  }
}
