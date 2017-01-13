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

  return 0;
}
