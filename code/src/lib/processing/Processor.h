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

/** \file Processor.h
    \brief This file defines the Processor class, which performs all the
           computations to detect planes, curbs, and sidewalks.
  */

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "base/Serializable.h"
#include "data-structures/Grid.h"
#include "data-structures/Cell.h"
#include "data-structures/PointCloud.h"
#include "data-structures/DEMGraph.h"
#include "statistics/MixtureDistribution.h"

/** The class Processor performs all the computations to detect planes, curbs,
    and sidewalks from a 3D point cloud input.
    \brief Processor for curb detection
  */
class Processor :
  public virtual Serializable {
public:
  /** \name Constructors/destructor
    @{
    */
  /// Constructors with parameters
  Processor(const Grid<double, Cell, 2>::Coordinate& minDEM =
    Grid<double, Cell, 2>::Coordinate(0.0, 0.0),
    const Grid<double, Cell, 2>::Coordinate& maxDEM =
    Grid<double, Cell, 2>::Coordinate(4.0, 4.0),
    const Grid<double, Cell, 2>::Coordinate& demCellSize =
    Grid<double, Cell, 2>::Coordinate(0.1, 0.1), double k = 300.0,
    size_t maxMLIter = 200, double mlTol = 1e-6, bool weighted = false,
    size_t maxBPIter = 200, double bpTol = 1e-6, bool logDomain = false);
  /// Copy constructor
  Processor(const Processor& other);
  /// Assignment operator
  Processor& operator = (const Processor& other);
  /// Destructor
  virtual ~Processor();
  /** @}
    */

  /** \name Accessors
      @{
    */
  /// Returns the DEM minimum coordinates
  const Grid<double, Cell, 2>::Coordinate& getMinDEM() const;
  /// Sets the DEM minimum coordinates
  void setMinDEM(const Grid<double, Cell, 2>::Coordinate& minDEM);
  /// Returns the DEM maximum coordinates
  const Grid<double, Cell, 2>::Coordinate& getMaxDEM() const;
  /// Sets the DEM maximum coordinates
  void setMaxDEM(const Grid<double, Cell, 2>::Coordinate& maxDEM);
  /// Returns the DEM cell size
  const Grid<double, Cell, 2>::Coordinate& getDEMCellSize() const;
  /// Sets the DEM cell size
  void setDEMCellSize(const Grid<double, Cell, 2>::Coordinate& demCellSize);
  /// Returns the segmentation parameter
  double getSegmentationParam() const;
  /// Sets the segmentation parameter
  void setSegmentationParam(double k);
  /// Returns the ML maximum number of iterations
  size_t getMLMaxIter() const;
  /// Sets the ML maximum number of iterations
  void setMLMaxIter(size_t maxMLIter);
  /// Returns the ML tolerance
  double getMLTol() const;
  /// Sets the ML tolerance
  void setMLTol(double mlTol);
  /// Returns the weighted regression flag
  bool getWeightedRegressionFlag() const;
  /// Sets the weighted regression flag
  void setWeightedRegressionFlag(bool weighted);
  /// Returns the BP maximum number of iterations
  size_t getBPMaxIter() const;
  /// Sets the BP maximum number of iterations
  void setBPMaxIter(size_t maxBPIter);
  /// Returns the BP tolerance
  double getBPTol() const;
  /// Sets the BP tolerance
  void setBPTol(double bpTol);
  /// Returns the log-domain inference flag
  bool getLogDomainFlag() const;
  /// Sets the log-domain inference flag
  void setLogDomainFlag(bool logDomain);
  /// Returns the DEM
  const Grid<double, Cell, 2>& getDEM() const;
  /// Returns the DEM graph
  const DEMGraph& getDEMGraph() const;
  /// Returns the labeling
  const DEMGraph::VertexContainer& getVerticesLabels() const;
  /// Returns the valid flag of the processor
  bool getValid() const;
  /** @}
    */

  /** \name Methods
      @{
    */
  /// Process a point cloud
  void processPointCloud(const PointCloud<double, 3>& pointCloud);
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from standard input
  virtual void read(std::istream& stream);
  /// Writes to standard output
  virtual void write(std::ostream& stream) const;
  /// Reads from a file
  virtual void read(std::ifstream& stream);
  /// Writes to a file
  virtual void write(std::ofstream& stream) const;
  /** @}
    */

  /** \name Protected members
      @{
    */
  /// DEM min coordinate
  Grid<double, Cell, 2>::Coordinate mMinDEM;
  /// DEM max coordinate
  Grid<double, Cell, 2>::Coordinate mMaxDEM;
  /// DEM cells size
  Grid<double, Cell, 2>::Coordinate mDEMCellSize;
  /// Segmentation parameter
  double mK;
  /// ML maximum number of iterations
  size_t mMaxMLIter;
  /// ML tolerance
  double mMLTol;
  /// Weighted regression flag
  bool mWeighted;
  /// BP maximum number of iterations
  size_t mMaxBPIter;
  /// BP tolerance
  double mBPTol;
  /// Log-domain inference
  bool mLogDomain;

  /// DEM
  Grid<double, Cell, 2> mDEM;
  /// DEM graph
  DEMGraph mGraph;
  /// Vertices labels
  DEMGraph::VertexContainer mVerticesLabels;

  /// One point cloud has been processed and we have valid results
  bool mValid;
  /** @}
    */

};

#endif // PROCESSOR_H
