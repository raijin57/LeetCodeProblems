//
// Created by arsen on 19.11.2025.
//
#include <queue>
class MyQueue {
    std::queue<int> pushQueue;
    std::queue<int> popQueue;
public:
    MyQueue() {}

    void push(int x) {
        pushQueue.push(x);
    }

    int pop() {
        if (popQueue.empty()) {
            refill();
        }
        const int temp = popQueue.front();
        popQueue.pop();
        return temp;
    }

    int peek() {
        if (popQueue.empty()) {
            refill();
        }
        return popQueue.front();
    }

    bool empty() {
        return popQueue.empty() && pushQueue.empty();
    }

    void refill() {
        while (!pushQueue.empty()) {
            popQueue.push(pushQueue.front());
            pushQueue.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */