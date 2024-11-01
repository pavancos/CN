#include <iostream>
#include <string>

using namespace std;

string stringStuffing(const string& data, const string& flag, const string& esc) {
    string stuffedData = flag;

    size_t flagLength = flag.length();
    size_t escLength = esc.length();

    for (size_t i = 0; i < data.length(); i++) {
        if (data.substr(i, flagLength) == flag || data.substr(i, escLength) == esc) {
            stuffedData += esc;
        }
        stuffedData += data[i];
    }

    stuffedData += flag;
    return stuffedData;
}

string stringUnstuffing(const string& stuffedData, const string& flag, const string& esc) {
    string data;
    size_t flagLength = flag.length();
    size_t escLength = esc.length();

    for (size_t i = flagLength; i < stuffedData.length() - flagLength; i++) {
        if (stuffedData.substr(i, escLength) == esc) {
            if (stuffedData.substr(i + escLength, flagLength) == flag) {
                data += flag;
                i += escLength + flagLength - 1;
            } else if (stuffedData.substr(i + escLength, escLength) == esc) {
                data += esc;
                i += escLength * 2 - 1;
            } else {
                data += stuffedData[i];
            }
        } else {
            data += stuffedData[i];
        }
    }

    return data;
}

int main() {
    string data, flag, esc;

    cout << "Enter data to be transmitted: ";
    getline(cin, data);
    cout << "Enter FLAG string: ";
    getline(cin, flag);
    cout << "Enter ESCAPE string: ";
    getline(cin, esc);

    string stuffedData = stringStuffing(data, flag, esc);
    cout << "Stuffed Data: " << stuffedData << endl;

    string unstuffedData = stringUnstuffing(stuffedData, flag, esc);
    cout << "Unstuffed Data: " << unstuffedData << endl;

    return 0;
}