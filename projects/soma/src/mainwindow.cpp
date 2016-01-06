#include <QVTKWidget.h>
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Sphere
    auto sphereSource(vtkSmartPointer<vtkSphereSource>::New());
    sphereSource->Update();
    auto sphereMapper(vtkSmartPointer<vtkPolyDataMapper>::New());
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    auto sphereActor(vtkSmartPointer<vtkActor>::New());
    sphereActor->SetMapper(sphereMapper);

    // Cube
    auto cubeSource(vtkSmartPointer<vtkCubeSource>::New());
    cubeSource->Update();
    auto cubeMapper(vtkSmartPointer<vtkPolyDataMapper>::New());
    cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
    auto cubeActor(vtkSmartPointer<vtkActor>::New());
    cubeActor->SetMapper(cubeMapper);

    // VTK Renderer
    auto leftRenderer(vtkSmartPointer<vtkRenderer>::New());
    leftRenderer->AddActor(sphereActor);

    auto rightRenderer(vtkSmartPointer<vtkRenderer>::New());

    // Add Actor to renderer
    rightRenderer->AddActor(cubeActor);

    QVTKWidget* widget(new QVTKWidget);
    this->setCentralWidget(widget);
    widget->GetRenderWindow()->AddRenderer(leftRenderer);

    // Set up action signals and slots
    // connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

MainWindow::~MainWindow() {
    delete ui;
}
