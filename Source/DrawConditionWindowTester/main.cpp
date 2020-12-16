#include <QApplication>
#include "TicTacToe/Library/DrawConditionWindow.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Draw Condition Window Tester"));
  initialize_resources();
  auto window = DrawConditionWindow();
  window.show();
  window.activateWindow();
  application->exec();
}
