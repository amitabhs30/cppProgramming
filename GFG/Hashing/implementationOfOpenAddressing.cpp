#include <iostream>
#include <list>
using namespace std;

struct MyHash
{
    int capacity, size;
    int *arr;

    MyHash(int c)
    {
        capacity = c;
        size = 0;
        for (int i = 0; i < c; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % capacity;
    }
    void insert(int key)
    {
        int i=hash(key);
        int h=i;
        if(size==capacity)
        {
            cout<<"No slots available";
        }
        while(arr[i]!=-1&&arr[i]!=-2&&arr[i]!=key)
        {
            i=(i+1)%capacity;
            if(arr[i]==key)
            {
                cout<<"No slots available";
                return;
            }
            else
            {
                arr[i]=key;
                size++;
            }
            
        }
        
    }
    void del(int key)
    {
        int i=hash(key);
        int h=i;
        if(arr[i]==key)
        {
            arr[i]=-2;
        }
        else
        {
            if(search(key))
            {
                while(arr[i]!=key)
                {
                    i++;
                }
                arr[i]=-2;
            }
            else
            {
                cout<<"Not present in the array";
            }
            
        }
        
    }
    bool search(int key)
    {
        int i = hash(key);
        int h = i;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                return true;
            }
            i = (i + 1) % capacity;
            if (i == h)
                ;
            return false;
        }
        return false;
    }
};

int main()
{

    MyHash mh(7);
    mh.insert(10);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.del(15);
    cout << mh.search(15);
    return 0;
}