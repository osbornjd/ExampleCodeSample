#include "Kaon.h"
#include <cmath>

/**
 * Default constructor
 */
Kaon::Kaon() : Particle()
{
  _px = 0;
  _py = 0;
  _pz = 0;
  _energy = 0;
}

/**
 * Constructor with 3 momentum which defines energy with default kaon mass
 */
Kaon::Kaon(const float px,
	   const float py,
	   const float pz)
  : Particle(px,py,pz)
{

  _px = px;
  _py = py;
  _pz = pz;
  _energy = sqrt( _px * px + py * py + pz * pz + KAON_MASS * KAON_MASS);
}

/**
 * Destructor
 */
Kaon::~Kaon () {}

