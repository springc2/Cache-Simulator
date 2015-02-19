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
#include <math.h>

using namespace std;

string hexStringToBinaryString(string);
int binaryStringToDecimal(string binary);

int main(int argc, const char * argv[])
{
    int K;  // Num Lines per Set
    int N; //Num Sets
    string filename;
    bool isFIFO;
    for (int sim = 0; sim < 32; sim++)
    {
        switch (sim)
        {
            case 0:
                K = 2;
                N = 32;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 1:
                K = 4;
                N = 16;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 2:
                K = 8;
                N = 8;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 3:
                K = 16;
                N = 4;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 4:
                K = 2;
                N = 128;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 5:
                K = 4;
                N = 64;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 6:
                K = 8;
                N = 32;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 7:
                K = 16;
                N = 16;
                isFIFO = true;
                filename = "TRACE1.DAT";
                break;
            case 8:
                K = 2;
                N = 32;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 9:
                K = 4;
                N = 16;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 10:
                K = 8;
                N = 8;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 11:
                K = 16;
                N = 4;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 12:
                K = 2;
                N = 128;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 13:
                K = 4;
                N = 64;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 14:
                K = 8;
                N = 32;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 15:
                K = 16;
                N = 16;
                isFIFO = false;
                filename = "TRACE1.DAT";
                break;
            case 16:
                K = 2;
                N = 32;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 17:
                K = 4;
                N = 16;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 18:
                K = 8;
                N = 8;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 19:
                K = 16;
                N = 4;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 20:
                K = 2;
                N = 128;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 21:
                K = 4;
                N = 64;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 22:
                K = 8;
                N = 32;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 23:
                K = 16;
                N = 16;
                isFIFO = true;
                filename = "TRACE2.DAT";
                break;
            case 24:
                K = 2;
                N = 32;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 25:
                K = 4;
                N = 16;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 26:
                K = 8;
                N = 8;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 27:
                K = 16;
                N = 4;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 28:
                K = 2;
                N = 128;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 29:
                K = 4;
                N = 64;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 30:
                K = 8;
                N = 32;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            case 31:
                K = 16;
                N = 16;
                isFIFO = false;
                filename = "TRACE2.DAT";
                break;
            default:
                break;
        }
        int length;
        int hitCount = 0;
        int missCount = 0;
        
        ifstream inFile;
        inFile.open (filename , ifstream::binary);
        
        if(inFile.fail())
        {
            cerr << "Failed to read from file " << filename << endl;
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
                countMemRefs++;
            }
        }
        
        vector<string> binaryMemRefs(length/3);
        
        for (int i = 0; i < length/3; i++)
        {
            binaryMemRefs[i] = hexStringToBinaryString(memRefs[i]);
        }
        

        cout << "\n\nSimulation " << sim+1 << " with " << filename << endl;
        
        //creates array of Queues for each line of cache
        CacheSetQueue* cacheLines = new CacheSetQueue[K];
        for (int i = 0; i < K; i++)
        {
            cacheLines[i] = CacheSetQueue(N, isFIFO);
        }
        
        int numIndexBits = log2(K);  //calculate number of index bits
        for (int i = 0; i < length/3; i++)
        {
            int lineIndex = binaryStringToDecimal(binaryMemRefs[i].substr(20-numIndexBits, numIndexBits));  //extract index from address
            string tag = binaryMemRefs[i].substr(0, 20-numIndexBits);  //extract tag from address
            
            if(cacheLines[lineIndex].addToQueue(tag))
                hitCount++;
            else
                missCount++;
        }
    
        double missRate = (double)missCount/(double)(countMemRefs*10) * 100;  //divide misses by total number of memory references in original file
    
        if(isFIFO)
            cout << "Replacement Policy: FIFO" << endl;
        else
            cout << "Replacement Policy: LRU" << endl;
        cout << "Number of Sets: " << N << endl;
        cout << "Number of Lines per Set: " << K << endl;
        cout << "Miss rate: " << setprecision(4) << missRate << "%" << endl;

    }
    
    return 0;
}


string hexStringToBinaryString(string sHex)
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

int binaryStringToDecimal(string binary)
{
    int n = atoi(binary.c_str());
    int output = 0;
    
    int m = 1;
    
    for(int i=0; n > 0; i++) {
        
        if(n % 10 == 1) {
            output += m;
        }
        n /= 10;
        m <<= 1;
    }
    
    return output;
}







