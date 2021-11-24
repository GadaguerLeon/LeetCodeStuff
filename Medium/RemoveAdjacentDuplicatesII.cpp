#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

std::string removeDuplicates(std::string s, int k) {
    std::stack<std::pair<char, int> > ps;
    std::string ans = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (ps.empty() || s[i] != ps.top().first) {
            ps.push(std::make_pair(s[i], 1));
        } else {
            ps.top().second++;
            int count = ps.top().second;
            if (count == k) {
                ps.pop();
            }
        }
    }

    while (!ps.empty()) {
        int count = ps.top().second;
        while (count--) {
            ans.push_back(ps.top().first);
        }
        ps.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main () {
    std::string one = "abcd";
    std::string two = "deeedbbcccbdaa";
    std::string three = "pbbcggttciiippooaais";
    
    std::cout << removeDuplicates(one, 2) << std::endl;
    std::cout << removeDuplicates(two, 3) << std::endl;
    std::cout << removeDuplicates(three, 2) << std::endl;

    return 0;
}