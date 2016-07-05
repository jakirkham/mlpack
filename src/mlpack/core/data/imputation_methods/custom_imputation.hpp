/**
 * @file custom_imputation.hpp
 * @author Keon Kim
 *
 * Definition and Implementation of the empty CustomImputation class.
 */
#ifndef MLPACK_CORE_DATA_IMPUTE_STRATEGIES_CUSTOM_IMPUTATION_HPP
#define MLPACK_CORE_DATA_IMPUTE_STRATEGIES_CUSTOM_IMPUTATION_HPP

#include <mlpack/core.hpp>
#include <cmath>

using namespace std;

namespace mlpack {
namespace data {

template <typename T>
class CustomImputation
{
 public:
  void Impute(const arma::Mat<T>& input,
              arma::Mat<T>& output,
              const T& mappedValue,
              const T& customValue,
              const size_t dimension,
              const bool transpose = true)
  {
    // initiate output
    output = input;

    // replace the target value to custom value
    if (transpose)
    {
      for (size_t i = 0; i < input.n_cols; ++i)
      {
        if (input(dimension, i) == mappedValue ||
            std::isnan(input(dimension, i)))
        {
          output(dimension, i) = customValue;
        }
      }
    }
    else
    {
      for (size_t i = 0; i < input.n_rows; ++i)
      {
        if (input(i, dimension) == mappedValue ||
            std::isnan(input(i, dimension)))
        {
          output(i, dimension) = customValue;
        }
      }
    }
  }
}; // class CustomImputation

} // namespace data
} // namespace mlpack

#endif
