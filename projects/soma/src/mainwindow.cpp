#include <QVTKWidget.h>
#include <vtkCylinderSource.h>
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

    auto cylinderSource(vtkSmartPointer<vtkCylinderSource>::New());
    cylinderSource->SetCenter(0.0, 0.0, 0.0);
    cylinderSource->SetRadius(5.0);
    cylinderSource->SetHeight(7.0);
    cylinderSource->SetResolution(100);

    auto mapper(vtkSmartPointer<vtkPolyDataMapper>::New());
    mapper->SetInputConnection(cylinderSource->GetOutputPort());
    auto cylinderActor(vtkSmartPointer<vtkActor>::New());
    cylinderActor->SetMapper(mapper);

    // //Create a renderer, render window, and interactor
    // vtkSmartPointer<vtkRenderer> renderer =
    //   vtkSmartPointer<vtkRenderer>::New();
    // vtkSmartPointer<vtkRenderWindow> renderWindow =
    //   vtkSmartPointer<vtkRenderWindow>::New();
    // renderWindow->AddRenderer(renderer);
    // vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    //   vtkSmartPointer<vtkRenderWindowInteractor>::New();
    // renderWindowInteractor->SetRenderWindow(renderWindow);

    // // Add the actor to the scene
    // renderer->AddActor(actor);
    // renderer->SetBackground(.1, .3,.2); // Background color dark green

    // // Render and interact
    // renderWindow->SetWindowName(argv[0]);
    // renderWindow->Render();
    // renderWindowInteractor->Start();

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
    // leftRenderer->AddActor(sphereActor);
    leftRenderer->AddActor(cylinderActor);

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
