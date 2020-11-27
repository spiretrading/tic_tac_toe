#include <doctest/doctest.h>
#include "TicTacToe/Library/GameModel.hpp"

using namespace TicTacToe;

TEST_SUITE("GameModel") {
  TEST_CASE("initial_game") {
    auto game = GameModel();
    REQUIRE(game.get_turn() == Board::Token::X);
    REQUIRE(game.get_board() == Board());
  }

  TEST_CASE("check_boundary") {
    auto game = GameModel();
    CHECK_THROWS(game.play_move(-1, 0));
    CHECK_THROWS(game.play_move(Board::ROW_COUNT, 0));
    CHECK_THROWS(game.play_move(-1, 0));
    CHECK_THROWS(game.play_move(0, Board::COLUMN_COUNT));
  }

  TEST_CASE("play_game") {
    SUBCASE("check_state") {
      auto game = GameModel();
      CHECK(game.play_move(0, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(0, 0) == GameModel::State::INVALID);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(1, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(1, 0) == GameModel::State::INVALID);
      CHECK(game.get_turn() == Board::Token::X);
    }

    SUBCASE("has_winner") {
      auto game = GameModel();
      CHECK(game.play_move(0, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(1, 1) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(0, 1) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(1, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(0, 0) == GameModel::State::INVALID);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(1, 0) == GameModel::State::INVALID);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(0, 2) == GameModel::State::END);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(0, 0) == GameModel::State::END);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(2, 2) == GameModel::State::END);
      CHECK(game.get_turn() == Board::Token::X);
    }

    SUBCASE("no_winner") {
      auto game = GameModel();
      CHECK(game.play_move(0, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(1, 1) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(0, 1) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(0, 2) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(2, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(1, 0) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(1, 2) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::O);
      CHECK(game.play_move(2, 2) == GameModel::State::CONTINUE);
      CHECK(game.get_turn() == Board::Token::X);
      CHECK(game.play_move(2, 1) == GameModel::State::END);
      CHECK(game.play_move(0, 0) == GameModel::State::END);
    }
  }
}
