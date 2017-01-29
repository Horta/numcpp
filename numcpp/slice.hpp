#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>

namespace numcpp {

  struct slice_t {
    size_t start;
    size_t end;
    size_t step;
  };

}

#endif
