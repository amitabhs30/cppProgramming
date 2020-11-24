#include<iostream>
#include<stack>
#include<deque>


using namespace std;

int main()
{
    stack<int>s;
    s.push(10);
    s.push(12);
    s.push(15);
    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}