#include <math.h>
#include <locale.h>
#include <iostream>
using namespace std;
// Функция, определяющая левую часть уравнения f (x) = 0.
double f(double x) { return (x * x - cos(7 * x)); }
// Функция, заданная выражением 4.4 .
double fi(double x, double L) { return (x + L * f(x)); }

// Функция, реализующая метод простой итерации.
int Iteration(double *x, double L, double eps);
int main() {
  setlocale(LC_ALL, "Russian");
  double A, B, X, L;
  double ep = 0.0001;  // Точность вычислений.
  int K;

  cout << "a=";
  cin >> A;  

  cout << "Метод простой итерации:" << endl;
  X = A;
  cout << "L=";
  cin >> L;
  K = Iteration(&X, L, ep);
  cout << " Найденное решение x=" << X;
  cout << ", количество итераций k=" << K << endl;
  return 0;
}
int Iteration(double *x, double L, double eps) {
  int k = 0;
  double x0;
  do {
    x0 = *x;
    *x = fi(x0, L);
    k++;
  } while (fabs(x0 - *x) >= eps);
  return k;
}
