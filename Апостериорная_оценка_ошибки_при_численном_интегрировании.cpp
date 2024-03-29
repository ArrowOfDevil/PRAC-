#include <iostream>
#include <vector>
using namespace std;

int b = 1;
int a = -1;
int r = 2;
int p = 2;
int q = 2;
int S = 3;
int N = 1;

double f(double x) { return 1 / (1 + pow(x, 2)); }
// Trapezoid method
double Integration(double y(double x), double b, double a, int N) {
  double h = (b - a) / N;
  double I = 0;
  for (int n = 1; n <= N + 1; n++) {
    I = I + (f(a + h * n) + f(a + h * (n - 1))) / 2 * h;
  }
  return I;
}
void mistakes(double f(double x), double r, double p, double q, double S) {
  vector<vector<double>> U(S, vector<double>(S));
  vector<vector<double>> R(S, vector<double>(S));
  for (int s = 0; s < S; s++) {
    U[s][0] = Integration(f, b, a, pow(r, s) * N);
  }
  for (int s = 1; s < S; s++) {
    for (int l = 0; l < s; l++) {
      R[s][l] = (U[s][l] - U[s - 1][l]) / (pow(r, p + l * q) - 1);
      U[s][l + 1] = U[s][l] + R[s][l];
    }
  }
  cout << "Tabular with numerical values of integration";
  cout << endl;
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < S; j++) {
      cout << U[i][j] << " ";
    }
    cout << endl;
  }
  cout << "\nTabular with mistakes";
  cout << endl;
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < S; j++) {
      cout << R[i][j] << " ";
    }
    cout << endl;
  }
}
int main() { 
  mistakes(f, r, p, q, S); 
  return 0;
}
