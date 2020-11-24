#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {   
        int m,n,e;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            cin>>e;
            a.push_back(e);
        }
        sort(a.begin(),a.end());

        int i=0,j=a.size()-1;

        while(i<j)
        {
            if(a[i]+a[j]==m)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
                break;
            }
            else if(a[i]+a[j]>m)
            j--;
            else 
            i++;
        }

        t--;
    }

    return 0;
}