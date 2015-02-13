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

using namespace std;

int main(int argc, const char * argv[]) {
    int length;
    
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
    
    string *memRefs = new string[length/3];
    int countMemRefs = 0;
    for (int i = 0; i < length; i++)
    {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)(unsigned char)data[i];
        memRefs[i/3].insert(0,ss.str());
        
        if(i%3 == 2)
        {
            cout << memRefs[i/3] << endl;
            countMemRefs++;
        }
    }
    
    //less than 60,000?
    cout << "Num memrefs is " << countMemRefs << endl;
    
    delete [] memRefs;
    
    return 0;
}

