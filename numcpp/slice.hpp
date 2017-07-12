#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>
#include <valarray>

namespace numcpp {

using std::size_t;

struct slice_t {
  size_t start;
  size_t end;
  size_t step;
};

class slice : protected std::slice {
public:
  slice() : std::slice{} {}
  slice(size_t start, size_t end, size_t step)
      : std::slice{start, 1 + (((end - start) - 1) / step), step} {}
  slice(const slice &other)
      : std::slice{static_cast<const std::slice &>(other)} {}

  size_t start() const {
    const std::slice& self = *this;
    return self.start();
  }
  size_t end() const {
    return (this->size() - 1) * this->step() + 1 + this->start();
  }
  size_t step() const { return this->stride(); }
};
}

#endif
