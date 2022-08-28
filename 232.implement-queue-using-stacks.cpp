/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> tmp;
        while(!s_.empty()) {
            tmp.push(s_.top());
            s_.pop();
        }

        s_.push(x);

        while(!tmp.empty()) {
            s_.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int tmp = s_.top();
        s_.pop();
        return tmp;
    }
    
    int peek() {
        return s_.top();
    }
    
    bool empty() {
        return s_.empty();
    }
private:
 stack<int> s_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

