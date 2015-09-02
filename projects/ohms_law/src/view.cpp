#include <functional>
#include <boost/lexical_cast.hpp>
#include <Wt/WBreak>
#include <Wt/WPushButton>
#include <Wt/WContainerWidget>
#include <Wt/WDoubleValidator>
#include "calculator.hpp"
#include "view.hpp"

view::view(const Wt::WEnvironment& env) : Wt::WApplication(env) {
  setTitle("Ohm's Law Calculator");

  root()->addWidget(new Wt::WText("Current: "));
  current_ = new Wt::WLineEdit(root());
  current_->setValidator(new Wt::WDoubleValidator());
  current_->setFocus();

  root()->addWidget(new Wt::WText("Resistance: "));
  resistance_ = new Wt::WLineEdit(root());
  resistance_->setValidator(new Wt::WDoubleValidator());

  Wt::WPushButton* button = new Wt::WPushButton("Calculate!", root());
  button->setMargin(5, Wt::Left);
  root()->addWidget(new Wt::WBreak());
  result_ = new Wt::WText(root());

  button->clicked().connect([&](Wt::WMouseEvent&) {
      const auto current(boost::lexical_cast<double>(current_->text()));
      const auto resistance(boost::lexical_cast<double>(resistance_->text()));

      calculator c;
      const auto voltage(c.voltage(resistance, current));
      const auto s(boost::lexical_cast<std::string>(voltage));
      result_->setText("Voltage: " + s);
    });
}

Wt::WApplication* create_application(const Wt::WEnvironment& env) {
  return new view(env);
}
