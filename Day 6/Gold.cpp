/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 6 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 06/12/2025
   ~ ⏱ Writing time: 1 hr 44 min 16 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
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

   vector<string> lines;
   while (getline (file, line)) {
      lines.push_back(line);
   }
   file.close();

   string symbolLine = lines[lines.size()-1];
   lines.erase(lines.begin() + lines.size()-1);

   vector<int> sizes;
   vector<char> symbols;
   int size = 0;
   for(int i = 0; i < symbolLine.length(); i++)
   {
      if(i == symbolLine.length() - 1)
         sizes.push_back(++size);
      else if(symbolLine[i] == '*' || symbolLine[i] == '+' )
      {         
         symbols.push_back(symbolLine[i]);
         if(size == 0)
         {
            size = 1;
            continue;
         }
         sizes.push_back(--size);
         size = 1;
      }
      else size++;
   }

   int pos = 0;
   for(int i = 0; i < symbols.size(); i++)
   {
      long long sum;
      if(symbols[i] == '*') sum = 1;
      else sum = 0;
      for(int j = 0; j < sizes[i]; j++)
      {
         string num = "";
         for(int k = 0; k < lines.size(); k++)
         {
            char c = lines[k][pos];
            if(c == ' ') continue;
            num += c;
         }
         if(symbols[i] == '*') sum*=stoi(num);
         else sum+=stoi(num);
         pos++;
      }
      pos++;
      result += sum;
   }

   cout << "The answer is: " << result << endl;
}