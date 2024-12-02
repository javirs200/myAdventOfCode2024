#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <map>

using namespace std;

// Merge short algorithm from https://www.geeksforgeeks.org/merge-sort/
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{

    // start a timer
    clock_t start;
    start = clock();

    //store each colum in a vector
    vector<int> a;
    vector<int> b;

    // read the input file
    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line)) // O(n)
        {
            int num1, num2;
            sscanf(line.c_str(), "%d %d", &num1, &num2);
            a.push_back(num1);
            b.push_back(num2);
        }
    }
    // close the file
    inputFile.close();

    // get the length of the vectors
    int len = a.size();

    // sort the vectors
    mergeSort(a, 0, len - 1); // O(n log n)
    mergeSort(b, 0, len - 1);  // O(n log n)

    int simularity1 = 0;
    // part one
    for(int i = 0; i < len; i++) // O(n)
    {
        simularity1 += abs(a[i] - b[i]);
    }

    //part two
    int simularity2 = 0;
    
    // create a map to store the frequency of each element
    map<int, int> freq;

    // store the frequency of each element
    for(int i = 0; i < len; i++) // O(n)
    {
        freq[b[i]]++;
    }

    // calculate the simularity sumatory of each element of a apearing in b
    for(int i = 0; i < len; i++) // O(n)
    {
        simularity2 += abs(a[i] * freq[a[i]]);   
    }

    // stop the timer
    cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms for N:" << len << " iterations"  << endl;

    // print the result
    cout << "Part 1: " << simularity1 << endl;
    cout << "Part 2: " << simularity2 << endl;

    return 0;
}