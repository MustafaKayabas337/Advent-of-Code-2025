/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 6 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 06/12/2025
   ~ ⏱ Writing time: 24 min 17 sec
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
   system("cls");
   
   string line;
   ifstream file("input.txt");
   long long result = 0;

   vector<vector<int>> numberRows;
   vector<char> symbols;
   while (getline (file, line)) {
      vector<int> numberRow;
      vector<string> s = split(line, ' ');
      for(auto x : s)
      {
         if(x == "") continue;
         if(x == "*" || x == "+") symbols.push_back(x[0]);
         else numberRow.push_back(stoi(x));
      }
      if(numberRow.size() > 0) numberRows.push_back(numberRow);
   }

   int width = numberRows[0].size();

   for(int i = 0; i < width; i++)
   {
      char symbol = symbols[i];
      long long sum = 0;
      long long mult = 1;
      for(int j = 0; j < numberRows.size(); j++)
      {
         if(symbol == '*')
            mult *= numberRows[j][i];
         else
            sum += numberRows[j][i];
      }

      if(mult != 1)
         result += mult;
      result += sum;
   }
   
   file.close();

   cout << "The answer is: " << result << endl;
}