#include <doctest/doctest.h>
#include "TicTacToe/Library/Board.hpp"

using namespace TicTacToe;

TEST_SUITE("Board") {
  TEST_CASE("initial_board") {
    auto board = Board();
    for(auto x = 0; x < Board::ROW_COUNT; ++x) {
      for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
        REQUIRE(board.get_piece(x, y) == Board::Token::NONE);
      }
    }
  }

  TEST_CASE("check_boundary") {
    auto board = Board();
    CHECK_THROWS(board.set_piece(-1, 0, Board::Token::X));
    CHECK_THROWS(board.set_piece(Board::ROW_COUNT, 0, Board::Token::X));
    CHECK_THROWS(board.set_piece(0, -1, Board::Token::X));
    CHECK_THROWS(board.set_piece(0, Board::COLUMN_COUNT, Board::Token::X));
    CHECK_THROWS(board.set_piece(-1, -1, Board::Token::X));
    CHECK_THROWS(board.set_piece(Board::ROW_COUNT, Board::COLUMN_COUNT, Board::Token::X));
    CHECK_THROWS(board.get_piece(-1, 0));
    CHECK_THROWS(board.get_piece(Board::ROW_COUNT, 0));
    CHECK_THROWS(board.get_piece(0, -1));
    CHECK_THROWS(board.get_piece(0, Board::COLUMN_COUNT));
    CHECK_THROWS(board.get_piece(-1, -1));
    CHECK_THROWS(board.get_piece(Board::ROW_COUNT, Board::COLUMN_COUNT));
  }

  TEST_CASE("access_board") {
    auto board = Board();
    board.set_piece(0, 0, Board::Token::O);
    CHECK(board.get_piece(0, 0) == Board::Token::O);
    board.set_piece(0, 0, Board::Token::X);
    CHECK(board.get_piece(0, 0) == Board::Token::X);
    board.set_piece(0, 0, Board::Token::NONE);
    CHECK(board.get_piece(0, 0) == Board::Token::NONE);
  }

  TEST_CASE("check_winner") {
    SUBCASE("empty_board") {
      auto board = Board();
      CHECK(evaluate_winner(board) == Board::Token::NONE);
    }

    SUBCASE("check_row") {
      auto board = Board();
      for(auto x = 0; x < Board::ROW_COUNT; ++x) {
        board.set_piece(x, 0, Board::Token::X);
      }
      CHECK(evaluate_winner(board) == Board::Token::X);
    }

    SUBCASE("check_column") {
      auto board = Board();
      for(auto y = 0; y < Board::COLUMN_COUNT; ++y) {
        board.set_piece(Board::ROW_COUNT - 1, y, Board::Token::O);
      }
      CHECK(evaluate_winner(board) == Board::Token::O);
    }

    SUBCASE("check_diagnal") {
      auto board = Board();
      for(auto x = 0; x < Board::ROW_COUNT; ++x) {
        board.set_piece(x, x, Board::Token::X);
      }
      CHECK(evaluate_winner(board) == Board::Token::X);
    }

    SUBCASE("check_reverse_diagnal") {
      auto board = Board();
      for(auto x = 0; x < Board::ROW_COUNT; ++x) {
        board.set_piece(x, Board::COLUMN_COUNT - 1 - x, Board::Token::O);
      }
      CHECK(evaluate_winner(board) == Board::Token::O);
    }

    SUBCASE("full_without_winner") {
      /**
         O | X | O
         O | X | X
         X | O | X 
      */
      auto board = Board();
      board.set_piece(0, 0, Board::Token::O);
      board.set_piece(0, 1, Board::Token::X);
      board.set_piece(0, 2, Board::Token::O);
      board.set_piece(1, 0, Board::Token::O);
      board.set_piece(1, 1, Board::Token::X);
      board.set_piece(1, 2, Board::Token::X);
      board.set_piece(2, 0, Board::Token::X);
      board.set_piece(2, 1, Board::Token::O);
      board.set_piece(2, 2, Board::Token::X);
      CHECK(evaluate_winner(board) == Board::Token::NONE);
    }

    SUBCASE("full_with_winner1") {
      /**
         X | X | O
         O | X | X
         O | O | X 
      */
      auto board = Board();
      board.set_piece(0, 0, Board::Token::X);
      board.set_piece(0, 1, Board::Token::X);
      board.set_piece(0, 2, Board::Token::O);
      board.set_piece(1, 0, Board::Token::O);
      board.set_piece(1, 1, Board::Token::X);
      board.set_piece(1, 2, Board::Token::X);
      board.set_piece(2, 0, Board::Token::O);
      board.set_piece(2, 1, Board::Token::O);
      board.set_piece(2, 2, Board::Token::X);
      CHECK(evaluate_winner(board) == Board::Token::X);
    }

    SUBCASE("full_with_winner2") {
      /**
         X | X | O
         O | O | O
         X | O | X 
      */
      auto board = Board();
      board.set_piece(0, 0, Board::Token::X);
      board.set_piece(0, 1, Board::Token::X);
      board.set_piece(0, 2, Board::Token::O);
      board.set_piece(1, 0, Board::Token::O);
      board.set_piece(1, 1, Board::Token::O);
      board.set_piece(1, 2, Board::Token::O);
      board.set_piece(2, 0, Board::Token::X);
      board.set_piece(2, 1, Board::Token::O);
      board.set_piece(2, 2, Board::Token::X);
      CHECK(evaluate_winner(board) == Board::Token::O);
    }
  }
}
