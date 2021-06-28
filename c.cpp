#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
sample input-
N (total number of flowers)
p1 p1' (two spaced integers defining the price for gardener1 and gardener2 for ith flower)
p2 p2'
.  .
.  .
.  .
pn pn'
*/

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> >gardener1(n);
    vector<pair<int,int> >gardener2(n);
    vector<bool>purchased(n,false);
    int cost=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        gardener1[i]=make_pair(x,i);
        gardener2[i]=make_pair(y,i);    
    }
    sort(gardener1.begin(),gardener1.begin());
    sort(gardener2.begin(),gardener2.begin());
    bool g1=gardener1.begin()->first<gardener2.begin()->first?true:false;
    for(int i=0;i<n;)
    {
        if(g1)
        {
            int price=gardener1.begin()->first;
            int flower=gardener1.begin()->second;
            if(purchased[flower])
            {
                gardener1.erase(gardener1.begin());
                continue;
            }
            else
            {
                cost+=price;
                purchased[flower]=true;
                g1=!g1;
                i++;
            }     
        }
        else
        {
            int price=gardener2.begin()->first;
            int flower=gardener2.begin()->second;
            if(purchased[flower])
            {
                gardener2.erase(gardener2.begin());
                continue;
            }
            else
            {
                cost+=price;
                purchased[flower]=true;
                g1=!g1;
                i++;
            }      
        }
        
    }
return 0;
}