//
//  main.cpp
//  Scheduling
//
//  Created by Caleb Voorhees on 11/12/21.
//

#include <iostream>
#include "Job.hpp"
#include <math.h>
using namespace std;

void weightedInterval(Job jobs[], int arrSize, int workers)
{
    // Sort jobs from smallest to largest by weight
    Job temp(0, 0, "empty");
    for (int i=0; i < arrSize; i++)
    {
        for (int j=0; j < arrSize-1; j++)
        {
            if (jobs[i].weight < jobs[j].weight)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    
    // Weighted interval schedule loop
    int i = 0;
    while (i < arrSize)
    {
        for (int j=0; j < workers; j++)
        {
            // Exit loop if iterator tries to go beyond the bounds of the array
            if (i > arrSize-1)
                break;
            
                // Assign workers to highest priority jobs first
                cout << "\nWorker " << j+1 << ": " << jobs[i].name << " = " << jobs[i].length << " hours (priority level " << jobs[i].weight << ")\n";
                i++;
        }
    }
    
    // If there are more workers than available jobs inform the user
    if (workers > arrSize)
    {
        cout << "\n"<< workers - arrSize << " extra workers remain.\n";
    }
}

void standardInterval(Job jobs[], int arrSize, int workers)
{
    // Sort jobs from smallest to largest by length
    Job temp(0, 0, "empty");
    for (int i=0; i < arrSize; i++)
    {
        for (int j=0; j < arrSize-1; j++)
        {
            if (jobs[i].length < jobs[j].length)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    
    // Standard interval schedule loop
    int i = 0;
    while (i < arrSize)
    {
        for (int j=0; j < workers; j++)
        {
            // Exit loop if iterator tries to go beyond the bounds of the array
            if (i > arrSize-1)
                break;
            
                // Assign workers to appropriate amount of jobs
                cout << "\nWorker " << j+1 << ": " << jobs[i].name << " = " << jobs[i].length << " hours\n";
                i++;
        }
    }
    
    // If there are more workers than available jobs inform the user
     if (workers > arrSize)
     {
         cout << "\n"<< workers - arrSize << " extra workers remain.\n";
     }
}

// Main Application
int main(int argc, const char * argv[]) {
    
    // Declare structure holding jobs
    Job jobs[] = {Job(8, 3, "task 1"), Job(3, 4, "task 2"), Job(6, 3, "task 3"), Job(10, 1, "task 4"), Job(2, 2, "task 5"), Job(6, 3, "task 6"), Job(8, 5, "task 7"), Job(5, 1, "task 8"), Job(9, 2, "task 9"), Job(2, 4, "task 10")};
    
    // Prompt for what kind of scheduling the user wants
    char scheduleType;
    cout << "Enter S for standard interval scheduling or W for weighted interval scheduling:\n";
    cin >> scheduleType;
    
    // Prompt user for amount of resources
    int workers = 0;
    cout << "Enter the amount of workers that are available:\n";
    cin >> workers;
    
    
    if (scheduleType == 'S')
    {
        // Run standard algorithm
        int arrSize = 10;
        standardInterval(jobs, arrSize, workers);
        }
    
    else if (scheduleType == 'W')
    {
        // Run weighted algorithm
        int arrSize = 10;
        weightedInterval(jobs, arrSize, workers);
    }
    
    return 0;
}
