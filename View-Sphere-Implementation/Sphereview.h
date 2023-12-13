#pragma once

#include <QtWidgets/QMainWindow>


class OpenGLWindow;

class Sphereview : public QMainWindow
{
    Q_OBJECT

public:
    Sphereview(QWindow* parent = nullptr);
    ~Sphereview();

private:
    void setupUi();

private:
    QMenuBar* mMenuBar;
    QToolBar* mMainToolBar;
    QWidget* mCentralWidget;
    QStatusBar* mStatusBar;
    OpenGLWindow* mRenderer;

};