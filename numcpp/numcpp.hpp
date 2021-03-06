#ifndef NUMCPP_HPP
#define NUMCPP_HPP

#include "array.hpp"
#include "shape.hpp"
#include "slice.hpp"
#include "io.hpp"

namespace numcpp {

inline decltype(auto) make_empty(const shape_t &shape) { return Array{shape}; }
inline decltype(auto) make_zeros(const shape_t &shape)
{
  auto arr = Array{shape};
  arr.fill(0);
  return arr;
}

// class Matrix;
//
// template <class T>
// std::valarray<T> push_front(const T &v, const std::valarray<T> &arr) {
//   std::valarray<T> narr(arr.size() + 1);
//   narr[0] = v;
//   narr[std::slice(1, arr.size(), 1)] = arr;
//   return narr;
// }

// Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
//   Matrix m(lhs.shape());
//   *m.data = *lhs.data + *rhs.data;
//   return m;
// }

// Array operator+(const Array &lhs, const Array &rhs) {
//   return Array{lhs.data + rhs.data};
// }
//
// Array operator-(const Array &lhs, const Array &rhs) {
//   return Array{lhs.data - rhs.data};
// }
//
// Array operator*(const Array &lhs, const Array &rhs) {
//   return Array{lhs.data * rhs.data};
// }
//
// Array operator/(const Array &lhs, const Array &rhs) {
//   return Array{lhs.data / rhs.data};
// }
//
// inline std::ostream &operator<<(std::ostream &o, const Array &arr) {
//   o << '[';
//   for (const auto &v : arr.data) {
//     o << v << " ";
//   }
//   o << '\b' << "]";
//   return o;
// }
//
// # Array attributes
// ndarray.flags	Information about the memory layout of the array.
// ndarray.shape	Tuple of array dimensions.
// ndarray.strides	Tuple of bytes to step in each dimension when traversing
// an array.
// ndarray.ndim	Number of array dimensions.
// ndarray.data	Python buffer object pointing to the start of the array’s data.
// ndarray.size	Number of elements in the array.
// ndarray.itemsize	Length of one array element in bytes.
// ndarray.nbytes	Total bytes consumed by the elements of the array.
// ndarray.base	Base object if memory is from some other object.
//
// # Array methods
// ## Array conversion
// ndarray.copy([order])	Return a copy of the array.
// ndarray.view([dtype, type])	New view of array with the same data.
// ndarray.fill(value)	Fill the array with a scalar value.
//
// ## Shape manipulation
// ndarray.reshape(shape[, order])	Returns an array containing the same
// data
// with a new shape.
// ndarray.resize(new_shape[, refcheck])	Change shape and size of array
// in-place.
// ndarray.flatten([order])	Return a copy of the array collapsed into one
// dimension.
// ndarray.ravel([order])	Return a flattened array.
//
// ## Calculation
// ndarray.sum([axis, dtype, out, keepdims])	Return the sum of the array
// elements over the given axis.
// ndarray.cumsum([axis, dtype, out])	Return the cumulative sum of the
// elements along the given axis.
//
// ## Arithmetic
// ndarray.__add__	x.__add__(y) <==> x+y
// ndarray.__sub__	x.__sub__(y) <==> x-y
// ndarray.__mul__	x.__mul__(y) <==> x*y
// ndarray.__div__	x.__div__(y) <==> x/y
// ndarray.__truediv__	x.__truediv__(y) <==> x/y
//
// ## Arithmetic, in-place
// ndarray.__iadd__	x.__iadd__(y) <==> x+=y
// ndarray.__isub__	x.__isub__(y) <==> x-=y
// ndarray.__imul__	x.__imul__(y) <==> x*=y
// ndarray.__idiv__	x.__idiv__(y) <==> x/=y
// ndarray.__itruediv__	x.__itruediv__(y) <==> x/y
//
// ## Container customization
// ndarray.__len__() <==> len(x)
// ndarray.__getitem__	x.__getitem__(y) <==> x[y]
// ndarray.__setitem__	x.__setitem__(i, y) <==> x[i]=y
// ndarray.__getslice__	x.__getslice__(i, j) <==> x[i:j]
// ndarray.__setslice__	x.__setslice__(i, j, y) <==> x[i:j]=y
}

#endif
