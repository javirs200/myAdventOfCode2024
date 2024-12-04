#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

vector<vector<char>> storeInput(string fileName)
{
    vector<vector<char>> matrix;
    // read the input file onto a matrix
    ifstream inputFile(fileName);
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            vector<char> row;
            for (int i = 0; i < line.size(); i++)
            {
                row.push_back(line[i]);
            }
            matrix.push_back(row);
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    // close the file
    inputFile.close();
    return matrix;
}

void part1(vector<vector<char>> matrix)
{   
    int xmasCount = 0 ;
    int N = matrix.size();
    int M = matrix[0].size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
           if (matrix[i][j] == 'X') {
                // horizontal reverse
                xmasCount += j > 2 && matrix[i][j-1] == 'M' && matrix[i][j-2] == 'A' && matrix[i][j-3] == 'S';
                // horixontal forward
                xmasCount += j < N-3 && matrix[i][j+1] == 'M' && matrix[i][j+2] == 'A' && matrix[i][j+3] == 'S';
                // vertical reverse
                xmasCount += i > 2 && matrix[i-1][j] == 'M' && matrix[i-2][j] == 'A' && matrix[i-3][j] == 'S';
                // vertical forward
                xmasCount += i > 2 && j > 2   && matrix[i-1][j-1] == 'M' && matrix[i-2][j-2] == 'A' && matrix[i-3][j-3] == 'S';
                // diagonal 1
                xmasCount += i > 2 && j < N-3 && matrix[i-1][j+1] == 'M' && matrix[i-2][j+2] == 'A' && matrix[i-3][j+3] == 'S';
                // diagonal 2
                xmasCount += i < N-3 && matrix[i+1][j] == 'M' && matrix[i+2][j] == 'A' && matrix[i+3][j] == 'S';
                // diagonal 3
                xmasCount += i < N-3 && j > 2   && matrix[i+1][j-1] == 'M' && matrix[i+2][j-2] == 'A' && matrix[i+3][j-3] == 'S';
                // diagonal 4
                xmasCount += i < N-3 && j < N-3 && matrix[i+1][j+1] == 'M' && matrix[i+2][j+2] == 'A' && matrix[i+3][j+3] == 'S';
            }
        }
    }
    cout << "Part 1: " << xmasCount << endl;
}

void part2(vector<vector<char>> matrix)
{
    int xmasCount = 0 ;
    int N = matrix.size();
    int M = matrix[0].size();
    for (int i = 1; i < N - 1; ++i){
        for (int j = 1; j < N - 1; ++j){
            if (matrix[i][j] == 'A') {
                xmasCount += matrix[i-1][j-1] == 'M' && matrix[i-1][j+1] == 'M' && matrix[i+1][j-1] == 'S' && matrix[i+1][j+1] == 'S';
                xmasCount += matrix[i-1][j-1] == 'M' && matrix[i-1][j+1] == 'S' && matrix[i+1][j-1] == 'M' && matrix[i+1][j+1] == 'S';
                xmasCount += matrix[i-1][j-1] == 'S' && matrix[i-1][j+1] == 'M' && matrix[i+1][j-1] == 'S' && matrix[i+1][j+1] == 'M';
                xmasCount += matrix[i-1][j-1] == 'S' && matrix[i-1][j+1] == 'S' && matrix[i+1][j-1] == 'M' && matrix[i+1][j+1] == 'M';
            }
        }
    }
        
    cout << "Part 2: " << xmasCount << endl;
}

int main()
{
     // start a timer
    clock_t start;
    start = clock();

    vector<vector<char>> matrix;

    string fileName = "input.txt";
    matrix = storeInput(fileName);

    part1(matrix);
    part2(matrix);
    
    // stop the timer
    cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms " << endl;
    return 0;
}