#include<iostream>
using namespace std;

int main() {
    int t=0;
    scanf("%d",&t);
    while(t--)
    {   
        unsigned long long a,b;
        scanf("%lld %lld",&a,&b);
        cout<<((b&(b-1ll))?"No" : "Yes") <<"\n";
    }
    return 0;
}