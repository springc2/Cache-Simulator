//
//  CacheSetQueue.cpp
//  
//
//  Created by Chris Springer on 2/17/15.
//


#include "CacheSetQueue.h"

CacheSetQueue::CacheSetQueue(int nSets, bool bFIFO)
{
    numSets = nSets;
    isFIFO = bFIFO;
}

bool CacheSetQueue::addToQueue(string tag)
{
    if (isFIFO) //FIFO Policy
    {
        for (int i = 0; i < setQueue.size(); i++)
        {
            if (tag.compare(setQueue.at(i)) == 0)
            {
                //if tag exists in cache, queue does not change
                return true; //hit
            }
        }

    }
    else //LRU Policy
    {
        for (int i = 0; i < setQueue.size(); i++)
        {
            if (tag.compare(setQueue.at(i)) == 0)
            {
                //if tag exists in cache, move element to back of queue (most recenty used)
                setQueue.erase(setQueue.begin()+i);
                setQueue.push_back(tag);
                return true; //hit
            }
        }
    }
    
    setQueue.push_back(tag); //add new mem reference to cache (back of queue)
    if (setQueue.size() > numSets)
        setQueue.pop_front();  //if cache full, take out first-in mem reference
    return false; //miss

}

int CacheSetQueue::getSize()
{
    return setQueue.size();  //return num memory references in queue
}

string CacheSetQueue::getTag(int index)
{
    return setQueue.at(index);  //return tag of memory reference at given location
}