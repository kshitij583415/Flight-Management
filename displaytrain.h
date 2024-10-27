#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printBoxWithLabel(const string &label)
{
    int labelLength = label.length();
    int boxWidth = labelLength + 4; // Account for padding and borders

    // Print top border
    cout << string(boxWidth, '-') << endl;

    // Print label with padding and borders
    cout << "| " << label << " |" << endl;

    // Print bottom border
    cout << string(boxWidth, '-') << endl;
}

void display2d(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
