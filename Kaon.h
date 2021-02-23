#ifndef KAON_H_
#define KAON_H_

#include "Particle.h"

class Kaon : public Particle
{

 public:

  /**
   * Constructors
   */
  Kaon();
  Kaon(const float px,
       const float py,
       const float pz);
  
  /**
   * Destructor
   */
  virtual ~Kaon();
  
  
  /**
   * Default charged kaon mass used to calculate energy given a momentum 3 vector
  */
  float KAON_MASS = 0.494; ///units in GeV/c
  	
};

#endif /* KAON_H_ */
