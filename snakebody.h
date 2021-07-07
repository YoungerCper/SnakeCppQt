#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <vector>
#include <QPoint>


class SnakeBody
{
public:

    enum Arrow{
        UP = 1,
        RIGHT,
        DOWN,
        LEFT
    };

    bool isLive = true;

    int direction = DOWN;

    std::vector<QPoint> titleBody;
    int leight = 3;

    int COUNT_DOT_W;
    int COUNT_DOT_H;

    SnakeBody(int dot_count_w, int dot_count_h);

    void Move();

    void Up();

    bool Check();

    QPoint& operator[](const int index);
};

#endif // SNAKEBODY_H
