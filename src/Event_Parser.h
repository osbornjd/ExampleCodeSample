#ifndef EVENT_PARSER_H_
#define EVENT_PARSER_H_

#include <string> 
#include <vector>
#include "Event.h"
#include "Particle.h"


class Event_Parser {

 public:

  /**
   * Constructors
   */
  Event_Parser();
  Event_Parser(int nevents);

  /**
   * Destructor
   */
  virtual ~Event_Parser();

  /**
   * Main workhorse function in this class which obtains the events to analyze
   */
  std::vector<Event> get_events(std::string filepath,
				std::string filename);

  /**
   * Getter and setter functions to get/set the number of events to analyze
   */
  void set_event_num(int nevents);
  int get_event_num();
  
 private:
  ///The number of events one would like to analyze
  int _nevents;
  


};

#endif /* EVENT_PARSER_H */
