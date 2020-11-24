#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){

    string in,hr,dn;
    getline(cin,in);
    hr=in.substr(0,2);
    dn=in.substr(8,2);
    in.pop_back();
    in.pop_back();
    if(dn=="AM"&&hr=="12")
    {
        in[0]='0';
        in[1]='0';
    }
    if(dn=="PM")
    {
        if(hr!="12")
        {
            string s=to_string(stoi(hr)+12);
            in[0]=s[0];
            in[1]=s[1];
        }
    }
    cout<<in;
    return 0;
}