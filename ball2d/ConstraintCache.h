// ConstraintCache.h
//
// Breannan Smith
// Last updated: 09/03/2015

// TODO: Can generalize this class so it is shared across 2d/3d sims

#ifndef CONSTRAINT_CACHE_H
#define CONSTRAINT_CACHE_H

#include "SCISim/Math/MathDefines.h"

class Constraint;

class ConstraintCache final
{

public:

  void cacheConstraint( const Constraint& constraint, const VectorXs& r );
  void getCachedConstraint( const Constraint& constraint, VectorXs& r ) const;
  void clear();

  void serialize( std::ostream& output_stream ) const;
  void deserialize( std::istream& input_stream );

private:

  std::map<std::pair<unsigned,unsigned>,VectorXs> m_ball_ball_constraints;
  std::map<std::pair<unsigned,unsigned>,VectorXs> m_plane_ball_constraints;
  std::map<std::pair<unsigned,unsigned>,VectorXs> m_drum_ball_constraints;

};

#endif