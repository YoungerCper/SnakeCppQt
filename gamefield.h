#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "frame.h"
#include "snakebody.h"

#include <QKeyEvent>

class GameField : public Frame
{
public:

    const int DOT_HEIGHT = 10;
    const int DOT_WIDTH = 10;

    const int DOT_COUNT_HEIGHT = 60;
    const int DOT_COUNT_WIDTH = 60;

    const int DEFAULT_SCORE = 2;

    int lastTime = 0;

    SnakeBody* snake;

    QPoint target;

    int score = 0;

    GameField(int height, int width, QWidget* parent);
    ~GameField();

    int GetKeyEvent(QKeyEvent*) override;

    void Draw() override;

    void Update() override;

    void SetTarget();
};

#endif // GAMEFIELD_H
