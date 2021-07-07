#include "snakebody.h"

SnakeBody::SnakeBody(int dot_count_w, int dot_count_h)
{
        for(int i =0; i < leight; i++)
        {
            QPoint p(0, 7 - i);
            titleBody.push_back(p);
        }

        COUNT_DOT_H = dot_count_h;
        COUNT_DOT_W = dot_count_w;
}

void SnakeBody::Move()
{
    if(isLive){
            QPoint p(titleBody[0].x(), titleBody[0].y());
            switch(direction){
            case UP:
                p.setY((p.y()-1 + COUNT_DOT_H) % COUNT_DOT_H );
                break;
            case RIGHT:
                p.setX((p.x() + 1)% COUNT_DOT_W);
                break;
            case DOWN:
                p.setY((p.y() + 1)% COUNT_DOT_H);
                break;
            case LEFT:
                p.setX((p.x() -1 + COUNT_DOT_W) % COUNT_DOT_W);
                break;
            }

            QPoint z = titleBody[0];
            for(int i = 1; i < leight; i++)    {
                QPoint t =  titleBody[i] ;
                titleBody[i] = z;
                z = t;
            }

            titleBody[0] = p;

            isLive = Check();
    }
}

void SnakeBody::Up()
{
    titleBody.push_back(titleBody[leight - 1]);
    leight++;
}

bool SnakeBody::Check()
{
        for(int i = 1; i < leight; i++) {  if(titleBody[0].x() == titleBody[i].x() && titleBody[0].y() == titleBody[i].y()) return false;  }

        return true;
}

QPoint& SnakeBody::operator[](const int index)
{
    return titleBody[index];
}
