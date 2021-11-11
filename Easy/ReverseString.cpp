#include <iostream>

void reverseString(std::string& s) {
    int left = 0; 
    int right = s.size() - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
}

int main() {
    std::string test = "Stevie Ray Vaughan";
    reverseString(test);
}