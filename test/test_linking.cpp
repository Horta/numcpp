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

  A.fill(2.3);
  B.fill(-1.0);

  Matrix matrix({10, 5});

  double v = matrix;
  matrix.fill(2.1);
  v = matrix;

  slice s0 = {0, 3, 1};
  slice s1 = {0, 2, 1};

  cout << "ndim " << matrix.ndim() << endl;
  cout << "size " << matrix.size() << endl;
  cout << "shape " << matrix.shape() << endl;

  auto mat = matrix(s0, s1);

  cout << "ndim " << mat.ndim() << endl;
  cout << "size " << mat.size() << endl;
  cout << "shape " << mat.shape() << endl;

  return 0;
}
