#include <cmath>
#include <iostream>
using namespace std;
double xi = 0.38;

double f(double x) {
  double ret = pow(x, 3) + 8 * pow(x, 2) - 3 * x + 3;
  return ret;
}

double gold_section_search(double a, double b, double E, double f(double x)) {
  double x1 = a + xi * (b - a);
  double x2 = a + (1 - xi) * (b - a);

  while (fabs(b - a) >= E) {
    if (f(x2) > f(x1)) {
      b = x2;
      x2 = x1;
      x1 = a + xi * (b - a);
    } else {
      a = x1;
      x1 = x2;
      x2 = a + (1 - xi) * (b - a);
    }
  }

  return (a + b) / 2;
}

int main() {
  double E = 0.001;
  double b = 5;
  double a = 0;

  double min_point = gold_section_search(b, a, E, f);

  cout << "min_point- " << min_point << endl;
  cout << "f_min- " << f(min_point) << endl;

  return 0;
}
