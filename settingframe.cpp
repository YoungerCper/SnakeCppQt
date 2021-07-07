#include "settingframe.h"
#include "window.h"
#include "gamestat.h"

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

SettingFrame::SettingFrame(int height, int width, QWidget* parent) : Frame(height, width, parent){}

int SettingFrame::GetKeyEvent(QKeyEvent* e)
{
    int key = e->key();

    int result = Window::SETTING;

    switch (key) {
    case Qt::Key_Up:
        cursor = (cursor + COUNT_DIFF - 1) % COUNT_DIFF;
        break;
    case Qt::Key_Down:
        cursor = (cursor +  1) % COUNT_DIFF;
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        GameStat::difficult = cursor;
        break;
    case Qt::Key_Escape:
        result = Window::MAINMENU;
        break;
    }

    return result;
}

void SettingFrame::Draw()
{
    QPainter painter(this->PARENT);
    QFont font = painter.font();

    font.setPointSize(40);
    font.setBold(true);
    painter.setFont(font);

    for(int i = 0; i < COUNT_DIFF; i++)
    {
            if(i == cursor)painter.setPen(Qt::red);
            else painter.setPen(Qt::black);
            painter.drawText(100, 150 + i * 50, nameDiff[i]);
    }
}

void SettingFrame::Update()
{

}
