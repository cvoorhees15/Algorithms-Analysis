//
//  Job.cpp
//  Scheduling
//
//  Created by Caleb Voorhees on 11/12/21.
//

#include "Job.hpp"
using namespace std;

Job::Job(int length, int weight, string name)
{
    this->length = length;
    this->weight = weight;
    this->name = name;
}

