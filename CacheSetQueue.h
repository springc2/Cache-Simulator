//
//  setQueue.h
//  
//
//  Created by Chris Springer on 2/17/15.
//
//

#ifndef ____setQueue__
#define ____setQueue__

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class CacheSetQueue
{
private:
    int numSets;
    queue<string> myQueue;
public:
    CacheSetQueue() {}
    CacheSetQueue(int nSets);
    void addToQueue(string);
    int getSize();
};

#endif /* defined(____setQueue__) */
