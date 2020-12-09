#include <QApplication>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include "TicTacToe/Library/GameBoardWindow/GameBoardWindow.hpp"
#include "TicTacToe/Library/Resources.hpp"

using namespace TicTacToe;

namespace {
  QWidget* make_game_board_window(const Board& board) {
    auto window = new QWidget();
    auto board_window = new GameBoardWindow(board, Board::Token::X, window);
    window->setFixedSize(780, 514);
    return window;
  }

  QWidget* make_controller_window(QWidget* game_board_window) {
    auto board_window = game_board_window->findChild<GameBoardWindow*>();
    auto window = new QWidget();
    window->setWindowTitle(QObject::tr("Window Controller"));
    auto layout = new QGridLayout(window);
    window->setLayout(layout);
    auto player_label = new QLabel(QObject::tr("Player: "), window);
    layout->addWidget(player_label, 0, 0);
    auto turn_combo_box = new QComboBox(window);
    turn_combo_box->addItem(QObject::tr("X"));
    turn_combo_box->addItem(QObject::tr("O"));
    board_window->set_turn(Board::Token::X);
    layout->addWidget(turn_combo_box, 0, 1);
    auto unlocked_label = new QLabel(QObject::tr("Unlocked Badges: "), window);
    layout->addWidget(unlocked_label, 1, 0);
    auto unlocked_spin_box = new QSpinBox(window);
    unlocked_spin_box->setMinimum(0);
    unlocked_spin_box->setMaximum(9);
    QObject::connect(turn_combo_box, &QComboBox::currentTextChanged,
      [=] (const QString& text) {
        if(text == "X") {
          board_window->set_turn(Board::Token::X);
          board_window->get_x_badge_panel().set_score(
            unlocked_spin_box->value());
        } else {
          board_window->set_turn(Board::Token::O);
          board_window->get_o_badge_panel().set_score(
            unlocked_spin_box->value());
        }
      });
    QObject::connect(unlocked_spin_box, qOverload<int>(&QSpinBox::valueChanged),
      [=] (int value) {
        if(turn_combo_box->currentText() == "X") {
          board_window->get_x_badge_panel().set_score(value);
        } else {
          board_window->get_o_badge_panel().set_score(value);
        }
      });
    layout->addWidget(unlocked_spin_box, 1, 1);
    return window;
  }
}  // namespace

int main(int argc, char** argv) {
  auto application = new QApplication(argc, argv);
  application->setOrganizationName(QObject::tr("Spire Trading Inc"));
  application->setApplicationName(QObject::tr("Game Board Window Tester"));
  initialize_resources();
  auto board = Board();
  auto game_board_window = make_game_board_window(board);
  auto board_window = game_board_window->findChild<GameBoardWindow*>();
  board_window->get_panel().connect_clicked_signal([&] (int x, int y) {
    auto token = board.get_piece(x, y);
    auto next_token = (static_cast<int>(token) + 1) % 3;
    board.set_piece(x, y, static_cast<Board::Token>(next_token));
    board_window->get_panel().refresh_board();
  });
  game_board_window->activateWindow();
  game_board_window->show();
  auto controller = make_controller_window(game_board_window);
  controller->show();
  application->exec();
}
