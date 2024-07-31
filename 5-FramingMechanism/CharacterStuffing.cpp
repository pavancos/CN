#include<bits/stdc++.h>
using namespace std;
string stuffing(string &data,char flag,char esc){
    string stuffed="";
    stuffed+=flag;
    for(char c:data){
        if(c==flag||c==esc)
            stuffed+=esc;
        stuffed+=flag;
    }
    stuffed+=flag;
    return stuffed;
}
string destuffing(string &data,char flag,char esc){
    string destuffed="";bool escNext=false;
    for(int i=1;i<data.length()-1;i++){
        if(escNext){
            destuffed+=data[i];
            escNext=false;
        }
        else if(data[i]==esc)
            escNext=true;
        else
            destuffed+=data[i];
    }
    return destuffed;
}
int main(){
    char flag,esc;
    string original;
    cout<<"Enter Original String: "; cin>>original;
    cout<<"Enter flag: ";cin>>flag;
    cout<<"Enter Esc Character: ";cin>>esc;
    string stuffed=stuffing(original,flag,esc);
    string destuffed=destuffing(original,flag,esc);
    cout<<"Stuffed Data: "<<stuffed<<endl;
    cout<<"Destuffed Data: "<<destuffed<<endl;
    return 0;
}
