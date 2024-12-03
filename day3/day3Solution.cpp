#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <regex>

using namespace std;

void part1(){

    // pattern to read "mul(X,Y)"  where X and Y are integers of 1-3 digits
    string pattern = "mul\\([0-9]{1,3},[0-9]{1,3}\\)";

    // result sumatory
    int result = 0;

    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        stringstream buffer;
        buffer << inputFile.rdbuf();
        string content = buffer.str();

        regex re(pattern);
        smatch match;

        auto begin = content.cbegin();
        auto end = content.cend();

        while (regex_search(begin, end, match, re)) {
            string str = match.str();
            int commaIndex = match.str().find(",");
            int num1 = stoi(str.substr(4,commaIndex- 4));
            int num2 = stoi(str.substr(commaIndex + 1, str.size() - commaIndex - 2));
            result += num1 * num2;
            // cout << match.str() << num1 * num2 << endl;
            begin = match.suffix().first;
        }
        // print the result
        cout << "Result: " << result << endl;
    }
    // close the file
    inputFile.close();

}

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