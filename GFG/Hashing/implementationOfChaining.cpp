#include <iostream>
#include <list>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;

    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[b];
    }

    void insert(int key)
    {
        int index = key % BUCKET;
        table[index].push_back(key);
    }
    void del(int key)
    {
        int index = key % BUCKET;
        table[index].remove(key);
    }
    bool search(int key)
    {
        int index = key % BUCKET;
        for (auto x : table[index])
        {
            if (x == key)
            {
                return true;
            }
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