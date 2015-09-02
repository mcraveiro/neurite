#include <iostream>
#include <boost/units/systems/si/electric_potential.hpp>
#include <boost/units/systems/si/current.hpp>
#include <boost/units/systems/si/resistance.hpp>
#include <boost/units/systems/si/io.hpp>
#include "calculator.hpp"


double calculator::
voltage(const double resistance, const double current) const {
  boost::units::quantity<boost::units::si::resistance>
    R(resistance * boost::units::si::ohms);
  boost::units::quantity<boost::units::si::current>
    I(current * boost::units::si::amperes);
  auto V(R * I);
  return V.value();
}
