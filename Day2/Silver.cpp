#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");
    int result = 0;


    while (getline (file, line)) {
    }
    file.close();

    cout << "The answer is: " << result << endl;
}