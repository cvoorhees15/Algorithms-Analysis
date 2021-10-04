//
//  main.cpp
//  Algorithms Analysis Proj 1
//  Created by Caleb Voorhees on 8/30/21
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// weighted algorithm
void weightedInterval (int jobs[], int resources, int weights[])
{
    // selection sort data from smallest to largest by weight
    int temp,min;
    for (int i = 0; i < 8-1; i++){
        min = i;
        for (int j = i + 1; j < 8; j++){
            if (weights[j] < weights[min])
            {
            min = j;
            temp = jobs[min];
            jobs[min] = jobs[i];
            jobs[i] = temp;
            }
        }
    }
    
    // declare variables and arrays
    int cols = 8/resources;
    double columns = 8/resources;
    int rows = resources;
    int workers [resources];
    int jobsPerWorker [resources] [cols];
    
    // if more workers than jobs assign each job to a worker and send the rest home
    if(resources >= 8)
    {
        for (int i=0; i<8; i++)
        {
            workers[i] = jobs[i];
            cout << "Worker " << i+1 << " works for " << workers[i] << " hours\n\n";
        }
        cout << "Extra workers have no jobs today and can go home!";
    }
    
   // if more jobs than workers assign each worker the highest priority job first
   if (resources < 8)
   {
       for (int i = 0; i < rows; i++){
           for (int j = 0; j < columns; j++){
           // distribute jobs to each worker
               jobsPerWorker[i][j] = jobs[(j*resources)+i];
           }
       }
       
       for (int i = 0; i < rows; i++){
           for (int j = 0; j < columns; j++){
            // print out what jobs the workers have
             cout <<"worker " << i+1 << " has a " << jobsPerWorker[i][j] << " hour job\n";
               
           }
           cout << endl;
       }
    }
}

// standard algorithm
void standardInterval (int jobs[], int resources)
{
    // Bubble sort job lengths lowest to highest
    int temp;
    for (int i = 0; i < 8; i++){
        for (int j = i + 1; j < 8; j++){
            if (jobs[i] > jobs[j])
            {
            temp = jobs[i];
            jobs[i] = jobs[j];
            jobs[j] = temp;
            }
            
            
        }
    }
    // declare variables and arrays
    int cols = 8/resources;
    double columns = ceil(8/resources);
    int rows = resources;
    int workers [resources];
    int jobsPerWorker [resources] [cols];
    
    // if more workers than jobs assign each job to a worker and send the rest home
    if(resources >= 8)
    {
        for (int i=0; i<8; i++)
        {
            workers[i] = jobs[i];
            cout << "Worker " << i+1 << " works for " << workers[i] << " hours\n\n";
        }
        cout << "Extra workers have no jobs today and can go home!";
    }

   // if more jobs than workers assign each worker the appropriate amount of jobs
   if (resources < 8)
   {
       for (int i = 0; i < rows; i++){
           for (int j = 0; j < cols; j++){
           // distribute jobs to each worker
               jobsPerWorker[i][j] = jobs[(j*resources)+i];
           }
       }
       
       for (int i = 0; i < rows; i++){
           for (int j = 0; j < columns; j++){
            // print out what jobs the workers have
             cout <<"worker " << i+1 << " has a " << jobsPerWorker[i][j] << " hour job\n";
               
           }
           cout << endl;
       }
   }
}
// Main application
int main(int argc, const char * argv[]) {
    // declare arrays to store data
    int allJobs[8] = {7,11,8,5,3,9,6,1};
    int allWeights[8] = {1,2,1,3,4,3,2,4};
    
    // declare variables for user input
    char schedType;
    int workers;
    
    // identify what type of schedule is being organized
    cout << "\n\nEnter S for a standard interval schedule: \n\nEnter W for a weighted interval schedule:\n\n";
    cin >> schedType;
    
    // identify resources available
    cout << "Enter the amount of workers that are available:";
    cin >> workers;
    
    if (schedType == 'S')
    standardInterval(allJobs, workers);
    
    if (schedType == 'W')
    {
    weightedInterval(allJobs, workers, allWeights);
    }
    
    return 0;
    
}




