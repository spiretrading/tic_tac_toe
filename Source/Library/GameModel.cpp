#include "TicTacToe/Library/GameModel.hpp"

using namespace TicTacToe;

GameModel::GameModel() {}

const Board& GameModel::get_board() const {
  throw std::runtime_error("Not implemented.");
}

Board::Token GameModel::get_turn() const {
  throw std::runtime_error("Not implemented.");
}

GameModel::State GameModel::play_move(int x, int y) {
  throw std::runtime_error("Not implemented.");
}
