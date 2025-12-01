/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 1 | Part 1 🎄
   ~ 👤 Mustafa Kayabaş | 01/12/2025
   ~ ⏱ Writing time: 20 min 20 sec
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");

    int wheel = 50;
    int sum = 0;

    while (getline (file, line)) {
        char rotation = line[0];
        int number = stoi(line.substr(1));

        wheel += (rotation == 'L') ? -number : number;
        wheel = ((wheel % 100) + 100) % 100;

        if (!wheel) sum++;
    }
    file.close(); 

    cout << "The answer is: " << sum << endl;
}