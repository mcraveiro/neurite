#include "view.hpp"

int main(int argc, char* argv[]) {
  return Wt::WRun(argc, argv, &create_application);
}
