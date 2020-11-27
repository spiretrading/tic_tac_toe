#include <QApplication>
#include "TicTacToe/Library/TitleWindow.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Title Window Tester"));
  initialize_resources();
  auto window = TitleWindow();
  window.show();
  window.activateWindow();
  application->exec();
}
