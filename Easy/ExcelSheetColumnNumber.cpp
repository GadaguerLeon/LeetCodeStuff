#include <iostream>
/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
Example 1
Input: columnTitle = "A"
Output: 1

Example 2
Input: columnTitle = "AB"
Output: 28

Example 3
Input: columnTitle = "ZY"
Output: 701

Example 4
Input: columnTitle = "FXSHRXW"
Output: 2147483647
*/

int titleToNumber(std::string columnTitle) {
    int ans = 0;
    int pow = 1;
    for (int i = columnTitle.size() - 1; i >= 0; i--) {
        ans += (columnTitle[i] - 64) * pow;
        pow *= 26;
    }
    return ans;
}

// Driver code 
int main() {
    std::string one = "A";
    std::string two = "AB";
    std::string three = "ZY";
    std::string four = "FXSHRXW";

    std::cout << titleToNumber(one) << std::endl;
    std::cout << titleToNumber(two) << std::endl;
    std::cout << titleToNumber(three) << std::endl;
    std::cout << titleToNumber(four) << std::endl;
    return 0;
}