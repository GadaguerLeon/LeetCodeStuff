#include <iostream>
#include <vector>
#include <stack>
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

int evalRPN(std::vector<std::string> tokens) {
    std::stack<char> st;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int operand_one = st.top();
            st.pop();
            int operand_two = st.top();
            st.pop();

            if (tokens[i] == "+") {
                st.push(operand_two + operand_one);
            } else if (tokens[i] == "-") {
                st.push(operand_two - operand_one);
            } else if (tokens[i] == "*") {
                st.push(operand_two * operand_one);
            } else if (tokens[i] == "/") {
                st.push(operand_two / operand_one);
            }
        } else {
            st.push(atoi(tokens[i].c_str()));
        }
    }
    return st.top();
}

// Driver code 
int main() {
    std::vector<std::string> one = {"2","1","+","3","*"};
    std::vector<std::string> two = {"4","13","5","/","+"};
    std::vector<std::string> three = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    std::cout << evalRPN(one) << std::endl;
    std::cout << evalRPN(two) << std::endl;
    std::cout << evalRPN(three) << std::endl;
}