#include "gamefield.h"
#include "snakebody.h"
#include "window.h"

#include <QPainter>
#include <QKeyEvent>
#include <cstdlib>

GameField::GameField(int height, int width, QWidget* parent) : Frame(height, width, parent){
    snake = new SnakeBody(DOT_COUNT_HEIGHT, DOT_COUNT_WIDTH);

    SetTarget();
}

GameField::~GameField()
{
    delete snake;
}

void GameField::Draw()
{
    QPainter p(PARENT);
    p.setBrush(QBrush(Qt::red));
    p.setPen(Qt::red);

    for(int i = 1; i < (*this->snake).leight; i++)
    {
        p.drawRect((*this->snake)[i].x() * DOT_WIDTH, (*this->snake)[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
    }

    p.setBrush(QBrush(Qt::darkRed));
    p.setPen(Qt::darkRed);
    p.drawRect((*this->snake)[0].x() * DOT_WIDTH, (*this->snake)[0].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);

    p.setBrush(QBrush(Qt::darkBlue));
    p.setPen(Qt::darkBlue);
    p.drawRect(target.x() * DOT_WIDTH, target.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);

    p.setPen(Qt::black);

    QString str("Счёт: ");
    QString digit = QString::number(score);

    p.drawText(0, FRAME_HEIGHT, str + digit);
}

 int GameField::GetKeyEvent(QKeyEvent* e)
 {
        int key = e->key();
        int result = Window::GAME;

        switch(key){
        case Qt::Key_Down:
            this->snake->direction = SnakeBody::DOWN;
            break;
        case Qt::Key_Right:
            this->snake->direction = SnakeBody::RIGHT;
            break;
        case Qt::Key_Up:
            this->snake->direction = SnakeBody::UP;
            break;
        case Qt::Key_Left:
            this->snake->direction = SnakeBody::LEFT;
            break;
        case Qt::Key_Escape:
            result = Window::MAINMENU;
            break;
        case Qt::Key_Space:
            lastTime = 1000;
            break;
        }

        return result;
 }

 void GameField::Update()
 {
        lastTime++;
        if(lastTime >= (4 - GameStat::difficult)){
            snake->Move();
            lastTime -= lastTime;
        }


        if(target.x() == (*snake)[0].x() && target.y() == (*snake)[0].y()){
            SetTarget();

            snake->Up();

            score += (GameStat::difficult + 1) * DEFAULT_SCORE;
        }
 }

 void GameField::SetTarget()
 {
       int x = rand() % DOT_COUNT_WIDTH;
       int y = rand() % DOT_COUNT_HEIGHT;

       target.setX(x);
       target.setY(y);
 }

