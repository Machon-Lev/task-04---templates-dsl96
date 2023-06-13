#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
class PriorityQueue {
public:
    void push(const T& t);
    T poll();

private:
    std::list<T> data;

     
    struct MyComparator {
        bool operator()(const T& a, const T& b) const {
            return a - b < 0;
        }
    };
};

template<typename T>
void PriorityQueue<T>::push(const T& t) {
    typename std::list<T>::iterator it = data.begin();
    while (it != data.end() && MyComparator()(*it, t)) {
        ++it;
    }
    data.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll() {
    if (data.empty()) {
        throw std::out_of_range("PriorityQueue is empty !");
    }
    T top = data.front();
    data.pop_front();
    return top;
}
