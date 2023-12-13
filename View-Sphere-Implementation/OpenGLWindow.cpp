#include "stdafx.h"
#include "OpenGLWindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include "Reader.h"
#include "MainWidget.h"
#include "QMouseEvent"

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(300, 250);
}
OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    // We are done with the current QOpenGLContext, forget it. If there is a
    // subsequent initialize(), that will then connect to the new context.
    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.perspective(100.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);



    mProgram->setUniformValue(m_matrixUniform, matrix);

    static const GLfloat vertices[] = {
         0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.5f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f,
        1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,

        1.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,

        0.5f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,

        0.5f, 0.5f, 0.5f,
        1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        0.8f, 0.2f, 0.5f,
        0.3f, 0.7f, 0.1f,
        0.2f, 0.9f, 0.5f,

        0.6f, 0.4f, 0.2f,
        0.8f, 0.2f, 0.4f,
        0.5f, 0.5f, 0.8f,

        0.9f, 0.3f, 0.2f,
        0.1f, 0.8f, 0.5f,
        0.4f, 0.6f, 0.9f,

        0.7f, 0.1f, 0.9f,
        0.4f, 0.6f, 0.2f,
        0.8f, 0.7f, 0.3f,

        0.2f, 0.5f, 0.8f,
        0.9f, 0.1f, 0.3f,
        0.6f, 0.4f, 0.7f,

        0.5f, 0.7f, 0.4f,
        0.2f, 0.9f, 0.8f,
        0.1f, 0.6f, 0.3f
    };
    SphereView::Reader reader;
    reader.reader(pointVector , colorVector);

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, pointVector.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorVector.data());

   
    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_POLYGON, 0, pointVector.size()/3);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::initializeGL()
{
    static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);

}

void OpenGLWindow::createGeometry()
{
    mVertices.clear();
    mNormals.clear();

    mVertices << QVector3D(0.0f, 0.707f, -0.05f);
    mVertices << QVector3D(-0.5f, -0.5f, -0.05f);
    mVertices << QVector3D(0.5f, -0.5f, -0.05f);

}





