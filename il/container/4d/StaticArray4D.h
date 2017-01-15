//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#ifndef IL_STATICARRAY4D_H
#define IL_STATICARRAY4D_H

// <cstring> is needed for memcpy
#include <cstring>
// <initializer_list> is needed for std::initializer_list<T>
#include <initializer_list>
// <type_traits> is needed for std::is_pod
#include <type_traits>

#include <il/base.h>

namespace il {

template <class T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
class StaticArray4D {
  static_assert(n0 >= 0,
                "il::StaticArray4D<T, n0, n1, n2, n3>: n0 must be nonnegative");
  static_assert(n1 >= 0,
                "il::StaticArray4D<T, n0, n1, n2, n3>: n1 must be nonnegative");
  static_assert(n2 >= 0,
                "il::StaticArray4D<T, n0, n1, n2, n3>: n2 must be nonnegative");

 private:
  T data_[n0 * n1 * n2 * n3 > 0 ? (n0* n1* n2* n3) : 1];
  il::int_t size_0_ = n0;
  il::int_t size_1_ = n1;
  il::int_t size_2_ = n2;
  il::int_t size_3_ = n3;

 public:
  StaticArray4D();
  StaticArray4D(const T& value);
  const T& operator()(il::int_t i0, il::int_t i1, il::int_t i2,
                      il::int_t i3) const;
  T& operator()(il::int_t i0, il::int_t i1, il::int_t i2, il::int_t i3);
  il::int_t size(il::int_t d) const;
  const T* data() const;
  T* data();
};

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
StaticArray4D<T, n0, n1, n2, n3>::StaticArray4D() {
  if (std::is_pod<T>::value) {
#ifndef NDEBUG
    for (il::int_t l = 0; l < n0 * n1 * n2 * n3; ++l) {
      data_[l] = il::default_value<T>();
    }
#endif
  }
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
StaticArray4D<T, n0, n1, n2, n3>::StaticArray4D(const T& value) {
  for (il::int_t l = 0; l < n0 * n1 * n2 * n3; ++l) {
    data_[l] = value;
  }
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
const T& StaticArray4D<T, n0, n1, n2, n3>::operator()(il::int_t i0,
                                                      il::int_t i1,
                                                      il::int_t i2,
                                                      il::int_t i3) const {
  IL_ASSERT(static_cast<il::uint_t>(i0) < static_cast<il::uint_t>(n0));
  IL_ASSERT(static_cast<il::uint_t>(i1) < static_cast<il::uint_t>(n1));
  IL_ASSERT(static_cast<il::uint_t>(i2) < static_cast<il::uint_t>(n2));
  IL_ASSERT(static_cast<il::uint_t>(i3) < static_cast<il::uint_t>(n3));
  return data_[((i3 * n2 + i2) * n1 + i1) * n0 + i0];
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
T& StaticArray4D<T, n0, n1, n2, n3>::operator()(il::int_t i0, il::int_t i1,
                                                il::int_t i2, il::int_t i3) {
  IL_ASSERT(static_cast<il::uint_t>(i0) < static_cast<il::uint_t>(n0));
  IL_ASSERT(static_cast<il::uint_t>(i1) < static_cast<il::uint_t>(n1));
  IL_ASSERT(static_cast<il::uint_t>(i2) < static_cast<il::uint_t>(n2));
  IL_ASSERT(static_cast<il::uint_t>(i3) < static_cast<il::uint_t>(n3));
  return data_[((i3 * n2 + i2) * n1 + i1) * n0 + i0];
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
il::int_t StaticArray4D<T, n0, n1, n2, n3>::size(il::int_t d) const {
  IL_ASSERT(static_cast<il::uint_t>(d) < static_cast<il::uint_t>(4));
  return d == 0 ? n0 : (d == 1 ? n1 : (d == 2 ? n2 : n3));
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
const T* StaticArray4D<T, n0, n1, n2, n3>::data() const {
  return data_;
}

template <typename T, il::int_t n0, il::int_t n1, il::int_t n2, il::int_t n3>
T* StaticArray4D<T, n0, n1, n2, n3>::data() {
  return data_;
}
}

#endif  // IL_STATICARRAY4D_H
