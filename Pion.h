#ifndef PION_H_
#define PION_H_

#include "Particle.h"

class Pion : public Particle
{

 public:
  
  /**
   * Constructors
   */
  Pion();
  Pion(const float px,
       const float py,
       const float pz);
  
  /**
   * Destructor
   */
  virtual ~Pion();
  

  /**
   * Default charged pion mass used to calculate energy given a momentum 3 vector
   */
  float PION_MASS = 0.139; ///units are in GeV/c

};

#endif /* PION_H_ */
