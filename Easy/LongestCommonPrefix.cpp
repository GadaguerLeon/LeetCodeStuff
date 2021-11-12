#include <iostream>
#include <vector>
#include <algorithm>
/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

std::string longestCommonPrefix(std::vector<std::string> strs) {
    std::string ans;
    std::string min = *min_element(strs.begin(), strs.end());

    for (int i = 0; i < strs.size(); i++) {
        for (int j = 0; j < strs.size(); j++) {
            if (min[i] != strs[j][i]) {
                return ans;
            }
        }
        ans.push_back(min[i]);
    }
    return ans;
}

// Driver code
int main () {
    std::vector<std::string> one = {"flower","flow","flight"};
    std::vector<std::string> two = {"dog","racecar","car"};
    std::cout << longestCommonPrefix(one) << std::endl;
    std::cout << longestCommonPrefix(two) << std::endl;
    return 0;
}