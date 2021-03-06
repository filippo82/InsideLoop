//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#ifndef IL_CUDASPARSEMATRIXCSR_H
#define IL_CUDASPARSEMATRIXCSR_H

#include <il/container/cuda/1d/CudaArray.h>

namespace il {

template <typename T>
class CudaSparseMatrixCSR {
 private:
  il::int_t n0_;
  il::int_t n1_;
  il::CudaArray<int> row_;
  il::CudaArray<int> column_;
  il::CudaArray<T> element_;

 public:
  CudaSparseMatrixCSR(il::int_t n0, il::int_t n1, il::CudaArray<int> row,
                      il::CudaArray<int> column, il::CudaArray<T> element);
  il::int_t size(il::int_t d) const;
  il::int_t nbNonZeros() const;
  const int* rowData() const;
  const int* columnData() const;
  const T* elementData() const;
};

template <typename T>
CudaSparseMatrixCSR<T>::CudaSparseMatrixCSR(il::int_t n0, il::int_t n1,
                                            il::CudaArray<int> row,
                                            il::CudaArray<int> column,
                                            il::CudaArray<T> element)
    : row_{row}, column_{column}, element_{element} {
  n0_ = n0;
  n1_ = n1;
}

template <typename T>
il::int_t CudaSparseMatrixCSR<T>::size(il::int_t d) const {
  IL_EXPECT_FAST(d >= 0 && d < 2);

  return d == 0 ? n0_ : n1_;
}

template <typename T>
il::int_t CudaSparseMatrixCSR<T>::nbNonZeros() const {
  return element_.size();
}

template <typename T>
const int* CudaSparseMatrixCSR<T>::rowData() const {
  return row_.data();
}

template <typename T>
const int* CudaSparseMatrixCSR<T>::columnData() const {
  return column_.data();
}

template <typename T>
const T* CudaSparseMatrixCSR<T>::elementData() const {
  return element_.data();
}

}  // namespace il

#endif  // IL_CUDASPARSEMATRIXCSR_H
