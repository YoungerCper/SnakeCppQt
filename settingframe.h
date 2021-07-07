#ifndef SETTINGFRAME_H
#define SETTINGFRAME_H

#include "frame.h"
#include "gamestat.h"


class SettingFrame : public Frame
{
public:

    enum DifficulteKit{
       EASY = 0,
       NORMAL,
       HARD,
       EXTREM
    };

    const QString nameDiff[4] = {"Легко" , "Нормально" , "Сложно" , "Очень сложно"};
    const int COUNT_DIFF = 4;

    int cursor = EASY;

    int GetKeyEvent(QKeyEvent*) override;

    void Draw() override;

    void Update() override;

    SettingFrame(int height, int width, QWidget* parent);
};

#endif // SETTINGFRAME_H
