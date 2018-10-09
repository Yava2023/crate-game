#include "game.h"

Game::Game(QWidget* parent) : QWidget(parent) {
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);

  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(loop_slot()));
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000.0f / 60.0f);
}

void Game::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Escape) {
    QApplication::quit();
  } else if (event->key() == Qt::Key_Right) {
    key_right = true;
  } else if (event->key() == Qt::Key_Left) {
    key_left = true;
  } else if (event->key() == Qt::Key_Down) {
    key_down = true;
  } else if (event->key() == Qt::Key_Up) {
    key_up = true;
  }
}

void Game::keyReleaseEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Right) {
    key_right = false;
  } else if (event->key() == Qt::Key_Left) {
    key_left = false;
  } else if (event->key() == Qt::Key_Down) {
    key_down = false;
  } else if (event->key() == Qt::Key_Up) {
    key_up = false;
  }
}

void Game::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setPen(pen);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(Qt::SolidPattern);
  painter.drawRect(QRect(0, 0, width(), height()));

  QPen pen2(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setBrush(Qt::red);
  painter.setPen(pen2);
  QRect crate = {x, height() - 10, 40, 20};
  painter.drawRect(crate);

  Falling_box box1{1.0f * width() / 2, 10};
  Game::showbox(box1, painter);
}

void Game::showbox(Falling_box box, QPainter& painter) {
  QPen pen2(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setBrush(Qt::red);
  painter.setPen(pen2);

  QRect rect = {static_cast<int>(box.posx()), static_cast<int>(box.posy()), 20,
                20};
  painter.drawRect(rect);
}
void Game::loop_slot() {
  if (key_up) y -= speed;
  if (key_down) y += speed;
  if (key_left) x -= speed;
  if (key_right) x += speed;
}
