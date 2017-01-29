#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "reduce.hpp"
#include "shape.hpp"
#include <memory>
#include <valarray>

namespace numcpp {

using std::shared_ptr;
using std::make_shared;
using std::valarray;
using std::initializer_list;

class Array {
private:
  std::gslice gslice;
  shared_ptr<valarray<double>> data;
  using array_type = valarray<double>;

public:
  using value_type = double;

  Array(const Array &arr) : gslice{arr.gslice}, data{arr.data} {}
  Array(Array &&arr)
      : gslice{std::move(arr.gslice)}, data{std::move(arr.data)} {}
  Array(initializer_list<double> il)
      : gslice{0, {il.size()}, {1}}, data{make_shared<array_type>(il)} {}
  Array(std::gslice gslice, shared_ptr<array_type> data)
      : gslice{gslice}, data{data} {}
  Array(const shape_t &shape)
      : gslice{make_gslice(shape)},
        data{make_shared<array_type>(product_reduce<shape_t::value_type>(
            std::begin(shape), std::end(shape)))} {}

  size_t ndim(void) const { return gslice.size().size(); }
  operator double(void) const { return (*data)[0]; }
  void fill(double v) { *data = v; }
  size_t size(void) const {
    auto size = gslice.size();
    return product_reduce<size_t>(std::begin(size), std::end(size));
  }
  shape_t shape(void) const { return shape_t{gslice.size()}; }

  //   template <class... Tail> std::gslice subselect(std::gslice gs, Tail...
  //   tail);
  //
  //   template <class... Tail> std::gslice subselect(std::gslice gs) {
  //     return std::gslice(gs.start(), va<size_t>(0), va<size_t>(0));
  //   }
  //
  //   template <class Head, class... Tail>
  //   std::gslice subselect(std::gslice gs, Head slice, Tail... tail) {
  //
  //     size_t start = gs.start() + slice.start * gs.stride()[0];
  //
  //     size_t size = 1 + (((slice.end - slice.start) - 1) / slice.step);
  //
  //     size_t stride = gs.stride()[0] * slice.step;
  //
  //     std::slice sl(1, gs.size().size(), 1);
  //     std::gslice gs_tail(start, gs.size()[sl], gs.stride()[sl]);
  //
  //     std::gslice new_gs(subselect(gs_tail, tail...));
  //
  //     return std::gslice(new_gs.start(), push_front(size, new_gs.size()),
  //                        push_front(stride, new_gs.stride()));
  //   }
  //
  //   template <class... Args> Array operator()(Args... args) {
  //     std::gslice gs = subselect(gslice, args...);
  //     return Array(gs, this->data);
  //   }
  //

  //

  //
  //   class iterator {
  //   public:
  //     typedef iterator self_type;
  //     typedef Array value_type;
  //     typedef Array &reference;
  //     typedef std::forward_iterator_tag iterator_category;
  //     // typedef int difference_type;
  //     iterator(reference m, size_t index) : m(m), index(index) {}
  //     self_type operator++() {
  //       self_type i = *this;
  //       index++;
  //       return i;
  //     }
  //     self_type operator++(int junk) {
  //       index++;
  //       return *this;
  //     }
  //     value_type operator*() { return m(index); }
  //     bool operator==(const self_type &rhs) {
  //       return &m == &(rhs.m) && index == rhs.index;
  //     }
  //     bool operator!=(const self_type &rhs) {
  //       return &m != &(rhs.m) && index != rhs.index;
  //     }
  //
  //   private:
  //     Array &m;
  //     size_t index;
  //   };
  //
  //   // iterator begin() { return iterator((*self)[0]); }
  //   // iterator end() { return iterator(data_ + size_); }
};
}

#endif
