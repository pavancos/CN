#include <iostream>
#include <string>
using namespace std;
string stuffing(const string& a) {
    string b;
    int cnt = 0;
    for (char bit : a) {
        b.push_back(bit);
        if (bit == '1') {
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
    string flag = "01111110";

    string stuffedData = flag + stuffing(original) + flag;
    cout << "Data after stuffing: " << stuffedData << endl;

    string dataWithoutFlag = stuffedData.substr(flag.length(), stuffedData.length() - 2 * flag.length());
    string destuffedData = destuffing(dataWithoutFlag);

    cout << "Data after destuffing: " << destuffedData << endl;
    if (destuffedData == original) {
        cout << "Success: Destuffed data matches the original data!" << endl;
    } else {
        cout << "Error: Destuffed data does not match the original data!" << endl;
    }
    return 0;
}