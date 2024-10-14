#include "saveontrigger.h"
#include <iostream>
#include <fstream>

int sample_counter = 0;

void saveOnTrigger(const DSOsamples *result){
	std::ofstream Output("savedontrigger/sample" + std::to_string(sample_counter) + ".csv");
	for(int i=0; i < SAMPLESIZE; i+=2){
		double sample = result->data.at(0).at(i);
		Output << i / result->samplerate << ", " << sample << std::endl;
	}
	Output.close();
	sample_counter++;
}
