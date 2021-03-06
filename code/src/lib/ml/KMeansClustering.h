/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

/** \file KMeansClustering.h
    \brief This file implements a K-Means clustering algorithm
  */

#ifndef KMEANSCLUSTERING_H
#define KMEANSCLUSTERING_H

#include <vector>

#include <Eigen/Core>

/** This file implements a K-means clustering algorithm based on
    Expectation-Maximization.
    \brief K-Means clustering algorithm
  */
namespace KMeansClustering {
  /** \name Methods
    @{
    */
  /// Clusters the input data points
  template <typename T, size_t M>
  size_t cluster(const std::vector<Eigen::Matrix<T, M, 1> >& data,
    std::vector<Eigen::Matrix<T, M, 1> >& clusterCenters,
    std::vector<std::vector<size_t> >& clusterToData, std::vector<size_t>&
    dataToCluster, size_t k, size_t maxIterations = 10000, double tol = 1e-6,
    bool debug = false);
  /** @}
    */

};

#include "ml/KMeansClustering.tpp"

#endif // KMEANSCLUSTERING_H
