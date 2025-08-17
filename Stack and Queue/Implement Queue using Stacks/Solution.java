import java.util.Stack; // Required for using the Stack data structure

// MyQueue class implements a FIFO queue using two stacks.
class MyQueue {
    // inputStack is used to push new elements.
    private Stack<Integer> inputStack;
    // outputStack is used to pop and peek elements from the front of the queue.
    private Stack<Integer> outputStack;

    // Constructor to initialize the queue.
    public MyQueue() {
        inputStack = new Stack<>();
        outputStack = new Stack<>();
    }

    /**
     * Pushes element x to the back of the queue.
     * Time Complexity: O(1)
     * Space Complexity: O(1) (for the element itself)
     */
    public void push(int x) {
        inputStack.push(x);
    }

    /**
     * Removes the element from the front of the queue and returns it.
     * If outputStack is empty, it transfers all elements from inputStack to outputStack
     * to reverse their order.
     * Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
     * Space Complexity: O(N) in worst case (all elements moved from input to output).
     */
    public int pop() {
        // If outputStack is empty, transfer all elements from inputStack to it.
        if (outputStack.empty()) {
            transferElements();
        }
        // Pop and return the top element from outputStack (which is the front of the queue).
        return outputStack.pop();
    }

    /**
     * Returns the element at the front of the queue.
     * If outputStack is empty, it transfers all elements from inputStack to it.
     * Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
     * Space Complexity: O(N) in worst case (all elements moved from input to output).
     */
    public int peek() {
        // If outputStack is empty, transfer all elements from inputStack to it.
        if (outputStack.empty()) {
            transferElements();
        }
        // Peek and return the top element from outputStack.
        return outputStack.peek();
    }

    /**
     * Returns true if the queue is empty, false otherwise.
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public boolean empty() {
        // The queue is empty if both inputStack and outputStack are empty.
        return inputStack.empty() && outputStack.empty();
    }

    // Helper method to transfer elements from inputStack to outputStack.
    // This reverses the order of elements, preparing them for FIFO retrieval.
    private void transferElements() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.pop());
        }
    }

    public static void main(String[] args) {
        MyQueue myQueue = new MyQueue();

        System.out.println("Operations and Outputs:");
        System.out.println("myQueue.push(1);");
        myQueue.push(1); // queue is: [1]
        System.out.println("Output: null (operation)");

        System.out.println("myQueue.push(2);");
        myQueue.push(2); // queue is: [1, 2] (front is 1)
        System.out.println("Output: null (operation)");

        System.out.println("myQueue.peek();");
        int peekResult = myQueue.peek(); // return 1
        System.out.println("Output: " + peekResult); // Expected: 1

        System.out.println("myQueue.pop();");
        int popResult = myQueue.pop(); // return 1, queue is [2]
        System.out.println("Output: " + popResult); // Expected: 1

        System.out.println("myQueue.empty();");
        boolean isEmpty = myQueue.empty(); // return false
        System.out.println("Output: " + isEmpty); // Expected: false

        System.out.println("\n--- Further Testing ---");
        System.out.println("myQueue.push(3);");
        myQueue.push(3);
        System.out.println("myQueue.push(4);");
        myQueue.push(4);
        System.out.println("myQueue.pop();");
        System.out.println("Output: " + myQueue.pop()); // Expected: 2
        System.out.println("myQueue.peek();");
        System.out.println("Output: " + myQueue.peek()); // Expected: 3
        System.out.println("myQueue.pop();");
        System.out.println("Output: " + myQueue.pop()); // Expected: 3
        System.out.println("myQueue.empty();");
        System.out.println("Output: " + myQueue.empty()); // Expected: false
        System.out.println("myQueue.pop();");
        System.out.println("Output: " + myQueue.pop()); // Expected: 4
        System.out.println("myQueue.empty();");
        System.out.println("Output: " + myQueue.empty()); // Expected: true
    }
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