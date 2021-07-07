#include "window.h"
#include "gamestat.h"




Window::Window()
{
    SetUp();
}

Window::~Window()
{
    delete frame;
}

void Window::SetUp()
{
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    timer = startTimer(DELAY);
}

void Window::timerEvent(QTimerEvent *e)
{
    this->frame->Update();
    this->repaint();
}

void Window::keyPressEvent(QKeyEvent *e)
{
    int newFrame = this->frame->GetKeyEvent(e);
    if(newFrame != nowFrame){
        switch(newFrame){
        case MAINMENU:
            delete frame;
            frame = new MainMenu(WINDOW_HEIGHT, WINDOW_WIDTH, this);
            break;
        case GAME:
            delete frame;
            frame = new GameField(WINDOW_HEIGHT, WINDOW_WIDTH, this);
            break;
        case SETTING:
            delete frame;
            frame = new SettingFrame(WINDOW_HEIGHT, WINDOW_WIDTH, this);
            break;
        case EXIT:
            this->close();
            break;
        }
        qDebug()<<newFrame<<nowFrame;

        nowFrame = newFrame;
    }

}

void Window::paintEvent(QPaintEvent *e)
{
    this->frame->Draw();
}


