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

#include "functions/LogisticFunction.h"
#include "statistics/Randomizer.h"
#include "exceptions/BadArgumentException.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

LogisticDistribution::LogisticDistribution(double location, double scale) :
    mLocation(location) {
  setScale(scale);
}

LogisticDistribution::LogisticDistribution(const LogisticDistribution& other) :
    mLocation(other.mLocation),
    mScale(other.mScale),
    mInverseScale(other.mInverseScale) {
}

LogisticDistribution& LogisticDistribution::operator =
    (const LogisticDistribution& other) {
  if (this != &other) {
    mLocation = other.mLocation;
    mScale = other.mScale;
    mInverseScale = other.mInverseScale;
  }
  return *this;
}

LogisticDistribution::~LogisticDistribution() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void LogisticDistribution::read(std::istream& stream) {
}

void LogisticDistribution::write(std::ostream& stream) const {
  stream << "location: " << mLocation << std::endl
    << "scale: " << mScale;
}

void LogisticDistribution::read(std::ifstream& stream) {
}

void LogisticDistribution::write(std::ofstream& stream) const {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

void LogisticDistribution::setLocation(double location) {
  mLocation = location;
}

double LogisticDistribution::getLocation() const {
  return mLocation;
}

void LogisticDistribution::setScale(double scale) {
  if (scale <= 0)
    throw BadArgumentException<double>(scale,
      "LogisticDistribution<1>::setScale(): scale must be strictly positive",
      __FILE__, __LINE__);
  mInverseScale = 1.0 / scale;
  mScale = scale;
}

double LogisticDistribution::getScale() const {
  return mScale;
}

double LogisticDistribution::getInverseScale() const {
  return mInverseScale;
}

double LogisticDistribution::pdf(const RandomVariable& value) const {
  return exp(logpdf(value));
}

double LogisticDistribution::logpdf(const RandomVariable& value) const {
  return -(value - mLocation) * mInverseScale - (log(mScale) + 2 * log(1.0 +
    exp(-(value - mLocation) * mInverseScale)));
}

double LogisticDistribution::cdf(const RandomVariable& value) const {
  const static LogisticFunction<double> logisticFunction;
  return logisticFunction((value - mLocation) * mInverseScale);
}

LogisticDistribution::RandomVariable LogisticDistribution::getSample() const {
  const static Randomizer<double> randomizer;
  double y = 0;
  while (y == 0)
    y = randomizer.sampleUniform();
  return mLocation + mScale * log(y / (1 - y));
}

LogisticDistribution::Mean LogisticDistribution::getMean() const {
  return mLocation;
}

LogisticDistribution::Median LogisticDistribution::getMedian() const {
  return mLocation;
}

LogisticDistribution::Mode LogisticDistribution::getMode() const {
  return mLocation;
}

LogisticDistribution::Variance LogisticDistribution::getVariance() const {
  return M_PI * M_PI / 3.0 * mScale * mScale;
}
