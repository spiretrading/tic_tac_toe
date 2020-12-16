#ifndef TIC_TAC_TOE_APPLICATION_CONTROLLER_HPP
#define TIC_TAC_TOE_APPLICATION_CONTROLLER_HPP
#include <memory>
#include <QWidget>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/GameBoardWindow/GameBoardController.hpp"
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** The controller of the application. */
  class ApplicationController {
    public:

      /**
       * Constructs an application controller.
       */
      ApplicationController();

      /**
       * Release resources of the application controller.
       */
      ~ApplicationController();

    private:
      int m_x_badge_count;
      int m_o_badge_count;
      QWidget m_application_window;
      std::unique_ptr<GameBoardController> m_game_board_controller;

      void show_title_window();
      void play();
      void game_over(Board::Token winner);
      void game_win(Board::Token winner);
      void game_draw();
  };
}

#endif
