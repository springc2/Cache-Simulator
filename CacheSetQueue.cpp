//
//  setQueue.cpp
//  
//
//  Created by Chris Springer on 2/17/15.
//
//

#include "CacheSetQueue.h"

CacheSetQueue::CacheSetQueue(int nSets)
{
    numSets = nSets;
}

void CacheSetQueue::addToQueue(string memRef)
{
    //TODO: check if mem ref exists before pushing
    
    myQueue.push(memRef);
    if (myQueue.size() > numSets)
        myQueue.pop(); 
}

int CacheSetQueue::getSize()
{
    return myQueue.size();
}