#include "Event_Parser.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

/**
 * Default constructor
 */

Event_Parser::Event_Parser()
{
  _nevents = 0;
}

/**
 * Constructor with a specific number of events to analyze
 */

Event_Parser::Event_Parser(int nevents)
{
  _nevents = nevents;
}

/**
 * Default destructor
 */

Event_Parser::~Event_Parser () {}


/**
 * Function which returns a vector of events
 * The string filepath should be the path to the directory where the 
 * event information lies.
 * The string filename should be a default filename which can be used 
 * to identify  the events, where the filename is the same for all events 
 * except for the event  numbers. For example, eventnum1.txt, eventnum2.txt, etc.
 */

std::vector<Event> Event_Parser::get_events(std::string filepath,
					    std::string filename)
{

  std::vector<Event> event_vector;

  for( int i = 0 ; i < _nevents; ++i )
    {

      std::string totalpath = filepath + filename +
	std::to_string(i) + ".txt";
  
      ifstream file( totalpath );

      std::vector<Particle> particles;
      
      if( file.is_open() )
	{
	  int particle_id, particle_status;
	  float particle_px, particle_py, particle_pz, particle_energy;
	  
	  /**
	   * Get all the particles from the ifstream file
	   */
	  while ( file >> particle_id >> particle_status
		       >> particle_px >> particle_py
		       >> particle_pz >> particle_energy )
	    {
	  
	      Particle particle(particle_px,
				particle_py,
				particle_pz,
				particle_energy);
	      
        
	      particles.push_back(particle);
	    }

	  Event this_event(particles);

	  event_vector.push_back(this_event);
	}
      else 
	{
	  std::cout << "No file is open for event " << i
		    << "! Going to the next event number."
		    << std::endl;
	}
    }


  return event_vector;

}


/**
 * Getter and setter functions for the number of events to analyze
 */

void Event_Parser::set_event_num(int nevents)
{
  _nevents = nevents;
}

int Event_Parser::get_event_num()
{
  return _nevents;
}
