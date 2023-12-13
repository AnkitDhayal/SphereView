#include "stdafx.h"
#include "Sphereview.h"
#include "OpenGLWindow.h"

Sphereview::Sphereview(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
}

Sphereview::~Sphereview()
{}

void Sphereview::setupUi() {
    resize(600, 400);
    mMenuBar = new QMenuBar(this);
    mMenuBar->setObjectName("menuBar");
    setMenuBar(mMenuBar);
    mMainToolBar = new QToolBar(this);
    mMainToolBar->setObjectName("mainToolBar");
    addToolBar(mMainToolBar);
    mStatusBar = new QStatusBar(this);
    mStatusBar->setObjectName("statusBar");
    setStatusBar(mStatusBar);
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    setCentralWidget(mRenderer);



    setWindowTitle(QCoreApplication::translate("SimpleDDA_BresenhamClass", "SimpleDDA", nullptr));
}