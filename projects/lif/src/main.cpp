#include <iomanip>
#include <iostream>

const double e_rest = -60e-3;
const double t_bg_cur = 0.02; // current into resistance

const double membrane_resistance = 1e8; // 100 megohms
// The commonly used standard cell has a width of 1 cm, and thus for
// very pure water in equilibrium with air would have a resistance of
// about 106 ohm, known as a megohm.

const double membrane_capacitance = 200e-12; // 200
                                             // pico-farads. farad =
                                             // amperes per second
                                             // over voltage.
const double tau_m = membrane_resistance * membrane_capacitance; // tau is the membrane time constant

double test(double t, double v, double dt) {
  const auto scale_mem  = dt / tau_m;
  return (e_rest - v + t_bg_cur) * scale_mem;
}

template<typename F>
void euler(F f, double y0, double start, double end, double dt) {
  double y = y0;
  std::cout << "# y " << "x" << std::endl;
  for (double t = start; t < end; t += dt) {
      std::cout << std::fixed << std::setprecision(3)
                << t << " " << y
                << std::endl;
      y += /*dt **/ f(t, y, dt);
    }
}

/*
double newtonCoolingLaw(double, double t) {
  return -0.07 * (t - 20);
}
*/

int main() {
  // euler(newtonCoolingLaw, 100, 20, 100,  2);
  euler(test, e_rest, 0, 2, 1e-4);
}
