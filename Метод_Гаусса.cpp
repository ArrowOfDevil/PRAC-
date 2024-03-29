#include <iostream>
using namespace std;
#include <vector>

vector<double> Gauss(vector<vector<double>> A, vector<double> b) {
  int n = b.size();

  vector<double> x(n);

  int u = 0;

  // straight approach
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double ratio = A[j][i] / A[i][i];
      for (int k = i; k < n; k++) {
        A[j][k] -= ratio * A[i][k];
      }
      b[j] -= ratio * b[i];
      u++;
    }
  }

  // backward approach
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      double ratio = A[j][i] / A[i][i];
      for (int k = n - 1; k >= 0; k--) {
        A[j][k] -= ratio * A[i][k];
      }
      b[j] -= ratio * b[i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
    cout << endl;
  }

  // to look for solving of system
  for (int i = 0; i < n; i++) {
    x[i] = b[i] / A[i][i];
  }

  return x;
}

int main() {
  // Example system of linear equations:
  // 2x + y - z = 8
  // -3x - y + 2z = -11
  // -2x + y + 2z = -3

  vector<vector<double>> A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
  vector<double> b = {8, -11, -3};

  vector<double> solution;

  // Solve the system using Gauss
  solution = Gauss(A, b);

  cout << "Solution:" << endl;
  for (int i = 0; i < solution.size(); i++) {
    cout << "x" << i + 1 << " = " << solution[i] << endl;
  }
}
