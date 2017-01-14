#include "numcpp/numcpp.hpp"

#include <iostream>

using namespace numcpp;
using std::cout;
using std::endl;

int main()
{
  auto A = make_empty(4);
  auto B = make_empty(4);
  auto C = make_zeros(4);

  cout << A << endl;

  A.fill(2.3);
  B.fill(-1.0);

  cout << A << endl;
  cout << B << endl;
  cout << A+B << endl;
  cout << C << endl;

  Matrix matrix({10, 5});

  double v = matrix;
  cout << v << endl;
  matrix.fill(2.1);
  v = matrix;
  cout << v << endl;

  slice s0 = {0, 3, 1};
  slice s1 = {0, 2, 1};

  cout << "matrix ndim " << matrix.ndim() << endl;
  cout << "matrix size " << matrix.size() << endl;

  cout << "matrix ndim " << matrix(s0, s1).ndim() << endl;
  // cout << "matrix size " << mat.size() << endl;

  return 0;
}
