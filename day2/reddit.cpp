#include <bits/stdc++.h>

using namespace std;

bool issafe(vector<int> a)
{

    int n = a.size();

    if (n < 2)
        return true;

    int check = 0;

    for (int i = 1; i < n; i++)
    {

        int diff = a[i] - a[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3)
            return false;

        if (diff == 0)
            return false;

        if (check == 0)
            check = diff > 0 ? 1 : -1;

        else if (check * diff <= 0)
            return false;
    }

    return true;
}

int main()
{
    // read the input file
    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        string line;

        int res = 0;

        while (getline(inputFile, line))
        {

            stringstream ss(line);

            vector<int> levels;

            int num;

            while (ss >> num)
                levels.push_back(num);

            if (issafe(levels))
            {

                res++;

                continue;
            }

            bool safe = false;

            for (int i = 0; i < levels.size(); i++)
            {

                vector<int> temp = levels;

                temp.erase(temp.begin() + i);

                if (issafe(temp))
                {

                    safe = true;

                    break;
                }
            }

            if (safe)
                res++;
        }

        cout << res << endl;
    }
    // close the file
    inputFile.close();

    return 0;
}