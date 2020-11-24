#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*fb=first burner
  sb=second burner
  res=result
  t=temp
  wh=where in array
  */

int main()
{
    long long int z;
    cin >> z;
    while (z > 0)
    {
        int n, res = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int fb, sb;
        int wh = arr.size() - 1;
        sort(arr.begin(), arr.end());
        fb = arr[wh--];
        sb = arr[wh--];
        while (wh >= 0)
        {
            int t = min(sb, fb);
            res += t;
            if (fb == sb)
            {
                sb = 0;
                fb = 0;
                sb = arr[wh--];
                if (wh >= 0)
                    fb = arr[wh--];
                continue;
            }
            else if (fb < sb)
            {
                sb = sb - fb;
                fb = arr[wh--];
            }
            else
            {
                fb = fb - sb;
                sb = arr[wh--];
            }
        }
        int t = max(sb, fb);
        res += t;
        cout << res << endl;
        z--;
    }
    return 0;
}
