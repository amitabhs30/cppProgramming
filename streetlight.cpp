// #include<bits/stdc++.h>
#include "/Users/amitabh/stdc++.h"

using namespace std;


int c=0;

bool sortByrange(const pair<pair<int,int>,int>&a,const pair<pair<int,int>,int>&b){

    return (abs(a.first.second-a.first.first)>abs(b.first.second-b.first.first));

}


void findSx(vector<pair<pair<int,int>,int> >range, vector<int>pow, int start, int end)
{
    range.erase(range.begin());
    if(start==end)
    {
        return;
    }
    while((range.front().second<=start||range.front().second>=end)&&(!range.empty()))
    {
        range.erase(range.begin());
    }
    if(range.empty())
    {
        return;
    }
    else if((range.front().first.first<=start&&range.front().first.second>=end))
    {
        c+=1;
        return;
    }
    else
    {   c+=1;
        findSx(range,pow,start,range.front().first.first);
        findSx(range,pow,range.front().first.second,end);
    }
}

void findS(vector<pair<pair<int,int>,int> >range, vector<int>pow, int start, int end)
{
    c+=1;
        findSx(range,pow,start,range.front().first.first);
        findSx(range,pow,range.front().first.second,end);
}



int main()
{
    int n;
    //map<int,int>imap;
    cin>>n;
    vector<int>pow(n);
    vector<pair<pair<int,int>,int> >range(n);

    for(int i=0;i<n;i++)
    {
        cin>>pow[i];
        range[i].first.first=max(i-pow[i],0);
        range[i].first.second=min(i+pow[i],n-1);
        range[i].second=i;
        //imap[i]=pow[i];
    }
    for(auto e: pow)
    {
        if(e>=n)
        {
            cout<<"1";
        }
    }
    sort(range.begin(),range.end(),sortByrange);
    findS(range,pow,0,n-1);
    cout<<c<<endl;
    return 0;
}
