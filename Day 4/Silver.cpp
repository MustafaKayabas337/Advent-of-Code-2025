#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


int main()
{
   string line;
   ifstream file("input.txt");
   int result = 0;

   vector<vector<char>> stage;

   while (getline (file, line)) {
      vector<char> ln;
      for(char c : line)
      {
         ln.push_back(c);
      }
      stage.push_back(ln);
   }
   file.close();

   int lim_xl = 0;
   int lim_yl = 0;
   int lim_xm = stage[0].size();
   int lim_ym = stage.size();

   for(int i = 0; i < lim_ym; i++)
   {
      for(int j = 0; j < lim_xm; j++)
      {
         if(stage[i][j] == '@')
         {
            int rolls = 0;
            if(j - 1 >= 0 && stage[i][j-1] == '@') rolls++;
            if(j - 1 >= 0 && i - 1 >= 0 && stage[i-1][j-1] == '@') rolls++;
            if(i - 1 >= 0 && stage[i-1][j] == '@') rolls++;
            if(j + 1 < lim_xm && i - 1 >= 0 && stage[i-1][j+1] == '@') rolls++;
            if(j + 1 < lim_xm && stage[i][j+1] == '@') rolls++;
            if(j + 1 < lim_xm && i + 1 < lim_ym && stage[i+1][j+1] == '@') rolls++;
            if(i + 1 < lim_ym && stage[i+1][j] == '@') rolls++;
            if(j - 1 >= 0 && i + 1 < lim_ym && stage[i+1][j-1] == '@') rolls++;    
            if(rolls < 4)
               result++;
         }
      }
   }

   cout << "The answer is: " << result << endl;
}