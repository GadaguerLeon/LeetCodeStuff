#include <iostream>
#include <stack>
#include <algorithm>
/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1 
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2
Input: s = "azxxzy"
Output: "ay"
*/

std::string removeDuplicates(std::string s) {
    std::stack<char> st;
    std::string ans;

    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || s[i] != st.top()) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

// Driver code
int main() {
    std::string one = "abbaca";
    std::string two = "azxxzy";
    std::cout << removeDuplicates(one) << std::endl;
    std::cout << removeDuplicates(two) << std::endl;
    return 0;
}