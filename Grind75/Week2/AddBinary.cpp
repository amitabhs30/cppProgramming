
// 67. Add Binary
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given two binary strings a and b, return their sum as a binary string.



// Example 1:

// Input: a = "11", b = "1"
// Output: "100"

// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"



// Constraints:

//     1 <= a.length, b.length <= 104
//     a and b consist only of '0' or '1' characters.
//     Each string does not contain leading zeros except for the zero itself.



#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int aIt = a.length()-1;
        int bIt = b.length()-1;
        int carry = 0;
        while(aIt>=0 || bIt>=0 || carry){
            if(aIt>=0) carry += a[aIt--] - '0';
            if(bIt>=0) carry += b[bIt--] - '0';
            res += carry %2 + '0';
            carry/=2;
        }
        reverse(begin(res),end(res));
        return res;
    }
};
