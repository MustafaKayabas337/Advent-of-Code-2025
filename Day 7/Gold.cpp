/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 7 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 07/12/2025
   ~ ⏱ Writing time: 1 hr 1 min 8 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
   string line;
   ifstream file("input.txt");
   long long result = 0;
   vector<string> stage;
   vector<vector<long long>> valsList;
   while (getline (file, line)) {
      stage.push_back(line);
      valsList.push_back(vector<long long>(line.length(), 0));
   }
   
   int lineLength = stage[0].length();
   int stageSize = stage.size();

   for(int i = 0; i < stageSize - 1; i++)
   {
      for(int j = 0; j < lineLength; j++)
      {
         char c = stage[i][j];
         long long val = valsList[i][j];
         if(c == 'S')
         {
            stage[i+1][j] = '|';
            valsList[i+1][j] = 1;
         }
         else if(stage[i][j] == '|' && stage[i+1][j] != '^')
         {
            stage[i+1][j] = '|';
            valsList[i+1][j] += val;
         }
         else if(stage[i+1][j] == '^' && stage[i][j] == '|')
         {
            if(j - 1 >= 0)
            {
               stage[i+1][j-1] = '|';
               valsList[i+1][j-1] += val;
            }
            if(j + 1 < stageSize)
            {
               stage[i+1][j+1] = '|';
               valsList[i+1][j+1] += val;
            }
         }
      }
   }

   for(auto x : valsList[stageSize-1])
   {
      result += x;
   }
   file.close();

   cout << "The answer is: " << result << endl;
}