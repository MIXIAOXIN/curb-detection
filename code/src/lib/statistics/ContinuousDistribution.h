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

/** \file ContinuousDistribution.h
    \brief This file is an interface to the continuous distributions
  */

#ifndef CONTINUOUSDISTRIBUTION_H
#define CONTINUOUSDISTRIBUTION_H

#include <cstdlib>

template <typename X, size_t M = 1, size_t N = 1> class ContinuousDistribution;

#include "statistics/ContinuousDistribution1v.h"
#include "statistics/ContinuousDistributionMv.h"

#endif // CONTINUOUSDISTRIBUTION_H
