#include <iostream>
#include <vector>
#include <algorithm>
/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

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

int main () {
    std::vector<std::string> test = {"flower","flow","flight"};
    std::cout << longestCommonPrefix(test) << std::endl;
    return 0;
}