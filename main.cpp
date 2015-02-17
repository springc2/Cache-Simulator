//
//  main.cpp
//  Cache Simulator
//
//  Created by Chris Springer on 2/12/15.
//  Copyright (c) 2015 Chris Springer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "CacheSetQueue.h"

using namespace std;

string GetBinaryStringFromHexString (string sHex)
{
    string sReturn = "";
    for (int i = 0; i < sHex.length (); ++i)
    {
        switch (sHex [i])
        {
            case '0': sReturn.append ("0000"); break;
            case '1': sReturn.append ("0001"); break;
            case '2': sReturn.append ("0010"); break;
            case '3': sReturn.append ("0011"); break;
            case '4': sReturn.append ("0100"); break;
            case '5': sReturn.append ("0101"); break;
            case '6': sReturn.append ("0110"); break;
            case '7': sReturn.append ("0111"); break;
            case '8': sReturn.append ("1000"); break;
            case '9': sReturn.append ("1001"); break;
            case 'a': sReturn.append ("1010"); break;
            case 'b': sReturn.append ("1011"); break;
            case 'c': sReturn.append ("1100"); break;
            case 'd': sReturn.append ("1101"); break;
            case 'e': sReturn.append ("1110"); break;
            case 'f': sReturn.append ("1111"); break;
        }
    }
    return sReturn;
}

int main(int argc, const char * argv[])
{
    int length;
    
    //for Sim 1 only, will have to perform all simulations
    int K = 2;  // Num Lines per Set
    int N = 32; //Num Sets
    int hitCount = 0;
    int missCount = 0;
    bool isFIFO = true;
    
    ifstream inFile;
    inFile.open ("TRACE1.DAT" , ifstream::binary);
    
    if(inFile.fail())
    {
        cerr << "Failed to read from file TRACE1.DAT" << endl;
    }
    
    inFile.seekg (0, ios::end);
    length = (int)inFile.tellg();
    inFile.seekg (0, ios::beg);
    
    char data[length];
    
    inFile.read(data, length);
    inFile.close();
    
    vector<string> memRefs(length/3);
    int countMemRefs = 0;
    for (int i = 0; i < length; i++)
    {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)(unsigned char)data[i];
        memRefs[i/3].insert(0,ss.str());
        
        if(i%3 == 2)
        {
          //  cout << memRefs[i/3] << endl;
            countMemRefs++;
        }
    }
    
    vector<string> binaryMemRefs(length/3);
    
    for (int i = 0; i < length/3; i++)
    {
        binaryMemRefs[i] = GetBinaryStringFromHexString(memRefs[i]);
    }
    
   /* for (int i = 0; i < length/3; i++)
    {
        cout << memRefs[i] << endl;
        cout << binaryMemRefs[i] << endl;
    }*/
    
    //less than 60,000?
    cout << "Num memrefs is " << countMemRefs << endl;
    
    //creates array of Queues for each line of cache
    CacheSetQueue* cacheLines = new CacheSetQueue[K];
    for (int i = 0; i < K; i++)
    {
        cacheLines[i] = CacheSetQueue(N, isFIFO);
    }
  
    cacheLines[1].addToQueue("1");
    cacheLines[1].addToQueue("2");
    cacheLines[1].addToQueue("3");
    cacheLines[1].addToQueue("4");
    cacheLines[1].addToQueue("5");
    cacheLines[1].addToQueue("6");
    cacheLines[1].addToQueue("4");
    cacheLines[1].addToQueue("7");
    
    
    
    for (int i = 0; i < N; i++)
    {
        cout << cacheLines[1].getTag(i) << endl;
    }
    
    
    
    return 0;
}






