#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void swap(int i,vector<int>&A,vector<int>&B)
{
    int temp=A[i];
    A[i]=B[i];
    B[i]=temp;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>A(n);
        vector<int>B(m);
        int sumA=0,sumB=0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sumA+=A[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>B[i];
            sumB+=B[i];
        }
        if(sumA>sumB)
        {
            //End the loop as John is already winning
            cout<<"0"<<endl;
            continue;
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end(),greater<int>());
        int i=0,count=0;
        do{
            sumA+=B[i]-A[i];
            sumB+=A[i]-B[i];
            swap(i,A,B);
            count++;
            i++;
        }while((sumA<sumB)&&(i<A.size()&&i<B.size()));
        if(sumA<=sumB)
        {
            // not possible
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<count<<endl;
        }
    }
    
    return 0;
}
