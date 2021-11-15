//
//  Job.hpp
//  Scheduling
//
//  Created by Caleb Voorhees on 11/12/21.
//

#ifndef Job_hpp
#define Job_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Job
{
public:
    string name;
    int length, weight;
    Job(int length, int weight, string name);
    
};


#endif /* Job_hpp */
