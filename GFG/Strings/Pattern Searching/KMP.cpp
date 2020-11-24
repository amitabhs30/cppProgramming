#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> fillLps(string s)
{
    vector<int> LPS(s.length());
    int i = 1, len = 0;
    LPS[0] = 0;
    while (i < s.length())
    {
        if (s[i] == s[len])
        {
            LPS[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len - 1];
            }
        }
    }
    return LPS;
}

void KMP(string txt, string pat)
{
    int N = txt.length();
    int M = pat.length();
    vector<int> lps = fillLps(pat);

    int i = 0, j = 0;

    while (i < N)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

int main()
{
    string txt, pat;
    cout << "Enter the Text";
    getline(cin, txt);
    cout << "Enter the Pattern";
    getline(cin, pat);
    KMP(txt,pat);
    cout << endl;
    return 0;
}
