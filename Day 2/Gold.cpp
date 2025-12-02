/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 2 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 02/12/2025
   ~ ⏱ Writing time: 6 min 52 sec
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

bool isInvalidID(long long num) {
    string s = to_string(num);
    int len = s.size();

    for (int i = 1; i <= len / 2; i++) {
        if (len % i) continue;
        string pattern = s.substr(0, i);
        bool valid = true;

        for (int j = i; j < len; j += i) {
            if (s.substr(j, i) != pattern) {
                valid = false;
                break;
            }
        }

        if (valid) return true;
    }
    return false;
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

        for (long long id = start; id <= end; id++) {
            if (isInvalidID(id)) {
                result += id;
            }
        }
    }
    file.close();

    cout << "The answer is: " << result << endl;
}