#include <bits/stdc++.h>
using namespace std;
void doXOR(char *tmp, char *div, int divLen){
    for (int i = 1; i < divLen; i++)
        tmp[i] = (tmp[i] == div[i]) ? '0' : '1';
}
void calcCRC(char *data, char *tmp, char *div, int dataLen, int divLen){
    for (int i = 0; i < divLen; i++)
        tmp[i] = data[i];
    int i = divLen;
    do{
        if (tmp[0] == '1')
            doXOR(tmp, div, divLen);
        for (int j = 0; j < divLen - 1; j++)
            tmp[j] = tmp[j + 1];
        tmp[divLen - 1] = data[i++];
    } while (i <= dataLen + divLen - 1);
}
void check(char *data, char *div, int dataLen, int divLen){
    char tmp[50];
    cout << "Enter the received data: ";
    cin >> tmp;
    calcCRC(tmp, tmp, div, dataLen, divLen);
    bool errorDetected = false;
    for (int i = 0; i < divLen - 1; i++){
        if (tmp[i] != '0'){
            errorDetected = true;
            break;
        }
    }
    if (errorDetected)
        cout << "\nError detected\n\n";
    else
        cout << "\nNo error detected\n\n";
}
int main(){
    char data[50],div[50],tmp[50];
    cout << "Enter data to be transmitted: ";
    cin >> data;
    cout << "Enter the divisor: ";
    cin >> div;
    int dataLen = strlen(data);
    int divLen = strlen(div);

    for (int i = dataLen; i < dataLen + divLen - 1; i++)
        data[i] = '0';
    data[dataLen + divLen - 1] = '\0';
    calcCRC(data, tmp, div, dataLen, divLen);

    cout << "\nCRC value is: ";
    for (int i = 0; i < divLen - 1; i++)
        cout << tmp[i];
    cout<<"\n";

    cout << "\nGenerated value is: ";
    for(int i=0;i<dataLen-1;i++)
        cout<< data[i];
    for (int i = 0; i < divLen - 1; i++)
        cout << tmp[i];
        cout<<"\n";

    for (int i = dataLen, j = 0; i < dataLen + divLen - 1; i++, j++)
        data[i] = tmp[j];
    data[dataLen + divLen - 1] = '\0';
    check(data, div, dataLen, divLen);
    return 0;
}
/*
Enter data to be transmitted: 10010011100111
Enter the divisor: 10110

CRC value is: 1100

Generated value is: 10010011100111100
Enter the received data: 100100111001111100

No error detected
*/
/*
Enter data to be transmitted: 101010111
Enter the divisor: 101

CRC value is: 11

Generated value is: 1010101111
Enter the received data: 10101011111

No error detected
*/

