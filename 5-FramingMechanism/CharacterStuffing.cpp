#include <iostream>
#include <string>
using namespace std;
string stuffing(const string &data, char flag, char esc)
{
    string stuffed;
    stuffed += flag;
    for (char c : data)
    {
        if (c == flag || c == esc)
            stuffed += esc;
        stuffed += c;
    }
    stuffed += flag;
    return stuffed;
}

string destuffing(const string &data, char flag, char esc)
{
    string destuffed;
    bool escNext = false;

    for (int i = 1; i < data.length() - 1; ++i)
    {
        if (escNext)
        {
            destuffed += data[i];
            escNext = false;
        }
        else if (data[i] == esc)
        {
            escNext = true;
        }
        else
        {
            destuffed += data[i];
        }
    }
    return destuffed;
}

int main()
{
    char flag, esc;
    string original;
    cout << "Enter data String: ";
    cin >> original;
    cout << "Enter Flag: ";
    cin >> flag;
    cout << "Enter Esc Character: ";
    cin >> esc;
    string stuffed = stuffing(original, flag, esc);
    cout << "Stuffed Data: " << stuffed << endl;
    string destuffed = destuffing(stuffed, flag, esc);
    cout << "Destuffed Data: " << destuffed << endl;

    if (destuffed == original)
    {
        cout << "Success: Destuffed data matches the original data!" << endl;
    }
    else
    {
        cout << "Error: Destuffed data does not match the original data!" << endl;
    }
    return 0;
}