#include <vector>
#include <chrono>
#include <iostream>
#include "RelayRunner.h"

int main()
{
    // create running track and runners (1 for each track section)
    const int numTrackSections = 10;

    RelayRunner copyRunners[numTrackSections] = {new Baton(), nullptr}; // init array with first element as baton instance 
    //RelayRunner moveRunners[numTrackSections] = {new Baton(), nullptr}; // ... and move semantics

    // start race by looping over all track sections
    long totalTimeCopy{0}, totalTimeMove{0};
    for (size_t i = 0; i < numTrackSections - 1; i++)
    {
        // pass baton to next runner
        auto t1 = std::chrono::high_resolution_clock::now();

        copyRunners[i + 1] = copyRunners[i]; // copy assignment
        
        auto t2 = std::chrono::high_resolution_clock::now();
        
        //moveRunners[i + 1] = std::move(moveRunners[i]); // move assignment
        
        auto t3 = std::chrono::high_resolution_clock::now();

        // accumulate lap times
        auto timeCopy = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        auto timeMove = std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count();
        totalTimeCopy += timeCopy; 
        totalTimeMove += timeMove; 
    }

    // award ceremony
    std::cout << std::endl << std::endl;
    std::cout << "AND THE WINNER IS " << (totalTimeMove<totalTimeCopy ? "MoveRunner" : "CopyRunner") << std::endl;
    std::cout << "MoveRunner = " << totalTimeMove << "ns, CopyRunner = " << totalTimeCopy << "ns \n"; 
    std::cout << std::endl << std::endl;

    return 0;
}