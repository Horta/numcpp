#ifndef REDUCE_HPP
#define REDUCE_HPP

#include <numeric>
#include <functional>

namespace numcpp {

  template <class T, class Iterator>
  T product_reduce(Iterator begin, Iterator end) {
    return std::accumulate(begin, end, 1, std::multiplies<T>());
  }


}

#endif
