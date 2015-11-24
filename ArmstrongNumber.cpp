#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    // the length of the number
    unsigned int length=0;
    
    // the text file containing possible armstrong numbers
    ifstream armFile(argv[1]);
    
    // a possible armstrong number
    string value;

    if(armFile.is_open())
    {
        // a digit from the possible armstrong value
        unsigned int digit;
        unsigned int sum = 0;
        unsigned int index = 0;

        while(getline(armFile,value))
        {
            length = value.length();

            while(index < length)
            {
                digit = value[index] - '0';

                sum = sum + pow(digit,length);

                ++index;
            }

            if(atoi(value.c_str()) == sum)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }

            // make sure to reset
            index = 0;
            sum = 0;
        }
    }

    armFile.close();

    return 0;
}
