/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 5 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 05/12/2025
   ~ ⏱ Writing time: 1 hr 0 min 32 sec
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
   file.close();

   while(true)
   {
      vector<long long> nonOverlappingIDs;
      nonOverlappingIDs.push_back(freshIDs[0]);
      nonOverlappingIDs.push_back(freshIDs[1]);


      for(int i = 2; i < freshIDs.size(); i+=2)
      {
         long long start = freshIDs[i];
         long long end = freshIDs[i+1];
         bool nonOverlap = true;
         for(int j = 0; j < nonOverlappingIDs.size(); j+=2)
         {
            long long nonOverlapStart = nonOverlappingIDs[j];
            long long nonOverlapEnd = nonOverlappingIDs[j+1];
            if(!(start > nonOverlapEnd || end < nonOverlapStart))
            {
               nonOverlap = false;
               if(start < nonOverlapStart) nonOverlappingIDs[j] = start;
               if(end > nonOverlapEnd) nonOverlappingIDs[j+1] = end;
               break;
            }
         }

         if(nonOverlap)
         {
            nonOverlappingIDs.push_back(start);
            nonOverlappingIDs.push_back(end);
         }
      }
      
      if(freshIDs == nonOverlappingIDs)
      {
         for(int i = 0; i < freshIDs.size(); i+=2)
         {
            result += freshIDs[i+1] - freshIDs[i] + 1;
         }
         break;
      }
      freshIDs = nonOverlappingIDs;

   }
   

   cout << "The answer is: " << result << endl;
}