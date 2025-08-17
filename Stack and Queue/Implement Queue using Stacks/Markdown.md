# Implement Queue using Stacks

## 🧠 Problem

Implement a first-in-first-out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `pop`, `peek`, and `empty`).

### Functions to Implement:

-   `push(x)`: Pushes element `x` to the back of the queue.
-   `pop()`: Removes the element from the front of the queue and returns it.
-   `peek()`: Returns the element at the front of the queue.
-   `empty()`: Returns `true` if the queue is empty, `false` otherwise.

### Examples:

**Example 1:**

Here is a well-formatted Markdown file for the "Implement Queue using Stacks" problem, with clear explanations for the question, approach, and complexities.

You can copy and paste this content directly into a new .md file in your repository (e.g., Daily-DSA/Stacks and Queues/implement-queue-using-stacks/problem_statement.md).

Markdown

# Implement Queue using Stacks

## 🧠 Problem

Implement a first-in-first-out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `pop`, `peek`, and `empty`).

### Functions to Implement:

-   `push(x)`: Pushes element `x` to the back of the queue.
-   `pop()`: Removes the element from the front of the queue and returns it.
-   `peek()`: Returns the element at the front of the queue.
-   `empty()`: Returns `true` if the queue is empty, `false` otherwise.

### Examples:

**Example 1:**
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue becomes: [1]
myQueue.push(2); // queue becomes: [1, 2] (front is 1)
myQueue.peek();  // returns 1
myQueue.pop();   // returns 1, queue becomes [2]
myQueue.empty(); // returns false

Here is a well-formatted Markdown file for the "Implement Queue using Stacks" problem, with clear explanations for the question, approach, and complexities.

You can copy and paste this content directly into a new `.md` file in your repository (e.g., `Daily-DSA/Stacks and Queues/implement-queue-using-stacks/problem_statement.md`).

```markdown
# Implement Queue using Stacks

## 🧠 Problem

Implement a first-in-first-out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `pop`, `peek`, and `empty`).

### Functions to Implement:

-   `push(x)`: Pushes element `x` to the back of the queue.
-   `pop()`: Removes the element from the front of the queue and returns it.
-   `peek()`: Returns the element at the front of the queue.
-   `empty()`: Returns `true` if the queue is empty, `false` otherwise.

### Examples:

**Example 1:**
```

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue becomes: [1]
myQueue.push(2); // queue becomes: [1, 2] (front is 1)
myQueue.peek();  // returns 1
myQueue.pop();   // returns 1, queue becomes [2]
myQueue.empty(); // returns false

```

---

## Constraints

-   `1 <= x <= 9` for `push` operation.
-   At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
-   All calls to `pop` and `peek` are guaranteed to be valid (i.e., the queue will not be empty when these operations are called).

---

## 💡 Approach

The core idea is to use two stacks: an `inputStack` and an `outputStack`.

-   `inputStack`: This stack is primarily used for adding new elements.
-   `outputStack`: This stack is used for removing (popping) and viewing (peeking) elements. The trick is that `outputStack` will always store elements in reverse order of `inputStack` for efficient FIFO operations.

### Breakdown of Operations:

1.  **`push(x)` operation:**
    * To add an element to the queue, we simply push `x` onto the `inputStack`. This is an $O(1)$ operation.

2.  **`pop()` operation:**
    * If the `outputStack` is empty, it means we need to "refill" it with elements from `inputStack` in the correct FIFO order. We achieve this by transferring all elements from `inputStack` to `outputStack`. As elements are popped from `inputStack` (LIFO) and pushed onto `outputStack`, their order is effectively reversed, making the oldest element of the original `inputStack` (which is the front of our conceptual queue) appear at the top of `outputStack`.
    * Once `outputStack` is not empty (after potential transfer), we simply pop and return its top element.

3.  **`peek()` operation:**
    * This is very similar to `pop()`. If `outputStack` is empty, we transfer all elements from `inputStack` to `outputStack` to ensure the front element is accessible.
    * Then, we return the top element of `outputStack` without removing it.

4.  **`empty()` operation:**
    * The queue is considered empty if and only if both `inputStack` and `outputStack` are empty.

---

## ⏱ Complexities

-   **Time Complexity:**
    * `push(x)`: $O(1)$ — This operation involves a single push onto `inputStack`.
    * `pop()` and `peek()`: $O(1)$ amortized.
        * While a single `pop` or `peek` operation might take $O(N)$ time in the worst case (when `outputStack` is empty and all $N$ elements from `inputStack` must be transferred), this transfer operation happens infrequently. Each element is pushed onto `inputStack` once and then popped from `inputStack` once and pushed onto `outputStack` once, and finally popped from `outputStack` once. Thus, over a sequence of $N$ operations, each element is moved at most a constant number of times, making the total time $O(N)$. Therefore, the amortized time complexity per `pop` or `peek` operation is $O(1)$.

-   **Space Complexity:** $O(N)$
    * Where $N$ is the total number of elements currently in the queue.
    * In the worst case, all elements might reside in `inputStack` (e.g., after several `push` operations but no `pop` or `peek`), or they might all be transferred to `outputStack`. So, the space required is proportional to the number of elements stored.
```