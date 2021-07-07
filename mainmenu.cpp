#include "mainmenu.h"
#include "frame.h"
#include "window.h"

#include <QPainter>
#include <QWidget>
#include <QFont>
#include <QKeyEvent>


MainMenu::MainMenu(int height, int width, QWidget* parent) : Frame(height, width, parent){}


int MainMenu::GetKeyEvent(QKeyEvent *key)
{
   int e = key->key();
   int result = Window::MAINMENU;
   switch(e){
   case Qt::Key_Down:
       cursor++;
       cursor%= COUNT_POINT;
       break;
   case Qt::Key_Up:
       cursor+=COUNT_POINT - 1;
       cursor%= COUNT_POINT;
       break;
   case Qt::Key_Enter:
   case Qt::Key_Return:
        result = cursor;
       break;
   }
   qDebug()<<cursor;
    return result;
}

void MainMenu::Draw()
{
    QPainter painter(this->PARENT);
    QFont font = painter.font();

    font.setPointSize(40);
    font.setBold(true);
    painter.setFont(font);

    for(int i = 0; i < COUNT_POINT; i++)
    {
            if(i == cursor)painter.setPen(Qt::red);
            else painter.setPen(Qt::black);
            painter.drawText(100, 150 + i * 50, namePoint[i]);
    }
}
