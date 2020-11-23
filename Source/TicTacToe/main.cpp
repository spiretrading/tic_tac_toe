#include <QApplication>
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Tic Tac Toe"));
  initialize_resources();
  application->exec();
}
