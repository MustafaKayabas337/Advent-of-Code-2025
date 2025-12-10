/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 9 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 09/12/2025
   ~ ⏱ Writing time: 8 min 31 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

struct RedTile
{
   int x, y;
};

long long findArea(RedTile a, RedTile b)
{
   long long x = abs(a.x - b.x) + 1;
   long long y = abs(a.y - b.y) + 1;

   return x*y;
}

int main()
{
   system("cls");
   
   string line;
   ifstream file("input.txt");
   long long result = 0;

   vector<RedTile> redTiles;
   int id = 0;
   while(getline (file, line)) {
      RedTile redTile;
      sscanf(line.c_str(), "%d,%d", &redTile.x, &redTile.y);
      redTiles.push_back(redTile);
   }
   file.close();
   vector<long long> areas;
   for(int i = 0; i < redTiles.size(); i++)
   {
      for(int j = i + 1; j < redTiles.size(); j++)
      {
         long long area = findArea(redTiles[i], redTiles[j]);
         areas.push_back(area);
      }
   }

   sort(areas.begin(), areas.end(), greater<long long>());

   result = areas[0];

   cout << "The answer is: " << result << endl;
}