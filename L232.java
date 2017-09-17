class MyQueue {
    // Push element x to the back of queue.
    private Stack<Integer> s1 = new Stack<>();
    private Stack<Integer> s2 = new Stack<>();
    public void push(int x) {
        s2.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        if (s1.isEmpty()) {
            while (!s2.isEmpty()) s1.push(s2.pop());
        }
        s1.pop();
    }

    // Get the front element.
    public int peek() {
        if (s1.isEmpty()) {
            while (!s2.isEmpty()) s1.push(s2.pop());
        }
        return s1.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}