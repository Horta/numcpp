#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <valarray>

namespace numcpp {

using shape_t = std::valarray<size_t>;

std::gslice make_gslice(const shape_t &shape) {
  return std::gslice(0, shape, shape_t{sizeof(double), shape.size()});
}
}

#endif
