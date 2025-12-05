/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 5 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 05/12/2025
   ~ ⏱ Writing time: 18 min 8 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
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
   vector<long long> freshIDs;

   while (getline (file, line)) {
      if(line == "") break;
      vector<string> s = split(line, '-');
      freshIDs.push_back(stoll(s[0]));
      freshIDs.push_back(stoll(s[1]));
   }


   while (getline (file, line)) {
      if(line == "") break;
      long long id = stoll(line);
      for(int i = 0; i < freshIDs.size(); i+=2)
      {
         if(id < freshIDs[i]) continue;
         else
         {
            if(id > freshIDs[i+1]) continue;
            result++;
            break;
         }
      }
   }

   file.close();

   cout << "The answer is: " << result << endl;
}