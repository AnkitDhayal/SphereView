#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QPushButton* uploadButton = new QPushButton("Upload STL File", this);
    connect(uploadButton, &QPushButton::clicked, this, &MainWindow::loadSTLFile);
    layout->addWidget(uploadButton);

    stlViewer = new STLViewer(this);
    layout->addWidget(stlViewer);

    setWindowTitle("STL File Viewer");
    resize(800, 600);
}

void MainWindow::loadSTLFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open STL File", "", "STL Files (*.stl)");
    if (!filePath.isEmpty()) {
        stlViewer->loadSTLFile(filePath);
    }
}

