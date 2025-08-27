#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Two queues

public:
    MyStack() {}

    void push(int x) {
        q2.push(x); // Push into q2
        while (!q1.empty()) {
            q2.push(q1.front()); // Transfer all elements
            q1.pop();
        }
        swap(q1, q2); // Swap q1 and q2
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
