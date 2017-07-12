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

template <class T>
std::valarray<T> push_front(const T &v, const std::valarray<T> &arr) {
  std::valarray<T> narr(arr.size() + 1);
  narr[0] = v;
  narr[std::slice(1, arr.size(), 1)] = arr;
  return narr;
}

class Array {
private:
  std::gslice gslice;
  using array_type = valarray<double>;

  Array(std::gslice gslice, shared_ptr<array_type> data)
      : gslice{gslice}, data{data} {}

public: shared_ptr<array_type> data;
  using value_type = double;

  Array(const Array &arr) : gslice{arr.gslice}, data{arr.data} {}
  Array(Array &&arr) noexcept
      : gslice{std::move(arr.gslice)}, data{std::move(arr.data)} {}
  Array(initializer_list<double> il)
      : gslice{0, {il.size()}, {1}}, data{make_shared<array_type>(il)} {}
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
    // template <class T, class... Tail>
    // std::gslice subselect(std::gslice gs, T slice, Tail... tail) {
    //
    //   size_t tail_start = gs.start() + slice.start * gs.stride()[0];
    //
    //   size_t tail_size = 1 + (((slice.end - slice.start) - 1) / slice.step);
    //
    //   size_t tail_stride = gs.stride()[0] * slice.step;
    //
    //   std::slice sl(1, gs.size().size(), 1);
    //   std::gslice gs_tail(tail_start, gs.size()[sl], gs.stride()[sl]);
    //
    //   std::gslice new_gs(subselect(gs_tail, tail...));
    //
    //   return std::gslice(new_gs.start(), push_front(tail_size, new_gs.size()),
    //                      push_front(tail_stride, new_gs.stride()));
    // }

  // template <class... Args> Array operator()(Args... args) {
  //   // std::gslice gs = subselect(gslice, args...);
  //   std::gslice gs = gslice;
  //   return Array{gs, data};
  // }
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
