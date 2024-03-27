#include <locale.h>
#include <math.h>
#include <cmath>
#include <iostream>
using namespace std;

typedef double (*pointFunc)(double);

double f(double x) { return (10 - x); }

double rectangle_integral(pointFunc f, double a, double b, int n) {
  double x, h;
  double sum = 0.0;
  double fx;
  h = (b - a) / n;  // шаг

  for (int i = 0; i < n; i++) {
    x = a + i * h;
    fx = f(x);
    sum += fx;
  }
  return (sum * h);  // приближенное значение интеграла равно
  // сумме площадей прямоугольников
}

int main() {
  setlocale(LC_ALL, "Russian");
  double a, b, eps;
  double s1, s;
  int n = 1;  // начальное число шагов

  cout << "Введите левую границу интегрирования a = ";
  cin >> a;
  cout << "\nВведите правую границу интегрирования b = ";
  cin >> b;
  cout << "\nВведите требуемую точность eps = ";
  cin >> eps;
  s1 = rectangle_integral(f, a, b, n);  // первое приближение для интеграла
  do {
    s = s1;     // второе приближение
    n = 2 * n;  // увеличение числа шагов в два раза,
                // т.е. уменьшение значения шага в два раза
    s1 = rectangle_integral(f, a, b, n);
  } while (fabs(s1 - s) > eps);  // сравнение приближений с заданной точностью
  cout << "\nИнтеграл = " << s1 << endl;
}
