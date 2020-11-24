#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    int mul = 1;
    for (int i = 2; i <= n; i++)
    {
        mul = mul * i;
    }
    return mul;
}

void findLexicographicRank(string s)
{
    int count[256]={0};
    int n=s.length();
    int fac=fact(n);
    for(int i=0;i<n;i++)
    {
        count[s[i]]++;
    }
    for(int i=1;i<=256;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    int val=0;
    for(int i=0;i<n;i++)
    {
        fac=fac/(n-i);
        val+=(count[s[i]-1]*fac);
        for(int j=s[i];j<=256;j++)
        {
            count[j]--;
        }
    }
    cout<<"Lexicographic value is: "<<val+1;
}

int main()
{
    string s1;
    cout << "Enter the String of characters";
    getline(cin, s1);

    findLexicographicRank(s1);
    return 0;
}
