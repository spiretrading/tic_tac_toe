#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP
#include <boost/signals2/dummy_mutex.hpp>
#include <boost/signals2/signal_type.hpp>
#ifdef _DEBUG
  #include <QDebug>
#endif

namespace TicTacToe {
  class Board;
  class GameModel;
  class TitleWindow;

  /** Defines the common type of boost signal used throughout Spire. */
  template<typename F>
  using Signal = typename boost::signals2::signal_type<F,
    boost::signals2::keywords::mutex_type<boost::signals2::dummy_mutex>>::type;
}

#endif
