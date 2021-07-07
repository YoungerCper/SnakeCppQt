#ifndef GAMESTAT_H
#define GAMESTAT_H


class GameStat
{
public:

    enum DifficultKit{
        EASY = 0,
        NORMAL,
        HARD,
        EXTREM
    };

    static int difficult;

    GameStat();
};

#endif // GAMESTAT_H
