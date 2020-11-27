#include <doctest/doctest.h>
#include "TicTacToe/Library/GameModel.hpp"

using namespace TicTacToe;

TEST_SUITE("GameModel") {
  TEST_CASE("initial_game") {
    auto game = GameModel();
    REQUIRE(game.get_turn() == Board::Token::X);
    REQUIRE(game.get_board() == Board());
  }
}
