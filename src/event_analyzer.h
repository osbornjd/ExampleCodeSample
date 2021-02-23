#include "Event.h"
#include "Particle.h"
#include "Pion.h"
#include "Kaon.h"
#include "Event_Parser.h"
#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>

/**
 * User defined values 
 * num_events is the number of events to analyze
 * pseudorapidity_cut is the range in pseudorapidity (or polar angle) one wants to analyze
 */
const static int num_events = 8;
const static float pseudorapidity_cut = 2.;

/**
 * Default pion/kaon masses as known from measurements
 */
const static float PION_MASS = 0.135;
const static float KAON_MASS = 0.494;

/**
 * File path and file name where events exist in txt files
 */
std::string filepath = "example_events/";
std::string filename = "event_number_";


/**
 * Workhorse function which calculates distances in phi-pseudorapidity space between particles
 */
void calculate_distances(std::vector<Event> events,
			 float &pipi,
			 float &kk);
