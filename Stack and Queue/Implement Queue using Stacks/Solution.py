# Python Solution for Implement Queue using Stacks

class MyQueue:
    def __init__(self):
        # input_stack is used to push new elements.
        self.input_stack = []
        # output_stack is used to pop and peek elements from the front of the queue.
        self.output_stack = []

    def _transfer_elements(self):
        """
        Helper method to transfer elements from input_stack to output_stack.
        This reverses the order of elements, preparing them for FIFO retrieval.
        Time Complexity: O(N) where N is the number of elements in input_stack.
        Space Complexity: O(1) auxiliary, as elements are just moved between stacks.
        """
        while self.input_stack:
            self.output_stack.append(self.input_stack.pop())

    def push(self, x: int) -> None:
        """
        Pushes element x to the back of the queue.
        Time Complexity: O(1)
        Space Complexity: O(1) (for the element itself)
        """
        self.input_stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from the front of the queue and returns it.
        If output_stack is empty, it transfers all elements from input_stack to output_stack
        to reverse their order.
        Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
        Space Complexity: O(N) in worst case (all elements moved from input to output).
        """
        # If output_stack is empty, transfer all elements from input_stack to it.
        if not self.output_stack:
            self._transfer_elements()
        # Pop and return the last element from output_stack (which is the front of the queue).
        return self.output_stack.pop()

    def peek(self) -> int:
        """
        Returns the element at the front of the queue.
        If output_stack is empty, it transfers all elements from input_stack to it.
        Time Complexity: O(1) amortized. Worst case O(N) if transfer is needed.
        Space Complexity: O(N) in worst case (all elements moved from input to output).
        """
        # If output_stack is empty, transfer all elements from input_stack to it.
        if not self.output_stack:
            self._transfer_elements()
        # Peek and return the last element from output_stack without removing it.
        return self.output_stack[-1]

    def empty(self) -> bool:
        """
        Returns true if the queue is empty, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(1)
        """
        # The queue is empty if both input_stack and output_stack are empty.
        return not self.input_stack and not self.output_stack


if __name__ == "__main__":
    my_queue = MyQueue()

    print("Operations and Outputs:")
    print("my_queue.push(1);")
    my_queue.push(1) # queue is: [1]
    print("Output: null (operation)")

    print("my_queue.push(2);")
    my_queue.push(2) # queue is: [1, 2] (front is 1)
    print("Output: null (operation)")

    print("my_queue.peek();")
    peek_result = my_queue.peek() # return 1
    print(f"Output: {peek_result}") # Expected: 1

    print("my_queue.pop();")
    pop_result = my_queue.pop() # return 1, queue is [2]
    print(f"Output: {pop_result}") # Expected: 1

    print("my_queue.empty();")
    is_empty = my_queue.empty() # return false
    print(f"Output: {is_empty}") # Expected: False

    print("\n--- Further Testing ---")
    print("my_queue.push(3);")
    my_queue.push(3)
    print("my_queue.push(4);")
    my_queue.push(4)
    print("my_queue.pop();")
    print(f"Output: {my_queue.pop()}") # Expected: 2
    print("my_queue.peek();")
    print(f"Output: {my_queue.peek()}") # Expected: 3
    print("my_queue.pop();")
    print(f"Output: {my_queue.pop()}") # Expected: 3
    print("my_queue.empty();")
    print(f"Output: {my_queue.empty()}") # Expected: False
    print("my_queue.pop();")
    print(f"Output: {my_queue.pop()}") # Expected: 4
    print("my_queue.empty();")
    print(f"Output: {my_queue.empty()}") # Expected: True
```

### Complexity Analysis:

* **`push(x)`:**
    * **Time Complexity:** $O(1)$
        * It involves a single `append` operation onto `input_stack`, which is typically $O(1)$ for Python lists.
    * **Space Complexity:** $O(1)$ (for the element itself)
        * No additional auxiliary space proportional to `N` is used for this specific operation.

* **`pop()` and `peek()`:**
    * **Time Complexity:** $O(1)$ amortized.
        * In the worst case (when `output_stack` is empty), all $N$ elements from `input_stack` are transferred to `output_stack`. This takes $O(N)$ time. However, this full transfer operation happens only when `output_stack` is completely empty. Each element is pushed onto `input_stack` once, popped from `input_stack` once, pushed onto `output_stack` once, and finally popped from `output_stack` once. Thus, over a sequence of $N$ operations, each element undergoes a constant number of stack operations, leading to a total time of $O(N)$. Therefore, the average (amortized) time complexity per `pop` or `peek` operation is $O(1)$.
    * **Space Complexity:** $O(N)$
        * In the worst case, all $N$ elements could be stored across `input_stack` and `output_stack`. Thus, the space required is proportional to the number of elements in the que