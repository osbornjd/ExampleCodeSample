#include "test.h"

int main(int argc, char * argv[])
{
 
  std::cout << "TESTING EVENT CLASS"
	    << std::endl << std::endl;

  test_event();

  std::cout << std::endl << std::endl << "TESTING PARTICLE CLASS"
	    << std::endl << std::endl;

  test_particle();

  std::cout << std::endl << std::endl << "TESTING PION CLASS"
	    << std::endl << std::endl;

  test_pion();

  std::cout<< std::endl << std::endl << "TESTING PARSER CLASS"
	   << std::endl << std::endl;

  test_parser();


  return 1;
}

void test_event()
{
  /**
   * Just make a dummy event and test some functions with it
   */

  Event dumevent;
  std::cout << "Default Event constructor yields "
	    << dumevent.num_particles_in_event() << std::endl;

  std::vector<Particle> dumparticles = dumevent.get_particles();
  
  std::cout << "Default Event constructor gives " << dumparticles.size()
	    << " particle, which has a boring 4 vector of ("
	    << dumparticles.at(0).get_px() << ","
	    << dumparticles.at(0).get_py() << ","
	    << dumparticles.at(0).get_pz() << ","
	    << dumparticles.at(0).get_energy() << ")"
	    << std::endl;

  ///Make dumparticles more interesting with some random Particles
  dumparticles.push_back( Particle(9,10,11,50) );
  dumparticles.push_back( Particle(3,4,5,6) );

  dumevent.set_particles(dumparticles);
  
  std::cout << "Set Event particles to a new vector with length "
	    << dumevent.num_particles_in_event()
	    << std::endl;
}

void test_particle()
{
  /**
   * Just make dummy particles and test some functions with them
   */

  Particle dum1;
  Particle dum2(5,3,-0.5,9);
  Particle dum3(3,-11,4);

  dum3.set_energy(14);

  dum1.set_px( 99 );
  dum1.set_py( 53 );
  dum1.set_pz( -100 );
  dum1.set_energy( 187 );
  
  std::cout << "dum1 4vec: (" << dum1.get_px() << ","
	    << dum1.get_py() << "," << dum1.get_pz()
	    << "," << dum1.get_energy() << ")"
	    << std::endl;

  std::cout << "dum2 4vec: (" << dum2.get_px() << ","
	    << dum2.get_py() << ","
	    << dum2.get_pz() << ","
	    << dum2.get_energy() << ")"
	    << std::endl;

  std::cout << "dum1 phi: " << dum1.get_phi() << std::endl;

  std::cout << "dum2 phi: " << dum2.get_phi() << std::endl;

  std::cout << "deltaphi between dum1 and dum2: "
	    << dum1.delta_phi( dum2 ) << std::endl;
  
}


void test_parser()
{

  /**
   * Test the parser class by printing out a dummy event which has 
   * a smaller number of particles
   */
  
  std::string filepath = "example_events/";
  std::string filename = "test_event_";
  Event_Parser parser;
  std::vector<Event> no_events = parser.get_events(filepath,filename);

  std::cout << "Default event parser constructor yields "
	    << no_events.size() << " events, which isn't very exciting"
	    << std::endl;

  parser.set_event_num(1);
  
  std::vector<Event> one_event = parser.get_events(filepath,filename);

  std::cout << "Event number 0 has " << one_event.size() << " event with "
	    << one_event.at(0).num_particles_in_event()
	    << " particles in the event"
	    << std::endl << std::endl;

  std::cout << std::setprecision(4)
	    << "The first particle in event number 0 has 4 vector: ("
	    << one_event.at(0).get_particles().at(0).get_px()
	    << ", " << one_event.at(0).get_particles().at(0).get_py()
	    << ", " << one_event.at(0).get_particles().at(0).get_pz()
	    << ", " << one_event.at(0).get_particles().at(0).get_energy()
	    << ")" << std::endl;

  int numparticles = one_event.at(0).num_particles_in_event();
  
  std::cout << std::setprecision(4)
	    << "The last particle in event number 0 has 4 vector: ("
	    << one_event.at(0).get_particles().at(numparticles-1).get_px()
	    << ", " << one_event.at(0).get_particles().at(numparticles-1).get_py()
	    << ", " << one_event.at(0).get_particles().at(numparticles-1).get_pz()
	    << ", " << one_event.at(0).get_particles().at(numparticles-1).get_energy()
	    << ")" << std::endl;



  /**
   * Now test the parser with multiple events, which is more realistic 
   * since one would like to analyze more than 1 event.
   */
  
  std::cout << std::endl << std::endl;
  std::cout << "Test Parser with multiple events" << std::endl;

  ///Test 2 events
  parser.set_event_num(2);

  std::vector<Event> several_events = parser.get_events(filepath,filename);

  std::cout << "For " << parser.get_event_num()
	    << " events, Event vector size is "
	    << several_events.size()
	    << std::endl << std::endl;

  for(int i = 0; i < several_events.size(); ++i)
    {
      int numpart = several_events.at(i).num_particles_in_event();
      std::cout << std::endl << "Number of particles in event "
		<< i << " is "
		<< numpart << std::endl;

      for(int j = 0; j < numpart; ++j)
	{

	  std::cout << std::setprecision(4)
		    << "The " << j << "th particle in event number "
		    << i << " has 4 vector: ("
		    << several_events.at(i).get_particles().at(j).get_px()
		    << ", " << several_events.at(i).get_particles().at(j).get_py()
		    << ", " << several_events.at(i).get_particles().at(j).get_pz()
		    << ", " << several_events.at(i).get_particles().at(j).get_energy()
		    << ")" << std::endl;

	}
    }
}

void test_pion()
{
  /**
   * Test the pion class with a dummy pion vector, which is a subclass of the Particle class
   */

  Pion dumpion(4,6,10);

  std::cout << "The pion has 3 momentum vector ("
	    << dumpion.get_px()<<","
	    << dumpion.get_py()<<","
	    << dumpion.get_pz()<<")"
	    << std::endl;

  std::cout << "Thus the pion has energy "
	    << dumpion.get_energy()
	    << " GeV/c with a fixed mass of "
	    << dumpion.get_mass()<<" GeV/c^2 "
	    << std::endl;
}
