#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include "TicTacToe/Library/GameBoardWindow/BadgePanel.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

namespace {
  QWidget* MakeGameBoardWindow() {
    auto window = new QWidget();
    auto layout = new QVBoxLayout(window);
    window->setLayout(layout);
    auto palette = window->palette();
    palette.setColor(QPalette::Window, Qt::white);
    window->setPalette(palette);
    auto panel = new BadgePanel(Board::Token::X, 0, window);
    layout->addWidget(panel);
    return window;
  }

  QWidget* MakeControllerWindow(QWidget* gameBoardWindow) {
    auto window = new QWidget();
    window->setWindowTitle(QObject::tr("Window Controller"));
    auto layout = new QGridLayout(window);
    window->setLayout(layout);
    auto unlockedLabel = new QLabel(QObject::tr("X Unlocked Badges: "));
    layout->addWidget(unlockedLabel, 0, 0);
    auto unlockedSpinBox = new QSpinBox(window);
    unlockedSpinBox->setMinimum(0);
    unlockedSpinBox->setMaximum(9);
    QObject::connect(unlockedSpinBox, qOverload<int>(&QSpinBox::valueChanged),
      [=] (int value) {
        auto panel = static_cast<BadgePanel*>(
          gameBoardWindow->layout()->itemAt(0)->widget());
        panel->set_score(value);
      });
    layout->addWidget(unlockedSpinBox, 0, 1);
    return window;
  }
}

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Game Board Window Tester"));
  initialize_resources();
  auto gameBoardWindow = MakeGameBoardWindow();
  gameBoardWindow->activateWindow();
  gameBoardWindow->show();
  auto controller = MakeControllerWindow(gameBoardWindow);
  controller->show();
  application->exec();
}
