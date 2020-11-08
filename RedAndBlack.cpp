#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "RedAndBlack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string inputFile;
    for (int i = 0; i < argc - i; i++)
    {

        if (argc == 1)
        {
            help();
        }
        else
        {
            if (string(argv[i]) == "-i")
            {
                inputFile = argv[i + 1];
                redAndBlack(inputFile);
            }
        }
    }
    return 0;
}
