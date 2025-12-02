/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 2 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 02/12/2025
   ~ ⏱ Writing time: 55 min 24 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

vector<string> split(const string& s, char delimiter)                                                                                                                          
{                                                                                                                                                                                             
   vector<string> splits;                                                                                                                                                           
   string split;                                                                                                                                                                         
   istringstream ss(s);                                                                                                                                                                  
   while (getline(ss, split, delimiter))                                                                                                                                                 
   {                                                                                                                                                                                          
      splits.push_back(split);                                                                                                                                                                
   }                                                                                                                                                                                          
   return splits;                                                                                                                                                                             
}

int main()
{
    string line;
    ifstream file("input.txt");
    long long result = 0;

    vector<string> idRangesList;
    while (getline (file, line)) {
        idRangesList = split(line, ',');
    }
    for(int i = 0; i < idRangesList.size(); i++)
    {
        vector<string> idRange = split(idRangesList[i], '-');
        long long start = stoll(idRange[0]);
        long long end = stoll(idRange[1]);
        int startLen = idRange[0].length();

        long long newStart = stoll("1" + string(startLen, '0'));
        if (startLen % 2)
        {
            start = newStart;
            startLen++;
        }

        long long iteration = stoll(to_string(start).substr(0, startLen/2));
        while(true)
        {
            string halfNumber = to_string(iteration);
            long long mirroredNumber = stoll(halfNumber + halfNumber);
            iteration++;
            if(mirroredNumber <= end)
            {   
                if(mirroredNumber < start) continue;
                result += mirroredNumber;
            }
            else
                break;
        }
    }
    file.close();

    cout << "The answer is: " << result << endl;
}