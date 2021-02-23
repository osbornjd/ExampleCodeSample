#include "event_analyzer.h"
using namespace std;


int main(int argc, char * argv[])
{


  Event_Parser parser(num_events);

  auto events = parser.get_events(filepath, filename);

  float avg_pionpion_distance = 0.;
  float avg_kaonkaon_distance = 0.;
  
  /**
   * Calculate the average distances between pion-pion pairs and kaon-kaon pairs
   */ 
 calculate_distances(events,
		      avg_pionpion_distance,
		      avg_kaonkaon_distance);


 /**
  * Print out the averages for easy reading 
  */
 std::cout<<std::setprecision(4)<<"Charged pions are, on average, separated by "
	   <<avg_pionpion_distance<<" in azimuthal-pseudorapidity space"
	   <<std::endl;

 std::cout<<std::setprecision(4)<<"Charged Kaons are, on average, separated by "
	   <<avg_kaonkaon_distance<<" in azimuthal-pseudorapidity space"
	   <<std::endl;
  
  return 1;  
}

/**
 * Calculate the distances between pion-pion pairs and kaon-kaon pairs
 */ 
void calculate_distances(std::vector<Event> events,
			 float &pipi,	        
			 float &kk)
{

  int total_pions_analyzed = 0;
  int total_kaons_analyzed = 0;

  /**
   * Loop over all the events to analyze
   */
  for(int i = 0; i < events.size(); ++i )
    {
      auto numparts_in_event = events.at(i).num_particles_in_event();

      std::vector <Pion> pions;
      std::vector <Kaon> kaons;

      /**
       * Collect the pions and kaons in a given event i 
       */   
      for(int j = 0; j < numparts_in_event; ++j )
	{
	  auto particle = events.at(i).get_particles().at(j);
	  /**
	   * Just analyze pions in a given pseudorapidity range defined by the cut
	   */	 
	  if(fabs( particle.get_pseudorapidity() ) > pseudorapidity_cut )
	    continue;

	  /**
	   * Check that the masses are within 5% of the measured pion or kaon mass.
	   * This accounts for the particles being slightly off mass shell.
	   */
	  if( fabs( 1. - particle.get_mass() / PION_MASS ) < 0.05 )
	    {
	      pions.push_back( Pion( particle.get_px(),
				     particle.get_py(),
				     particle.get_pz() ) );
	    }
	  
	  if( fabs( 1. - particle.get_mass() / KAON_MASS ) <0.05 )
	    {
	      kaons.push_back( Kaon( particle.get_px(),
				     particle.get_py(),
				     particle.get_pz() ) );
	    }

	} ///collected pions and kaons in an event

      /**
       * Now compare the particles to one another to determine 
       * distance in pseudorapidity-phi space
       */
      for(int j = 0; j < pions.size(); ++j)
	{
	  Pion pion1 = pions.at(j);
	  
	  /**
	   * Start at j to avoid double counting
	   */	  
	  for(int k = j; k < pions.size(); ++k) 
	    {
	      /**
	       * Don't want to compare the particle to itself
	       */
	      if( j == k )
		continue;
	      
	      Pion pion2 = pions.at(k);

	      pipi += pion1.deltaR(pion2);
	      total_pions_analyzed++;
	      
	    }
	}

    
      for(int j = 0; j < kaons.size(); ++j)
	{
	  Kaon kaon1 = kaons.at(j);
	  /**
	   *  Start at j to avoid double counting
	   */
	  for(int k = j; k < kaons.size(); ++k)
	    {
	      /**
	       * Don't want to compare the particle to itself
	       */
	      if( j == k )
		continue;
	      
	      Kaon kaon2 = kaons.at(k);

	      kk += kaon1.deltaR(kaon2);
	      total_kaons_analyzed++;
	    }
	}
      /**
       * Make sure to resize the vectors, just to be sure we don't have events mixing with each other
       */
      pions.resize(0);
      kaons.resize(0);

    } ///Event loop
      

  /**
   * Now take the average by dividing by the total number of particles analyzed
   * These are pointers so they get "returned"
   */  
  pipi /= total_pions_analyzed;
  kk /= total_kaons_analyzed;
  
}
