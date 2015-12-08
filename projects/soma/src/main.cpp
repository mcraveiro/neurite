#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QPushButton>

int main(int argc, char **argv) {
  QApplication app (argc, argv);
  QPushButton button ("Hello world !");
  button.show();
  return app.exec();
}
