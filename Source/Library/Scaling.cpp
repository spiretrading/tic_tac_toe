#include "TicTacToe/Library/Scaling.hpp"
#include <QApplication>
#include <QDesktopWidget>

using namespace TicTacToe;

int TicTacToe::scale_width(int width) noexcept {
  auto dpiX = QApplication::desktop()->logicalDpiX();
  return (width * dpiX) / DPI;
}

int TicTacToe::scale_height(int height) noexcept {
  auto dpiY = QApplication::desktop()->logicalDpiY();
  return (height * dpiY) / DPI;
}

double TicTacToe::scale_width(double width) noexcept {
  auto dpiX = QApplication::desktop()->logicalDpiX();
  return (width * dpiX) / DPI;
}

double TicTacToe::scale_height(double height) noexcept {
  auto dpiY = QApplication::desktop()->logicalDpiY();
  return (height * dpiY) / DPI;
}

QSize TicTacToe::scale(int width, int height) noexcept {
  return QSize(scale_width(width), scale_height(height));
}

QSize TicTacToe::scale(const QSize& size) noexcept {
  return scale(size.width(), size.height());
}

QPoint TicTacToe::translate(int x, int y) noexcept {
  return QPoint(scale_width(x), scale_height(y));
}

QPoint TicTacToe::translate(const QPoint& p) noexcept {
  return translate(p.x(), p.y());
}
