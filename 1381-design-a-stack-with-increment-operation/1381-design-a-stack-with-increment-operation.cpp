class CustomStack {
private:
    // Vector to store stack elements
    vector<int> stackVector;

    // Index of the top element in the stack
    int topIndex;

public:
    CustomStack(int maxSize) {
        stackVector.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex < (int)(stackVector.size()) - 1) {
            stackVector[++topIndex] = x;
        }
    }

    int pop() {
        if (topIndex >= 0) {
            return stackVector[topIndex--];
        }
        return -1;  // Return -1 if the stack is empty
    }

    void increment(int k, int val) {
        int limit = min(k, topIndex + 1);
        for (int i = 0; i < limit; i++) {
            stackVector[i] += val;
        }
    }
};