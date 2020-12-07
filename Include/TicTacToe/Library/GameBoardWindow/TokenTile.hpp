#ifndef TIC_TAC_TOE_TOKEN_TILE_HPP
#define TIC_TAC_TOE_TOKEN_TILE_HPP
#include <QWidget>
#include "TicTacToe/Library/Board.hpp"
#include "TicTacToe/Library/TicTacToe.hpp"

namespace TicTacToe {

  /** Displays a single board tile. */
  class TokenTile : public QWidget {
    public:

      /** Signals the tile has been clicked. */
      using ClickedSignal = Signal<void ()>;

      /**
       * Constructs a TokenTile display no token.
       * @param parent The parent widget.
       */
      explicit TokenTile(QWidget* parent = nullptr);

      /**
       * Constructs a TokenTile displaying a token.
       * @param token The token to display.
       * @param parent The parent widget.
       */
      explicit TokenTile(Board::Token token, QWidget* parent = nullptr);

      /** Returns the displayed token. */
      Board::Token get_token() const;

      /** Sets the token to display. */
      void set_token(Board::Token token);

      /** Connects a slot to the ClickedSignal. */
      boost::signals2::connection connect_clicked_signal(
        const ClickedSignal::slot_type& slot) const;

    private:
      mutable ClickedSignal m_clickedSignal;
      Board::Token m_token;
  };
}

#endif
