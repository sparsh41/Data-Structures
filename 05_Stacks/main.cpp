#include "Stack.hpp"
#include "Stack.cpp"

int main() {
    StackArray::Stack<char, 30> s1;
    
    int i = 0;

    while (i < 26) {
        s1.push(i++ + 'A');
    }

    while (!s1.empty()) {
        std::cout << s1.pop() << std::endl;
    }

    try {
        s1.pop();
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}