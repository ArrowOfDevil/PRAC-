#include <locale.h>
#include <math.h>

#include <iostream>
using namespace std;
// Функция, определяющая левую часть уравнения f (x) = 0.
double f(double x) { return (x * x - cos(5 * x)); }
// Функция, реализующая метод касательных.
double f1(double x)  // Первая производная функции f (x).
{
  return (2 * x + 5 * sin(5 * x));
}
double f2(double x)  // Вторая производная функции f (x).
{
  return (2 + 25 * cos(5 * x));
}

int Tangent(double a, double b, double *c, double eps) {
  int k = 0;
  if (f(a) * f2(a) > 0)
    *c = a;
  else
    *c = b;
  do {
    *c = *c - f(*c) / f1(*c);
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
  cout << "Метод касательных:" << endl;
  K = Tangent(A, B, &X, ep);
  cout << " Найденное решение x=" << X;
  cout << ", количество итераций k=" << K << endl;
  return 0;
}
