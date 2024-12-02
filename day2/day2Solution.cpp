#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;


void isSafe(string record,int &safeCount)
{

    // split the record unknowk number of int separated by a space
    vector<int> levels;
    stringstream ss(record);
    int num;

    bool isSafe = true;
    bool ascending = true;
    bool descending = true;

    while (ss >> num)
    {
        levels.push_back(num);

        if (levels.size() > 1)
        {
            int prev = levels[levels.size() - 1];
            int actual = levels[levels.size() - 2];
            int change = abs(prev - actual);
            if (change > 3 || change == 0)
            {
                isSafe = false;

                break;
            }
            else
            {
                if (prev < actual)
                {
                    ascending = false;
                }
                if (prev > actual)
                {
                    descending = false;
                }
                isSafe = ascending || descending;
            }
        }
    }

    if (isSafe)
    {
        safeCount++;
    }

    // print the record not necesary
    // for (int i = 0; i < levels.size(); i++)
    // {
    //     cout << levels[i] << " ";
    // }
    // cout << "is safe:"<< isSafe << endl;
    // cout << "numbrer os fafe records: " << safeCount << endl;
}

void part1()
{
    int safeCount = 0;

    // read the input file
    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line)) // O(n)
        {
            isSafe(line,safeCount);
        }
        cout << "numbrer os fafe records: " << safeCount << endl;
    }
    // close the file
    inputFile.close();
};

int main()
{
    // start a timer
    clock_t start;
    start = clock();

    part1();

    // stop the timer
    cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms " << endl;
    return 0;
}