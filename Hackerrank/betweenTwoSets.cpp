#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>a1(n1);
    vector<int>a2(n2);
    for(int i=0;i<n1;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<n2;i++)
    {
        cin>>a2[i];
    }
    int res=0;

    
    for(int i=a1[n1-1];i<=a2[0];i++)
    {   a:
        for(int j=0;j<n1;j++)
        {
            if(!(i%a1[j]==0))
            {
                i++;
                if(i<=a2[0])goto a;
                else goto b;
            }
        }
        for(int j=0;j<n2;j++)
        {
            if(!(a2[j]%i==0))
            {
                i++;
                if(i<=a2[0])goto a;
                else goto b;
            }
        }
        res++;
    }
    b:
    cout<<res;
    return 0;
}