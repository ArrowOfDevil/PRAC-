#include <locale.h>
#include <math.h>
#include <iostream>
using namespace std;
// Функция, определяющая левую часть уравнения f (x) = 0.
double f(double x) { return (x * x - cos(5 * x)); }

// Функция, реализующая метод хорд.
int Chord(double a, double b, double *c, double eps) {
  int k = 0;
  do {
    *c = a - f(a) / (f(b) - f(a)) * (b - a);
    if (f(*c) * f(a) > 0)
      a = *c;
    else
      b = *c;
    k++;
  } while (fabs(f(*c)) >= eps);
  return k;
}

int main() {
  setlocale(LC_ALL, "Russian");
  double A, B, X, P;
  double ep = 0.001;  // Точность вычислений.
  int K;
  cout << "a=";
  cin >> A;  // Интервал изоляции корня.
  cout << "b=";
  cin >> B;
  cout << "Решение уравнения x^2 - cos (5* x) =0. " << endl;
  cout << "Метод хорд:" << endl;
  K = Chord(A, B, &X, ep);
  cout << " Найденное решение x=" << X;
  cout << ", количество итераций k=" << K << endl;
  return 0;
}
