#ifndef FRAME_H
#define FRAME_H

#include <QWidget>


class Frame
{
public:
    int FRAME_HEIGHT;
    int FRAME_WIDTH;

    QWidget* PARENT;

    Frame(int height, int width, QWidget* parent);
    ~Frame();

    virtual int GetKeyEvent(QKeyEvent*);

    virtual void Draw();

    virtual void Update();
};

#endif // FRAME_H
