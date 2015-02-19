//
//  CacheSetQueue.h
//  
//
//  Created by Chris Springer on 2/17/15.
//

#ifndef ____CacheSetQueue__
#define ____CacheSetQueue__

#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class CacheSetQueue
{
private:
    int numSets;
    bool isFIFO;
    deque<string> setQueue;
    
public:
    CacheSetQueue() {}
    CacheSetQueue(int nSets, bool bFIFO);
    bool addToQueue(string);
    int getSize();
    
};

#endif /* defined(____CacheSetQueue__) */
