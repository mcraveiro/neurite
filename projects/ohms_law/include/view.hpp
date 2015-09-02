#include <Wt/WText>
#include <Wt/WLineEdit>
#include <Wt/WApplication>

class view : public Wt::WApplication {
public:
  view(const Wt::WEnvironment& env);

private:
  Wt::WLineEdit* current_;
  Wt::WLineEdit* resistance_;
  Wt::WText* result_;
};

Wt::WApplication* create_application(const Wt::WEnvironment& env);
