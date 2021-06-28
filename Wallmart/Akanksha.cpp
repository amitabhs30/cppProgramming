#include<string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;
unordered_set<string> sett;
void printAllKLengthRec(string str, string prefix,
                                    int n, int k)
{
     int count=0;
    if (k == 0)
    {
        sort(str.begin(), str.end());
        sett.insert(str);
    }
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + str[i];
        printAllKLengthRec(str, newPrefix, n, k - 1);
    }
    
 
}
 

void query1(string s,int l,int r,int k){
    
    string str=s.substr(l-1,r-l+1);
    int len=str.length();
    printAllKLengthRec(str, "", len, k);
    cout<<sett.size()<<endl;
    
}
string query2(string s,int p,char c){
    s[p]=c;
    return s;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(x==1){
            int l,r,k;
            cin>>l>>r>>k;
            query1(s,l,r,k);
        }
        else{
            int p;
            char c;
            cin>>p;
            cin>>c;
           s= query2(s,p,c);
        }
        
    }

    return 0;
}