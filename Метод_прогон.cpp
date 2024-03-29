#include <iostream>
#include <vector>
using namespace std;
// В этом способе другое задание матрицы по сравнению с 1 способом. т.е. в этом способе матрица :
    // b1 c1 0
    // a2 b2 c2
    // 0 a3 b3
    // т.е. a1 и c3 равны нулю. Также тут можно собственноручно задать любую трехдиагональную матрицу.Случай 3x3 рассмотрен для простоты 
vector<double>solveTridiagonalMatrix(vector<double> a, vector<double> b, vector<double> c, vector<double> d) {
  int N = a.size();
  vector<double> eps(N + 1);
  vector<double> et(N + 1);
  vector<double> x(N + 1);
  eps[0] = 0;
  et[0] = 0;
  for (int i = 0; i < N; i++) {
    double temp = b[i] + a[i] * eps[i];
    eps[i + 1] = -c[i] / temp;
    et[i + 1] = (d[i] - a[i] * et[i]) / temp;
  }
  x[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    x[i] = eps[i + 1] * x[i + 1] + et[i + 1];
  }
  return x;
}
int main() {
  vector<double> a = {0, 1, 4};
  vector<double> b = {-1, 3, 5};
  vector<double> c = {2, 6, 0};
  vector<double> d = {12, 15, 0};
  vector<double> x = solveTridiagonalMatrix(a, b, c, d);
  for (int i = 0; i < a.size(); i++) {
    cout << "x" << i+1 << " = " << x[i] << "\n";
  }
  return 0;
}
