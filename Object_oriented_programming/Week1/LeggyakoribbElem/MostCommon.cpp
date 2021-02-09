#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> ReadNums(const string& filename)
{
    ifstream f(filename);
    vector<int> numbers;

    int tmp;
    while (f >> tmp) {
        numbers.push_back(tmp);
    }

    return numbers;
}

/*pair<int, int> function (const int &numbers)
{

}*/
int function (const vector<int> &numbers)
{
    int mostCommon = numbers[0];
    int quantity = 1;

    for (int i = 0; i < numbers.size(); i++) {
        int current = 0;
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[j] == numbers[i]) {
                current++;
            }
        }

        if (current > quantity) {
            mostCommon = numbers[i];
            quantity = current;
        }
    }

    return mostCommon;
}

int main() {

    const vector<int> numbers = ReadNums("in.txt.txt");

    int result = function(numbers);
    cout << "Most common number is " << result << endl;

    /*for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }*/

    return 0;
}