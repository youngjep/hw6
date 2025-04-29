#include "hash.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{

    //MyStringHash h2(true);
    //h2("104");
    //cout << "message is " <<  h2.letterDigitToNumber('9') << endl;
    //g++ -g -Wall -std=c++11 str-hash-test.cpp -o test
    //return 0;

    if(argc < 2){
        cout << "Please provide a string to hash" << endl;
        return 1;
    }

    // use debug r values so we get repeated results
    MyStringHash h1(true);

    // key to hash
    string k(argv[1]);
    size_t hk = h1(k);
    // Test the hash
    cout << "h(" << k << ")=" << hk << endl;
    return 0;
}

/*
    MyStringHash h2(true);
    cout << "message is " <<  h2.letterDigitToNumber('9') << endl;
    //g++ -g -Wall -std=c++11 str-hash-test.cpp -o test
    return 0;
*/