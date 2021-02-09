#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


vector<int> ReadHeights(const string& filename)
{
    ifstream f(filename);
    vector<int> heights;

    int tmp;
    while (f >> tmp) {
        heights.push_back(tmp);
    }

    return heights;
}

pair<bool, int> GetHighestDent(const vector<int> &heights)
{
    bool l = false;
    int maxx;

    for (int i = 1; i < heights.size()-1; i++) {
        if (heights[i] < heights[i-1] && heights[i] < heights[i+1]) {
            l = true;
            maxx = heights[i];
        }
    }

    pair<bool, int> returner; returner.first = l; returner.second = maxx;
    return returner;
}

int main()
{
    cout << "Szelgorcs" << endl;
    const vector<int> heights = ReadHeights("in.txt.txt");

    bool l;
    int max;
    const pair<bool, int> dent = GetHighestDent(heights);
    if (dent.first) {
        cout << "A legmagasabb rucsok: " << dent.second << endl;
    }
    else {
        cout << "Nincs rucsok." << endl;
    }

    return 0;
}

// > g++ -std=c++11 main.cpp
// > a.exe