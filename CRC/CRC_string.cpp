#include <iostream>
using namespace std;
string xorOf(string encoded, string crc){
    int crclen = crc.length();
    for (int i = 0; i <= (encoded.length() - crclen);i++){
        if(encoded[i]=='1'){
            for (int j = 0; j < crclen; j++)
                encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }
    }
    return encoded;
}
int main(){
    string data, crc, encoded = "";
    cout << endl
         << "-----------Sender Side --------------" << endl;
    cout << "Enter Data bits: " << endl;
    cin >> data;
    cout << "Enter Generator: " << endl;
    cin >> crc;
    encoded += data;
    int datalen = data.length();
    int crclen = crc.length();
    for (int i = 1; i <= (crclen - 1); i++)
        encoded += '0';
    encoded = xorOf(encoded, crc);
    cout << "CRC is: ";
    cout << encoded.substr(encoded.length() - crclen + 1) << endl
         << endl;
    cout << "Message to be Transmitted over network: ";
    cout << data + encoded.substr(encoded.length() - crclen + 1);
    cout << endl
         << "---------------Reciever Side-----------------" << endl;
    cout << "Enter the message recieved: " << endl;
    string msg;
    cin >> msg;

    msg = xorOf(msg, crc);
    for (char i : msg.substr(msg.length() - crclen + 1))
        if (i != '0'){
            cout << "Error in communication " << endl;
            return 0;
        }
    cout << "No Error" << endl;
    return 0;
}