#include <QGridLayout>
#include "TicTacToe/Library/GameBoardWindow/GameBoardPanel.hpp"
#include "TicTacToe/Library/GameBoardWindow/TokenTile.hpp"
#include "TicTacToe/Library/Scaling.hpp"

using namespace boost;
using namespace boost::signals2;
using namespace TicTacToe;

GameBoardPanel::GameBoardPanel(const Board& board, QWidget* parent)
    : QWidget(parent),
      m_board(&board) {
  setFixedSize(scale(304, 304));
  setStyleSheet("background-color: #FFFFFF;");
  auto panel_layout = new QGridLayout(this);
  panel_layout->setContentsMargins(0, 0, 0, 0);
  panel_layout->setHorizontalSpacing(scale_width(2));
  panel_layout->setVerticalSpacing(scale_height(2));
  for(auto i = 0; i < Board::ROW_COUNT; ++i) {
    for(auto j = 0; j < Board::COLUMN_COUNT; ++j) {
      auto tile = new TokenTile(this);
      tile->connect_clicked_signal([=] {
        m_clickedSignal(i, j);
      });
      panel_layout->addWidget(tile, i, j);
    }
  }
  setLayout(panel_layout);
}

void GameBoardPanel::refresh_board() {
  auto panel_layout = static_cast<QGridLayout*>(layout());
  for(auto i = 0; i < Board::ROW_COUNT; ++i) {
    for(auto j = 0; j < Board::COLUMN_COUNT; ++j) {
      auto tile = static_cast<TokenTile*>(panel_layout->
        itemAtPosition(i, j)->widget());
      if(tile->get_token() != m_board->get_piece(i, j)) {
        tile->set_token(m_board->get_piece(i, j));
      }
    }
  }
}

connection GameBoardPanel::connect_clicked_signal(
    const ClickedSignal::slot_type& slot) const {
  return m_clickedSignal.connect(slot);
}
