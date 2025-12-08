/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 7 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 07/12/2025
   ~ ⏱ Writing time: 22 min 30 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
   string line;
   ifstream file("input.txt");
   int result = 0;
   vector<string> stage;
   while (getline (file, line)) {
      stage.push_back(line);
   }

   int lineLength = stage[0].length();
   int stageSize = stage.size();

   for(int i = 0; i < stageSize - 1; i++)
   {
      for(int j = 0; j < lineLength; j++)
      {
         if(stage[i][j] == 'S' || (stage[i][j] == '|' && stage[i+1][j] != '^')) stage[i+1][j] = '|';
         else if(stage[i+1][j] == '^' && stage[i][j] == '|')
         {
            if(j - 1 >= 0) stage[i+1][j-1] = '|';
            if(j + 1 < stageSize) stage[i+1][j+1] = '|';
            result++;
         }
      }
   }

   file.close();

   cout << "The answer is: " << result << endl;
}