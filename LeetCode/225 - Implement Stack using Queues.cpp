class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        tq = q;
        while (!q.empty())
            q.pop();
        q.push(x);
        while (!tq.empty()) {
            int tmp = tq.front();
            tq.pop();
            q.push(tmp);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }

private:
    queue<int> q, tq;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
