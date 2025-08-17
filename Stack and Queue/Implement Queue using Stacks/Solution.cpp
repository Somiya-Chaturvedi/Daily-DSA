#include <iostream> // Required for input/output operations (e.g., cout)
#include <stack>    // Required for std::stack

// MyQueue class implements a FIFO queue using two stacks.
class MyQueue {
private:
    // inputStack is used to push new elements.
    std::stack<int> inputStack;
    // outputStack is used to pop and peek elements from the front of the queue.
    std::stack<int> outputStack;

    // Helper method to transfer elements from inputStack to outputStack.
    // This reverses the order of elements, preparing them for FIFO retrieval.
    // Time Complexity: O(N) where N is the number of elements in inputStack.
    // Space Complexity: O(1) auxiliary, as elements are just moved between stacks.
    void transferElements() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top()); // Get top element
            inputStack.pop();                   // Remove top element
        }
    }

public:
    // Constructor to initialize the queue.
    MyQueue() {
        // Stacks are automatically initialized when MyQueue object is created.
    }

    /**
     * Pushes element x to the back of the queue.
     * Time Complexity: O(1)
     * Space Complexity: O(1) (for the element itself)
     */
    void push(int x) {
        inputStack.push(x);
    }

    /**
     * Removes the element from the front of the queue and returns it.
     * If outputStack is empty, it transfers all elements from inputStack to outputStack
     * to reverse their order.
     * Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
     * Space Complexity: O(N) in worst case (all elements moved from input to output).
     */
    int pop() {
        // If outputStack is empty, transfer all elements from inputStack to it.
        if (outputStack.empty()) {
            transferElements();
        }
        // Get the top element from outputStack (which is the front of the queue).
        int frontElement = outputStack.top();
        // Pop and return the top element from outputStack.
        outputStack.pop();
        return frontElement;
    }

    /**
     * Returns the element at the front of the queue.
     * If outputStack is empty, it transfers all elements from inputStack to it.
     * Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
     * Space Complexity: O(N) in worst case (all elements moved from input to output).
     */
    int peek() {
        // If outputStack is empty, transfer all elements from inputStack to it.
        if (outputStack.empty()) {
            transferElements();
        }
        // Peek and return the top element from outputStack.
        return outputStack.top();
    }

    /**
     * Returns true if the queue is empty, false otherwise.
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool empty() {
        // The queue is empty if both inputStack and outputStack are empty.
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue myQueue;

    std::cout << "Operations and Outputs:\n";
    std::cout << "myQueue.push(1);\n";
    myQueue.push(1); // queue is: [1]
    std::cout << "Output: null (operation)\n";

    std::cout << "myQueue.push(2);\n";
    myQueue.push(2); // queue is: [1, 2] (front is 1)
    std::cout << "Output: null (operation)\n";

    std::cout << "myQueue.peek();\n";
    int peekResult = myQueue.peek(); // return 1
    std::cout << "Output: " << peekResult << "\n"; // Expected: 1

    std::cout << "myQueue.pop();\n";
    int popResult = myQueue.pop(); // return 1, queue is [2]
    std::cout << "Output: " << popResult << "\n"; // Expected: 1

    std::cout << "myQueue.empty();\n";
    bool isEmpty = myQueue.empty(); // return false
    std::cout << "Output: " << (isEmpty ? "true" : "false") << "\n"; // Expected: false

    std::cout << "\n--- Further Testing ---\n";
    std::cout << "myQueue.push(3);\n";
    myQueue.push(3);
    std::cout << "myQueue.push(4);\n";
    myQueue.push(4);
    std::cout << "myQueue.pop();\n";
    std::cout << "Output: " << myQueue.pop() << "\n"; // Expected: 2
    std::cout << "myQueue.peek();\n";
    std::cout << "Output: " << myQueue.peek() << "\n"; // Expected: 3
    std::cout << "myQueue.pop();\n";
    std::cout << "Output: " << myQueue.pop() << "\n"; // Expected: 3
    std::cout << "myQueue.empty();\n";
    std::cout << "Output: " << (myQueue.empty() ? "true" : "false") << "\n"; // Expected: false
    std::cout << "myQueue.pop();\n";
    std::cout << "Output: " << myQueue.pop() << "\n"; // Expected: 4
    std::cout << "myQueue.empty();\n";
    std::cout << "Output: " << (myQueue.empty() ? "true" : "false") << "\n"; // Expected: true

    return 0;
}
```

### Complexity Analysis:

* **`push(x)`:**
    * **Time Complexity:** $O(1)$
        * It involves a single push operation onto `inputStack`.
    * **Space Complexity:** $O(1)$ (for the element itself)
        * No additional auxiliary space proportional to `N` is used for this specific operation.

* **`pop()` and `peek()`:**
    * **Time Complexity:** $O(1)$ amortized.
        * In the worst case (when `outputStack` is empty), all $N$ elements from `inputStack` are transferred to `outputStack`. This takes $O(N)$ time. However, this full transfer operation happens only when `outputStack` is completely empty. Each element is pushed onto `inputStack` once, popped from `inputStack` once, pushed onto `outputStack` once, and popped from `outputStack` once. Thus, over a sequence of $N$ operations, each element undergoes a constant number of stack operations, leading to a total time of $O(N)$. Therefore, the average (amortized) time complexity per `pop` or `peek` operation is $O(1)$.
    * **Space Complexity:** $O(N)$
        * In the worst case, all $N$ elements could be stored across `inputStack` and `outputStack`. Thus, the space required is proportional to the number of elements in the que