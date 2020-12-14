#include <memory>
#include <QApplication>
#include <QTimer>
#include "TicTacToe/Library/GameBoardWindow/GameBoardController.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

void handle_game_over(std::unique_ptr<GameBoardController>& controller,
    int& x_badge_count, int& o_badge_count) {
  controller->connect_game_over_signal([&] (Board::Token winner) {
    if(winner == Board::Token::X) {
      ++x_badge_count;
      if(x_badge_count > 9) {
        x_badge_count = 1;
        o_badge_count = 0;
      }
    } else if(winner == Board::Token::O) {
      ++o_badge_count;
      if(o_badge_count > 9) {
        x_badge_count = 0;
        o_badge_count = 1;
      }
    }
    QTimer::singleShot(1000, [&] () {
      controller = std::make_unique<GameBoardController>(x_badge_count,
        o_badge_count);
      handle_game_over(controller, x_badge_count, o_badge_count);
    });
  });
}

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Game Board Controller Tester"));
  initialize_resources();
  auto x_badge_count = 0;
  auto o_badge_count = 0;
  auto controller = std::make_unique<GameBoardController>(x_badge_count,
    o_badge_count);
  handle_game_over(controller, x_badge_count, o_badge_count);
  application->exec();
}