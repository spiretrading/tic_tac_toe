#ifndef TIC_TAC_TOE_BADGE_BOX_HPP
#define TIC_TAC_TOE_BADGE_BOX_HPP
#include <QWidget>

namespace TicTacToe {

  /** Displays a single badge in either the locked or unlocked state. */
  class BadgeBox : public QWidget {
    public:

      /** The opacity of the locked badge. */
      static constexpr auto LOCKED_OPACITY = 0.25;

      /** The opacity of the unlocked badge. */
      static constexpr auto UNLOCKED_OPACITY = 1.0;

      /** The states of the box. */
      enum class State {

        /** The badge is unlocked. */
        UNLOCKED,

        /** The badge is locked. */
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

    private:
      State m_state;
  };
}

#endif
