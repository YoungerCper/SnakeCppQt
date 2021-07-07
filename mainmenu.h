#ifndef MAINMENU_H
#define MAINMENU_H

#include "frame.h"

class MainMenu : public Frame
{
public:

    enum pointMenu{
        START = 0,
        SEETING,
        EXIT
    };

    const int COUNT_POINT = 3;

    const QString namePoint[3] = {"Начать игру" , "Настройки"  , "Выход"};

    int cursor = 0;

    MainMenu(int height, int width, QWidget* parent);

    int GetKeyEvent(QKeyEvent*) override;

    void Draw() override;
};

#endif // MAINMENU_H
