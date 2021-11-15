#include <iostream>
/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1
Input: s = "aba"
Output: true

Example 2
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3
Input: s = "abc"
Output: false
*/

bool pCheck(std::string s, int start, int end) {
    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindrome(std::string s) {
    int left = 0; 
    int right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right]) {
            return (pCheck(s, left + 1, right) || pCheck(s, left, right -1));
        }
        left++;
        right--;
    }
    return true;
}


// Driver code
int main () {
    std::string one = "aba";
    std::string two = "abca";
    std::string three = "abc";

    std::cout << isPalindrome(one) << std::endl;
    std::cout << isPalindrome(two) << std::endl;
    std::cout << isPalindrome(three) << std::endl;
    return 0;
}