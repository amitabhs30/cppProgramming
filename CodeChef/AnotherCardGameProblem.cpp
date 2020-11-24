#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n>0)
    {
        int chefno,rickno;
        cin>>chefno>>rickno;
        // chefno=chefno/9;
        // rickno=rickno/9;
        if(chefno%9==0)
            chefno=chefno/9;
        else
            chefno=chefno/9+1;

        if(rickno%9==0)
            rickno=rickno/9;
        else
            rickno=rickno/9+1;    
            
        if(chefno==rickno||chefno>rickno)
        { 
            cout<<"1"<<" "<<rickno<<endl;
        }
        else
        {
            cout<<"0"<<" "<<chefno<<endl;
        }
        n--;
    }

    return 0;
}