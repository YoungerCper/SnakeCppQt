#ifndef WINDOW_H
#define WINDOW_H

#include "frame.h"
#include "mainmenu.h"
#include "gamefield.h"
#include "settingframe.h"
#include "gamestat.h"

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>



class Window : public QWidget
{
public:
    int timer;
    int nowFrame = MAINMENU;

    Frame* frame = new MainMenu(WINDOW_HEIGHT, WINDOW_WIDTH, this);

    enum FramKit{
        MAINMENU = -1,
        GAME,
        SETTING ,
        EXIT
    };

    //константы приложения
    //########################################################################
    const int DELAY = 50;
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDTH = 600;
    //########################################################################

    Window();
    ~Window();

    //начальные настройки, что-то вроде консруктора
    void SetUp();

protected:

    //обработчики прерываний
    //##########################################################################
    //обработчик таймера
    void timerEvent(QTimerEvent*) override;

    //обработчик нажатий клавиш
    void keyPressEvent(QKeyEvent*) override;

    //обработчик рисования
    void paintEvent(QPaintEvent*) override;

    //##########################################################################

};

#endif // WINDOW_H
