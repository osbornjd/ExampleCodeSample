


# Proton-Proton Event and Particle C++ Example
  
This is a basic code sample that I wrote to demonstrate writing simple classes with some basic inheritance.

The code computes the distance in pseudorapidity-azimuthal space between charged pion-pion pairs and charged kaon-kaon pairs in some basic proton-proton collisions. The proton-proton events were generated using the [PYTHIA event generator](http://home.thep.lu.se/Pythia/). The intent is just to show a simple analysis that one might actually be interested in doing with simulated proton-proton collision events. It could be scaled to something more complex if desired.

The sample uses some text files whcih actually contain the final-state particle information as simulated by PYTHIA. This is not realistic and definitely would not scale, as one would need many text files with many numbers in them which is unquestionably **not** a good way to handle data. However, for the purposes of a basic code sample, it suffices to demonstrate some basic input and output. One could, for example, use the [ROOT](https://root.cern.ch/) data analysis framework to handle the input/output; however, that requires additional building and is not practical for the sake of an example.

Questions regarding the code can be directed to the author, Joe Osborn, at <jdosbo@umich.edu>. The code is free to be used by others if desired, with appropriate reference.



## Build Instructions

There are some more detailed comments in the individual files, but some basic instructions can also be found here. To build the code, simply use the makefile provided by typing, at the bash shell,
```
make
```
There should be no required third party libraries, since the example PYTHIA events are included in the directory `example_events`. If one wanted to generate their own proton-proton simulations, one could follow the instructions at the PYTHIA website above to install their own version.

### Test

A simple test program can also be compiled by invoking 
```
make test
```
### Cleaning
Libraries can be cleaned up by typing
```
make clean
```
## Running the program

The various builds (`make` or `make test`) produce two exectuables, which can be run by typing (again at the shell prompt)
```
./test
./event_analyzer
```
Running either will run the main program (`event_analyzer`) or the simple testing program (`test`) which prints some basic information and tests with the classes.