#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
string s;

void reverseWords();

void reverse(int start, int end)
{
    while(start<end)
    {
        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
}

int main()
{
    
    cout << "Enter the String of characters";
    getline(cin, s);
    reverseWords();
    cout<<s;
    return 0;
}

void reverseWords()
{   int start=0;

    for(int end=0;end<s.length();end++)
    {
        if(s[end]==' ')
        {
            reverse(start,end-1);
            start=end+1;
        }
    }
    reverse(start,s.length()-1);
    reverse(0,s.length()-1);

}