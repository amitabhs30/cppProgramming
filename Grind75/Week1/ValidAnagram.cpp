
// 242. Valid Anagram
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given two strings s and t, return true if t is an

// of s, and false otherwise.



// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false



// Constraints:

//     1 <= s.length, t.length <= 5 * 104
//     s and t consist of lowercase English letters.



// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int hash[26] = {0};
        for(char c: t){
            hash[c-'a']+=1;
        }
        for(char c: s){
            if(hash[c-'a']==0)return false;
            hash[c-'a']-=1;
        }
        for(int val: hash){
            if(val){
                return false;
            }
        }
        return true;
    }
};
