#include <QApplication>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/GameBoardWindow/GameBoardPanel.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Game Board Window Tester"));
  initialize_resources();
  auto board = Board();
  auto game_board = new GameBoardPanel(board);
  game_board->connect_clicked_signal([&] (int x, int y) {
    auto token = board.get_piece(x, y);
    auto next_token = (static_cast<int>(token) + 1) % 3;
    board.set_piece(x, y, static_cast<Board::Token>(next_token));
    game_board->refresh_board();
  });
  game_board->activateWindow();
  game_board->show();
  application->exec();
}
