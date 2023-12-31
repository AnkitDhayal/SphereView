#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizerr.h"
#include "Point3D.h"
#include <vector>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include "Triangle.h"


class OpenGLWindow;

class Visualizer : public QMainWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();
private slots:
    void addPoints();
    void addRegion();
    void addLine();
    void addHermite();
    //void addBezier();
    void addPolygon();
    //void clipPolygon();
    //void clipLine();
    void reader();
    void writer();

private:
    QWidget* mCentralWidget;
    QWidget* mGridLayoutWidget;
    QGridLayout* mGridLayout;
    QHBoxLayout* mHorizontalLayout7;
    QHBoxLayout* mHorizontalLayout8;
    QHBoxLayout* mHorizontalLayout9;
    QHBoxLayout* mHorizontalLayout11;
   /* QPushButton* mPushButton4;
    QPushButton* mPushButton3;
    QPushButton* mPushButton5;
    QPushButton* mPushButton6;
    QPushButton* mPushButton7;*/
    QPushButton* mPushButton8;
    QPushButton* mPushButton9;
    QPushButton* mPushButton10;
    QPushButton* mPushButton11;
    QHBoxLayout* mHorizontalLayout10;
    QVBoxLayout* mVerticalLayout3;
    QVBoxLayout* mVerticalLayout5;
    QHBoxLayout* mHorizontalLayout5;
    QDoubleSpinBox* mDoubleSpinBox5;
    QDoubleSpinBox* mDoubleSpinBox6;
    QPushButton* mPushButton2;
    QListWidget* mListWidget3;
    OpenGLWindow* mOpenGLWidget;

    std::vector<Point3D> mPoints;

    QVector <Triangle> triangles;
    QVector <GLfloat> myColorVector;
    QVector <GLfloat> inputPoints;
};
