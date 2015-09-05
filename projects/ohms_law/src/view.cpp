/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
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
