#include <iostream>
#include <stack>

void reverseStack(std::stack<int>& original) 
{
    std::stack<int> tempStack;

    // Move all elements from original stack to tempStack
    while (!original.empty()) 
    {
        tempStack.push(original.top());
        original.pop();
    }

    // Move them back to the original stack (now reversed)
    while (!tempStack.empty()) 
    {
        original.push(tempStack.top());
        tempStack.pop();
    }
}


// Utility function to print the stack
void printStack(std::stack<int> s) 
{
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main_reverseStack()
{
    std::stack<int> myStack;

    // Push elements
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << "Original stack: ";
    printStack(myStack);

    // Reverse stack
    reverseStack(myStack);

    std::cout << "Reversed stack: ";
    printStack(myStack);

    return 0;
}




namespace recursion //O(n)
{
    // Function to insert an element at the bottom of the stack
    void insertAtBottom(std::stack<int>& s, int item) {
        if (s.empty()) 
        {
            s.push(item);
            return;
        }

        // Pop the top element
        int top = s.top();
        s.pop();

        // Recursive call
        insertAtBottom(s, item);

        // Push the top element back
        s.push(top);
    }

    // Function to reverse the stack using recursion
    void reverseStack(std::stack<int>& s) 
    {
        if (s.empty()) return;

        // Pop the top element
        int top = s.top();
        s.pop();

        // Reverse the remaining stack
        reverseStack(s);

        // Insert the popped element at the bottom
        insertAtBottom(s, top);
    }
}
