#ifndef TIC_TAC_TOE_BADGE_BOX_HPP
#define TIC_TAC_TOE_BADGE_BOX_HPP
#include <QWidget>

namespace TicTacToe {

  /** Displays a single badge in either the locked or unlocked state. */
  class BadgeBox : public QWidget {
    public:

      /** The states of the box. */
      enum class State {

        /** The badge is locked. */
        UNLOCKED,

        /** The badge is unlocked. */
        LOCKED
      };

      /**
       * Constructs a BadgeBox in a given state.
       * @param state The state of the box.
       * @param parent The parent widget.
       */
      explicit BadgeBox(State state, QWidget* parent = nullptr);

      /** Returns the state of the box. */
      State get_state() const;

      /** Sets the state of the box. */
      void set_state(State state);
  };
}

#endif
