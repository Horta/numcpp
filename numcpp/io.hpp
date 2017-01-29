#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include "array.hpp"

namespace numcpp {

inline std::ostream &operator<<(std::ostream &o, const Array &arr) {
  o << '[';
  for (const auto &v : *arr.data) {
    o << v << " ";
  }
  o << '\b' << "]";
  return o;
}
//
// inline std::ostream &operator<<(std::ostream &o, const shape_t &shape) {
//   o << '(';
//   for (const auto &v : shape) {
//     o << v << ", ";
//   }
//   o << "\b\b"
//     << ")";
//   return o;
// }
}
#endif
