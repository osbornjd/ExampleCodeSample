#ifndef EVENT_H_
#define EVENT_H_
#include "Particle.h"
#include <vector>

class Event {


 public:
  /**
   * Basic constructors
   */
  Event();
  
  Event(const std::vector<Particle> & particles);

  /**
   * Destructor
   */ 
  virtual ~Event();

  /**
   * Get the particles for an event
   */
  std::vector<Particle> get_particles();

  /**
   * Set the particles for an event if using with default constructor
   */
  void set_particles(std::vector<Particle> particles);

  /**
   * Returns the number of particles in an event
   */
  int num_particles_in_event();

  /**
   * Vector containing all of the particles in an event
   */ 
  std::vector<Particle> _particles;

};

#endif /* EVENT_H_ */
