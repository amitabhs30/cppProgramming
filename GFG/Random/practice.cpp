#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(int);

int main() {
    int n;
    cin>>n;
    print(n);
    return 0;
}

void print(int n)
{
    if(n==0)
    return;
    cout<<n;
    print(n-1);
}