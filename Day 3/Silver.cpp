/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 3 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 03/12/2025
   ~ ⏱ Writing time: 18 min 35 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");
    int result = 0;
    vector<vector<int>> batteriesList;

    while (getline (file, line)) {
        vector<int> batteries;
        int first = 0, second = 0;
        for(int i = 0; i < line.length(); i++)
        {
            int number = line[i] - '0';
            if(first == 0)
            {
                first = number;
            }
            else if(second != 0)
            {
                if(second > first)
                {
                    first = second;
                    second = number;
                }
                else if(number > second)
                    second = number;
            }
            else
                second = number;
        }
        //cout << first << second << endl;
        batteries.push_back(first);
        batteries.push_back(second);
        batteriesList.push_back(batteries);
    }

    for(int i = 0; i < batteriesList.size(); i++)
    {
        int largestJoltage = batteriesList[i][0] * 10 + batteriesList[i][1];
        result+=largestJoltage;
    }


    file.close();

    cout << "The answer is: " << result << endl;
}