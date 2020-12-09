#include <QApplication>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include "TicTacToe/Library/GameBoardWindow/GameBoardWindow.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

namespace {
  QWidget* MakeGameBoardWindow(const Board& board) {
    auto window = new QWidget();
    auto board_window = new GameBoardWindow(board, Board::Token::X, window);
    window->setFixedSize(780, 514);
    return window;
  }

  QWidget* MakeControllerWindow(QWidget* gameBoardWindow) {
    auto board_window = gameBoardWindow->findChild<GameBoardWindow*>();
    auto window = new QWidget();
    window->setWindowTitle(QObject::tr("Window Controller"));
    auto layout = new QGridLayout(window);
    window->setLayout(layout);
    auto player_label = new QLabel(QObject::tr("Player: "), window);
    layout->addWidget(player_label, 0, 0);
    auto turn_combobox = new QComboBox(window);
    turn_combobox->addItem(QObject::tr("X"));
    turn_combobox->addItem(QObject::tr("O"));
    board_window->set_turn(Board::Token::X);
    layout->addWidget(turn_combobox, 0, 1);
    auto unlocked_label = new QLabel(QObject::tr("Unlocked Badges: "), window);
    layout->addWidget(unlocked_label, 1, 0);
    auto unlocked_spinBox = new QSpinBox(window);
    unlocked_spinBox->setMinimum(0);
    unlocked_spinBox->setMaximum(9);
    QObject::connect(turn_combobox, &QComboBox::currentTextChanged,
      [=] (const QString& text) {
        if(text == "X") {
          board_window->set_turn(Board::Token::X);
          board_window->get_x_badge_panel().set_score(
            unlocked_spinBox->value());
        } else {
          board_window->set_turn(Board::Token::O);
          board_window->get_o_badge_panel().set_score(
            unlocked_spinBox->value());
        }
      });
    QObject::connect(unlocked_spinBox, qOverload<int>(&QSpinBox::valueChanged),
      [=] (int value) {
        if(turn_combobox->currentText() == "X") {
          board_window->get_x_badge_panel().set_score(value);
        } else {
          board_window->get_o_badge_panel().set_score(value);
        }
      });
    layout->addWidget(unlocked_spinBox, 1, 1);
    return window;
  }
}  // namespace

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Game Board Window Tester"));
  initialize_resources();
  auto board = Board();
  auto gameBoardWindow = MakeGameBoardWindow(board);
  auto board_window = gameBoardWindow->findChild<GameBoardWindow*>();
  board_window->get_panel().connect_clicked_signal([&] (int x, int y) {
    auto token = board.get_piece(x, y);
    auto next_token = (static_cast<int>(token) + 1) % 3;
    board.set_piece(x, y, static_cast<Board::Token>(next_token));
    board_window->get_panel().refresh_board();
  });
  gameBoardWindow->activateWindow();
  gameBoardWindow->show();
  auto controller = MakeControllerWindow(gameBoardWindow);
  controller->show();
  application->exec();
}
