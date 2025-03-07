#include"pch"
#include <stack>
#include <queue>


// Function to copy a stack using a queue
stack<int> copyStackUsingQueue(stack<int> originalStack) {
    queue<int> tempQueue;

    // Step 1: Transfer stack elements to queue
    while (!originalStack.empty()) {
        tempQueue.push(originalStack.top());
        originalStack.pop();
    }

    // Step 2: Transfer elements back from queue to new stack
    stack<int> copiedStack;
    while (!tempQueue.empty()) {
        copiedStack.push(tempQueue.front());
        tempQueue.pop();
    }

    return copiedStack;
}
namespace {
    // Function to print stack elements
    void printStack(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}

int main_copyStackUsingQueue() {
    stack<int> originalStack;
    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);
    originalStack.push(4);
    originalStack.push(5);

    cout << "Original Stack: ";
    printStack(originalStack);

    // Copy stack using a queue
    stack<int> copiedStack = copyStackUsingQueue(originalStack);

    cout << "Copied Stack: ";
    printStack(copiedStack);

    return 0;
}

