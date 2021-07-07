#include "frame.h"

#include <QKeyEvent>

Frame::Frame(int height, int width, QWidget* parent)
{
    FRAME_HEIGHT = height;
    FRAME_WIDTH = width;
    PARENT = parent;
}

Frame::~Frame(){}

int Frame::GetKeyEvent(QKeyEvent* key)
{

}

void Frame::Draw()
{

}

void Frame::Update()
{

}
