#include <QApplication>
#include "TicTacToe/Library/Resources.hpp"
#include "TicTacToe/Library/WinConditionWindow.hpp"

using namespace TicTacToe;

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Win Condition Window Tester"));
  initialize_resources();
  auto window = WinConditionWindow(Board::Token::X);
  window.show();
  window.activateWindow();
  application->exec();
}
