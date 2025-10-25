// 409. Longest Palindrome
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest

//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.



// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.



// Constraints:

//     1 <= s.length <= 2000
//     s consists of lowercase and/or uppercase English letters only.




#include<string>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==1){
            return 1;
        }
        unordered_set<char> countMap;
        int ans = 0;
        for(char c: s){
            if (countMap.find(c)!=countMap.end()){
                ans+=2;
                countMap.erase(c);
            }
            else{
                countMap.insert(c);
            }
        }
        if (countMap.size()>0){
            return ans+1;
        }
        return ans;
    }
};
