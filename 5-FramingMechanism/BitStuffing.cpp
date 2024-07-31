#include <iostream>
#include <string>
using namespace std;
string stuffing(const string& a) {
    string b;
    int cnt = 0;
    for(char c : a) {
        b.push_back(c);
        if (c == '1') {
            cnt++;
            if (cnt == 5) {
                b.push_back('0');
                cnt = 0;
            }
        } else 
            cnt = 0;
    }
    return b;
}
string destuffing(const string& a) {
    string b;
    int cnt = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
            cnt++;
            b.push_back(a[i]);
            if (cnt == 5 && i + 1 < a.size() && a[i + 1] == '0') {
                i++;
                cnt = 0;
            }
        } else {
            b.push_back(a[i]);
            cnt = 0;
        }
    }
    return b;
}
int main() {
    string original;
    cout << "Enter the original data: ";
    cin >> original;
    string stuffed =stuffing(original);
    cout << "Data after stuffing: " << stuffed << endl;
    string destuffed = destuffing(stuffed);
    cout << "Data after destuffing: " << destuffed << endl;
    if (destuffed == original)
        cout << "Success: Destuffed data matches the original data" << endl;
    else
        cout << "Error: Destuffed data does not match the original data" << endl;
    return 0;
}