#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;
int shiftString(int size,int no1,int no0,vector<int>data,int zeroWhenEvenOne,int ZeroWhenOddOne,string s)
{
    set<pair<pair<int,int>,pair<int,int> > >id;
    id.insert(make_pair(make_pair(no1,no0),make_pair(zeroWhenEvenOne,ZeroWhenOddOne)));
    for(int i=size;i<s.size();i++)
    {
        if(s[i-size]=='1')
        {
            no1--;
            data.erase(data.begin());
            int x=zeroWhenEvenOne;
            zeroWhenEvenOne=ZeroWhenOddOne;
            ZeroWhenOddOne=x;
        }
        else
        {       
            zeroWhenEvenOne--;
            no0--;
            data[0]--;
        }
        if(s[i]=='1')
        {
            data.push_back(0);
            no1++;
        }
        else
        {
            no0++;
            data[data.size()-1]++;
            if(data.size()%2)
                zeroWhenEvenOne++;
            else
                ZeroWhenOddOne++;
        }
        id.insert(make_pair(make_pair(no1,no0),make_pair(zeroWhenEvenOne,ZeroWhenOddOne)));//2
    }
    return id.size();
}

int getSubstring(int start,int end,string s)
{
    int no=0,nz=0,zeroBeforeOne=0,zeroWhenEvenOne=0,zeroWhenOddOne=0,currentOnes=0;
    vector<int>data;
    for(int i=start;i<end;i++)
    {
        if(s[i]=='1')
        {
            data.push_back(zeroBeforeOne);
            zeroBeforeOne=0;
            currentOnes++;
            no++;
        }
        else
        {
            zeroBeforeOne++;
            nz++;
            if(currentOnes%2)
                zeroWhenOddOne++;
            else
                zeroWhenEvenOne++;
        }
    }
    data.push_back(currentOnes);
    int resForSize=shiftString(end,no,nz,data,zeroWhenEvenOne,zeroWhenOddOne,s);
    return resForSize;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int res=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            res+=getSubstring(0,i+1,s);
        }
        cout<<res<<endl;
    }
    return 0;
}
