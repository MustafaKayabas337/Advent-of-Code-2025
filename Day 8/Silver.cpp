/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 8 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 08/12/2025
   ~ ⏱ Writing time: 2 hr 32 min 58 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct UnionFind {
   vector<int> parent;
   vector<int> size;

   UnionFind(int n) 
   {
      parent.resize(n);
      size.resize(n, 1);

      for (int i = 0; i < n; i++) 
         parent[i] = i;
   }

   int find(int x) 
   {
      if (parent[x] == x) return x;
      return parent[x] = find(parent[x]);
   }

   void unite(int x, int y) 
   {
      int rootX = find(x);
      int rootY = find(y);
      if (rootX == rootY) return;

      if (size[rootX] < size[rootY]) swap(rootX, rootY);
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
   }

   int getSize(int x) 
   {
      int root = find(x);
      return size[root];
   }
};

struct JunctionBox
{
   int x,y,z;
   int id;
};

struct Connection
{
   int id1, id2;
   long long distance;
};

long long findDistance(JunctionBox a, JunctionBox b)
{
   long long dx = a.x - b.x;
   long long dy = a.y - b.y;
   long long dz = a.z - b.z;

   return dx*dx + dy*dy + dz*dz;
}

int main()
{
   system("cls");

   string line;
   ifstream file("input.txt");
   int attempts = 1000; //10 for test, 1000 for input
   long long result = 1;

   vector<JunctionBox> junctionBoxes;
   int id = 0;
   while (getline (file, line)) {
      JunctionBox junctionBox;
      sscanf(line.c_str(), "%d,%d,%d", &junctionBox.x, &junctionBox.y, &junctionBox.z);
      junctionBox.id = id++;
      junctionBoxes.push_back(junctionBox);
   }
   file.close();
   vector<Connection> connections;
   for(int i = 0; i < junctionBoxes.size(); i++)
   {
      for(int j = i+1; j < junctionBoxes.size(); j++)
      {
         JunctionBox box1 = junctionBoxes[i];
         JunctionBox box2 = junctionBoxes[j];

         Connection connection;
         connection.id1 = box1.id;
         connection.id2 = box2.id;
         connection.distance = findDistance(box1, box2);
         connections.push_back(connection);
      }
   }

   sort(connections.begin(), connections.end(), [](const Connection &a, const Connection &b){ return a.distance < b.distance; });

   UnionFind UF(junctionBoxes.size());
   for(auto& connection : connections)
   {
      if(attempts-- == 0) break;

      int junctionBox1 = connection.id1;
      int junctionBox2 = connection.id2;

      if(UF.find(junctionBox1) != UF.find(junctionBox2))
         UF.unite(junctionBox1, junctionBox2);
   }

   vector<int> circuitSizes;
   for (int i = 0; i < junctionBoxes.size(); i++) 
   {
      int root = UF.find(i);
      if (root == i) circuitSizes.push_back(UF.getSize(i));
   }

   sort(circuitSizes.begin(), circuitSizes.end(), greater<int>());

   for(int i = 0; i < 3; i++)
      result *= circuitSizes[i];

   cout << "The answer is: " << result << endl;
}