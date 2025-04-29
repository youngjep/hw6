#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;


struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        unsigned long long w[] = {0,0,0,0,0};

        unsigned int index = k.size();

        for (unsigned int i = 0; i < 5; i++) 
        {
            if (index >= 0)
            {
                int len = 6;
                if (index < 6) 
                {
                    len = index;
                    index = 0;
                } 
                else 
                {
                    index = index - len;
                }

                std::string temp = k.substr(index, len);

                unsigned long long value = 0;

                for (unsigned int j = 0; j < len; j++) 
                {
                    value = (value * 36) + letterDigitToNumber(temp[j]);
                    //std::cout << temp[j] << " is " << letterDigitToNumber(temp[j]) << std::endl;
                }

                w[4 - i] = value;
            }
        }

        /*for (int i = 0; i < 5; i++) 
        {
            std::cout << "w[" << i << "] = " << w[i] << std::endl;
        }*/

        HASH_INDEX_T result = rValues[0] * w[0] + rValues[1] * w[1] + rValues[2] * w[2] + rValues[3] * w[3] + rValues[4] * w[4];
        return result;
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        letter = tolower(letter);
        // Add code here or delete this helper function if you do not want it
        if (letter >= 'a') 
        {
            return letter - 'a';
        }
        else 
        {
            return letter - '0' + 26;
        }
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
