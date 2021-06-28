#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

string normalise(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='2')
        {
            s[i]='5';
        }
        if(s[i]=='6')
        {
            s[i]='9';
        }
    }
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpn;
        string n,s;
        int sl,ans=INT16_MAX;
        cin>>n>>sl>>s;
        n=normalise(n);
        s=normalise(s);
        for(char e:s)
        {
            mps[e]++;
        }
        for(char e:n)
        {
            mpn[e]++;
        }
        // for(auto e:mpn)
        // {
        //     cout<<e.first<<" "<<e.second<<endl;
        // }
        for(auto e: mpn)
        {
            int countInN=e.second;
            int countInS=mps[e.first];
            if(countInN>countInS)
            {
                //Not possible to make the number.
                cout<<0<<endl;
                break;
            }
            else
            {
                int val=countInS-countInN;
                ans=min(ans,val+1);
            }            
        }
        cout<<ans<<endl;
    }

    return 0;
}