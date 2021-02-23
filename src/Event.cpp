#include "Event.h"

/**
 * Default constructor - just create an event with a default particle
 */
Event::Event()
{
  _particles.push_back(Particle());
}

/**
 * Default constructor. Sets _particles to the particles in this event
 */

Event::Event(const std::vector <Particle> & particles)
{
  _particles = particles;
}

/**
 * Default destructor
 */
Event::~Event () {}


/**
 * Get a vector of particles for this event
 */
std::vector<Particle> Event::get_particles()
{
  return _particles;
}

/**
 * Set the particles for this event
 */
void Event::set_particles(std::vector<Particle> particles)
{
  _particles = particles;
}

/**
 * Return the number of particles in an event
 */
int Event::num_particles_in_event()
{
  return _particles.size();
}
