#include <stdio.h>
#include <iostream>
using namespace std;
int findTrappedWater(int *, int, int);
int findTrappedWaterE(int *, int, int);
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
    int res = findTrappedWater(arr, 0, size - 1);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}


int findTrappedWater(int *arr, int start, int end) // naive solution O(n^2)
{   int lmax=0,rmax=0,water=0;
    for (int i=0;i<end;i++)
    {   int lmax=arr[i];
        for(int j=0;j<i;j++)
        {
            lmax=max(arr[j],lmax);
        }
        int rmax=arr[i];
        for(int j=i+1;j<=end;j++)
        {
            rmax=max(arr[j],rmax);
        }

        water+=(min(lmax,rmax)-arr[i]);
    }
    return water;
}

int findTrappedWaterE(int *arr, int start, int end) // O(n), space complexity of O(n)
{   int water=0;
    int rmax[end+1],lmax[end+1];

    lmax[0]=arr[0];
    for(int i=1;i<end;i++)
    {
        lmax[i]=max(lmax[i-1],arr[i]);
    }
    rmax[end]=arr[end];
    for (int i=end-1;i>=0;i--)
    {
        rmax[i]=max(rmax[i+1],arr[i]);
    }
    for (int i=1;i<end;i++)
    {
        water+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return water;
}






// int findTrappedWater(int *arr, int start, int end)  //My try
// {
//     int flag = 0, pitStart, water = 0;
//     for (int i = 0; i < end; i++)
//     {
//         if ((arr[i + 1] < arr[i]) && (flag == 0))
//         {
//             pitStart = arr[i];
//             flag = 1;
//             water += pitStart - arr[i + 1];
//         }
//         if ((arr[i + 1] < arr[i]) && (flag == 1))
//         {
//             water += pitStart - arr[i + 1];
//         }

//         if (arr[i + 1] > arr[i] && flag == 1)
//         {
//             if (i + 1 == end)
//             {
//                 return water;
//             }
//             else if(arr[i+1]>=pitStart)
//             {
//                 pitStart=arr[i+1];
//                 flag=0;
//             }
//             else
//             {
//                 water += pitStart -arr[i+1];
//             }
//         }
//     }
//     return water;
// }