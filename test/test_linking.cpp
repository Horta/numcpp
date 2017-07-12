#include "numcpp/numcpp.hpp"

using namespace numcpp;
using std::cout;
using std::endl;

int main()
{
  auto a = make_empty(shape_t{2, 2});
  auto b = make_empty(shape_t{2, 2});
  auto c = make_zeros(shape_t{2, 2});

  a.fill(2.3);
  b.fill(-1.0);

  auto sl = slice{0, 1, 1};

  // auto d = a(slice_t{0, 1, 1}, slice_t{0, 1, 1});
  //
  // Matrix matrix({10, 5});
  //
  // double v = matrix;
  // matrix.fill(2.1);
  // v = matrix;
  //
  // slice_t s0 = {0, 3, 1};
  // slice_t s1 = {0, 2, 1};
  //
  // cout << "ndim " << matrix.ndim() << endl;
  // cout << "size " << matrix.size() << endl;
  // cout << "shape " << matrix.shape() << endl;
  //
  // auto mat = matrix(s0, s1);
  //
  // // cout << "ndim " << mat.ndim() << endl;
  // // cout << "size " << mat.size() << endl;
  // // cout << "shape " << mat.shape() << endl;
  // //
  // // cout << mat+mat << endl;

  return 0;
}
