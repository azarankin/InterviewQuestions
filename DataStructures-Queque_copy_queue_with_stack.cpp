#include"pch"
#include <queue>
#include <stack>



// Function to copy a queue using a stack
queue<int> copyQueueUsingStack(queue<int> originalQueue) {
    stack<int> tempStack;

    // Step 1: Transfer queue elements to stack
    while (!originalQueue.empty()) {
        tempStack.push(originalQueue.front());
        originalQueue.pop();
    }

    // Step 2: Transfer elements back from stack to new queue
    queue<int> copiedQueue;
    while (!tempStack.empty()) {
        copiedQueue.push(tempStack.top());
        tempStack.pop();
    }

    return copiedQueue;
}

namespace {
    // Function to print queue elements
    void printQueue(queue<int> q) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}

int main_copyQueueUsingStack() {
    queue<int> originalQueue;
    originalQueue.push(1);
    originalQueue.push(2);
    originalQueue.push(3);
    originalQueue.push(4);
    originalQueue.push(5);

    cout << "Original Queue: ";
    printQueue(originalQueue);

    // Copy queue using a stack
    queue<int> copiedQueue = copyQueueUsingStack(originalQueue);

    cout << "Copied Queue: ";
    printQueue(copiedQueue);

    return 0;
}
