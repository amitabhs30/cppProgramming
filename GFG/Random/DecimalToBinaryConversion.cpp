#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void decimalToBinary(int);

int main() {
    int n;
    cout<<"Enter the no. to be changed from decimal to binary";
    cin>>n;
    decimalToBinary(n);
    cout<<endl;
    return 0;
}
void decimalToBinary(int n)
{
    if(n==0)
        return;
    decimalToBinary(n/2);
    cout<<n%2;    
}