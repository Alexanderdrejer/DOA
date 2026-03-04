#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "stack_class.h"

template <typename Object>
class Queue {
  private:
    Stack<Object> inStack; 
    Stack<Object> outStack;
    //Vi bruger 2 stacks for at fordele arbejdet. Mens den anden stack kan vende rækkefølgen om, så vi FIFO-princippet
    //fra en queue. Vi sikrer altså O(1) oftest, da tilføjelsen er hurtigt og delete er hurtig. Skulle inStack have 1000 elementer
    // løber 

    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.pop());
            }
        }
    }

  public:
    Queue() {}

    ~Queue() {}

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

    Object front() {
        transferIfNeeded();
        return outStack.top();
    }

    Object get() {
        transferIfNeeded();
        return outStack.pop();
    }

    void put(const Object x) {
        inStack.push(x);
    }
};

#endif