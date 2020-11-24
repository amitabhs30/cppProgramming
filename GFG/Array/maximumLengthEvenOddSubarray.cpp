#include <stdio.h>
#include <iostream>
using namespace std;
int findmaxVal(int *, int, int);
int findmaxValE(int *, int, int);
int main()
{
    int size, *arr = NULL;
    cout << "Enter the size of array";
    scanf("%d", &size);
    arr = new int[size];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int res = findmaxValE(arr, 0, size);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}
int findmaxVal(int *arr, int start, int end) // O(n^2)
{
    int count, res;
    for (int i = 0; i < end; i++)
    {
        count = 1;
        for (int j = i; j < end; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
            {
                count++;
            }
            else
            {
                break;
            }
        }
        res = max(count, res);
    }
    return res;
}
// 5 10 3 2 4 6 3 2 9
int findmaxValE(int *arr, int start, int end) // O(n)
{
    int cur = 1, res = 1;
    for (int i = 1; i < end; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            cur++;
            res = max(res, cur);
        }
        else
        {
            cur = 1;
        }
    }
    return res;
}


        // // forcan 50mg
        // // folvite
        // // paracitamol
        // // pantocid DSR
        // // ceftum 500-Antibiotic
        // // celim 500-vitamin C
        // // daflon 500- for piles
        // // piloroute 
        // // dayo 60k 
        // 9711089218