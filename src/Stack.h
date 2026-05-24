// A place for triggered abilities to go.
// Uses a LIFO stack, implemented as a vector
// The game object has one of these

#ifndef STACK_H
#define STACK_H

#include <vector>
#include "Trigger.h"

class Stack {
private:
    std::vector<Trigger> stack;
public:
    Stack();
    ~Stack();
    void push(Trigger);
    void push(std::vector<Trigger>);
    void resolveTop();
};
#endif