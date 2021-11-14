#include <iostream>
#include <vector>
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1
Input: nums = [2,2,1]
Output: 1

Example 2
Input: nums = [4,1,2,1,2]
Output: 4

Example 3
Input: nums = [1]
Output: 1
*/

int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main () {
    std::vector<int> one = {2, 2, 1};
    std::vector<int> two = {4, 1, 2, 1, 2};
    std::vector<int> three = {1};

    std::cout << singleNumber(one) << std::endl;
    std::cout << singleNumber(two) << std::endl;
    std::cout << singleNumber(three) << std::endl;
    return 0;
}