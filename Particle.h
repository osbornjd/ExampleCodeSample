#ifndef PARTICLE_H_
#define PARTICLE_H_


class Particle {

 public:

  /**
   * Constructors
   */
  Particle (); 
  Particle( const float px,
	    const float py,
	    const float pz,
	    const float energy);

  /**
   * Constructor for specific particle ID 
   */
  Particle( const float px,
	    const float py,
	    const float pz);

  /**
   * Default destructor
   */
  
  virtual ~Particle();


  /**
   * Main class members for 4 vector calculations
   */
  
  float _px, _py, _pz, _energy;

  /**
   * Basic getter functions to obtain 4 vector information
   */
  float get_phi();
  float get_pseudorapidity();
  float get_rapidity();
  float get_pt();
  float get_p();
  float get_mass();
  float get_px();
  float get_py();
  float get_pz();
  float get_energy();
  
  /**
   * Basic setter functions for changing the 4 vector information
   */
  void set_px ( float px );
  void set_py ( float py );
  void set_pz ( float pz );
  void set_energy ( float energy );


  /**
   * Useful Particle to Particle comparisons
   */

  float delta_phi ( Particle& part );
  float deltaR ( Particle& part );
  

};

#endif /* PARTICLE_H_ */
    
	   
