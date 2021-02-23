#include "Particle.h"
#include <cmath>
#include <iostream>
using namespace std;


///Default constructor - initializes 4 vector to 0
Particle::Particle()
{
  _px = 0;
  _py = 0;
  _pz = 0;
  _energy = 0;
}

/**
 * Default constructor. Sets _particles 4 vector 
 */

Particle::Particle(const float px,
		   const float py,
		   const float pz,
		   const float energy)
{

  _px = px;
  _py = py;
  _pz = pz;
  _energy = energy;

}

/**
 * Momentum vector constructor for Particle ID subclasses
 */
Particle::Particle(const float px,
		   const float py,
		   const float pz)
{

  _px = px;
  _py = py;
  _pz = pz;
  ///Just default set the energy to the momentum since it does not matter for a 3 vector
  _energy = sqrt( px * px + py * py + pz * pz );

}

/**
 * Default destructor
 */
Particle::~Particle () {}


/**
 * Getter functions - can obtain some basic quantities from the particle 4 vector
 */

///Get the azimuthal angle 
float Particle::get_phi()
{
  return atan( _py / _px );
}

///Get the transverse momentum
float Particle::get_pt()
{
  return sqrt( _px * _px + _py * _py );
}

///Get the total 3 momentum
float Particle::get_p()
{
  return sqrt( _px * _px + _py * _py + _pz * _pz );
} 

///Get the pseudorapidity
float Particle::get_pseudorapidity()
{
  float p = get_p();
  return 0.5 * log ( (p + _pz ) / (p - _pz ) );
}

///Get the rapidity
float Particle::get_rapidity()
{
  return 0.5 * log( ( _energy + _pz )/ ( _energy - _pz ) );
}

///Get the mass of the particle
float Particle::get_mass()
{
  return sqrt( _energy * _energy - get_p() * get_p() );
}

/**
 * Basic setter functions for changing the 4 vector information
 */

void Particle::set_px( float px )
{
  _px = px;
}

void Particle::set_py( float py )
{
  _py = py;
}

void Particle::set_pz( float pz )
{
  _pz = pz;
}

void Particle::set_energy( float energy )
{
  _energy = energy;
}

float Particle::get_px()
{
  return _px;
}

float Particle::get_py()
{
  return _py;
}

float Particle::get_pz()
{
  return _pz;
}

float Particle::get_energy()
{
  return _energy;
}

/**
 * Useful functions to compare two particles to one another
 */

///Get the azimuthal angle difference between this Particle and the passed Particle
float Particle::delta_phi ( Particle& part )
{
  float dphi = get_phi() - part.get_phi();

  ///Wrap delta phi around from [-pi,pi]
  if( dphi > M_PI )
    dphi -= 2. * M_PI;
  
  if ( dphi < -1 * M_PI )
    dphi += 2. * M_PI;

  return dphi;
}

///Get the deltaR between two particles in azimuth-pseudorapidity space
float Particle::deltaR ( Particle& part )
{
  float dphi = delta_phi( part );
  
  float deta = get_pseudorapidity() - part.get_pseudorapidity();
  
  float dr = sqrt ( dphi * dphi + deta * deta );

  return dr;
}
