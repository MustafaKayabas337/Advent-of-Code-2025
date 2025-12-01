/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~ 🎄 Advent of Code 2025 - Day 1 | Part 2 🎄
   ~ 👤 Mustafa Kayabaş | 01/12/2025
   ~ ⏱ Writing time: 1 hour 12 min 48 sec
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
    bool isZero;

    while (getline (file, line)) {
        isZero = !wheel;
        char rotation = line[0];
        int number = stoi(line.substr(1));

        wheel += (rotation == 'L') ? -number : number;
        
        if (wheel < 0 && !isZero) sum++;
        sum += abs(wheel) / 100;
        if (!wheel) sum++;

        wheel = ((wheel % 100) + 100) % 100;

        // Debug:
        // cout << "Sum: " << sum << " | Number: " << rotation << number << " | LastWheel: " << wheel << endl;
    }
    file.close(); 


    cout << "The answer is: " << sum << endl;
}