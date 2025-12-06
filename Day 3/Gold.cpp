/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 3 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 03/12/2025
   ~ ⏱ Writing time: 56 min 29 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
using namespace std;

string findMax(const string& s, int k)
{
    if(k == 0) return "";
    if(s.length() == k) return s;

    char max = s[0];
    int maxPos = 0;

    for(int i = 0; i <= s.length() - k; i++)
    {
        if(s[i] > max)
        {
            max = s[i];
            maxPos = i; 
        }
    }
    return max + findMax(s.substr(maxPos+1), k-1);
}

int main()
{
    string line;
    ifstream file("input.txt");
    long long result = 0;

    while (getline (file, line))
        result += stoll(findMax(line, 12));

    file.close();

    cout << "The answer is: " << result << endl;
}