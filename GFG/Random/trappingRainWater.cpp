#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct pit{//A simple structure of pit where each pit contains its height , the longest height to the left and to the right of it.
    int leftLongestElevation;
    int rightLongestElevation;
    int currPitSize;
};

int main()
{
    int n,e;
    cout<<"Enter Size of the array";
    cin>>n;
    vector<pit>pits(n);
    cout<<"Enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>e;
        pits[i].currPitSize=e;
    }
    int max1=INT32_MIN;
    int max2=INT32_MIN;
    for(int i=0,j=n-1;i<n;i++,j--)//O(n)//Calculating the left longest elevation and right longest elevation for each pit.
    {
        pits[i].leftLongestElevation=(max1<pits[i].currPitSize)?
                                    pits[i].currPitSize:
                                    max1;
        max1=max(pits[i].currPitSize,max1);
        pits[j].rightLongestElevation=(max2<pits[j].currPitSize)?
                                    pits[j].currPitSize:
                                    max2;
        max2=max(pits[j].currPitSize,max2);
    }
    int sum=0;
    
    for(int i=1;i<n-1;i++)//O(n)//amount of water a pit can trap is basically minimum of left longest elevation and right longest elevation - height of that pit. Also the boundary pits can not store water above them.
    {
        sum+=min(pits[i].leftLongestElevation,pits[i].rightLongestElevation)-pits[i].currPitSize;
    }
    cout<<"Total Rain Water that can be trapped = "<<sum<<endl;

    return 0;//(Total time complexity O(n))

}