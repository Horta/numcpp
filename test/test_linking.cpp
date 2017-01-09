#include "numcpp/numcpp.hpp"

#include <iostream>

using namespace numcpp;
using std::cout;
using std::endl;

int main()
{
  auto A = make_empty(4);
  auto B = make_empty(4);

  cout << A << endl;

  A.fill(2.3);

  cout << A << endl;

  return 0;
}
