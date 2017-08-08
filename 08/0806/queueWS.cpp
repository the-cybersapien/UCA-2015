#include <iostream>
#include <stack>

using namespace std;

template<class T>
class queue {

    stack<T> front;
    stack<T> back;

public:
    void push(T e) {
        front.push(e);
    }

    T pop() {
        while (!front.empty()) {
            back.push(front.top());
            front.pop();
        }
        T ret = back.top();
        back.pop();
        return ret;
    }

    T peek() {
        while (!front.empty()) {
            back.push(front.top());
            front.pop();
        }
        return back.top();
    }

    bool isEmpty() {
    	// queue is empty only if both the stacks are empty.
        return front.empty() && back.empty();
    }
};

template<class T>
void printQ(queue<T> q) {
    while (!q.isEmpty()) {
        cout << q.pop() << " ";
    }
    cout << endl;
}

int main() {

    queue<int> q;
    q.push(5);
    q.push(33);
    q.push(3333);
    q.push(3);
    printQ(q);
}
