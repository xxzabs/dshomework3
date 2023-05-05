#include <iostream>
#include "../vector/vector1.h" 
#include <stdexcept>

template<typename T>
class Queue
{
protected:
    //默认构造函数，在初始化时创建一个空队列
    Queue() {}

    //将元素item入队
    void enqueue(const T& item)
    {
        data_.push_back(item);
    }

    //将队首元素出队并返回其值；如果队列为空，则抛出std::out_of_range异常
    T dequeue()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::dequeue(): queue is empty");
        }
        T item = data_.front();
        data_.erase(data_.begin());
        return item;
    }

    //返回队首元素的值；如果队列为空，则抛出std::out_of_range异常
    T& front()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::front(): queue is empty");
        }
        return data_.front();
    }

    //返回队尾元素的值；如果队列为空，则抛出std::out_of_range异常
    T& back()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::back(): queue is empty");
        }
        return data_.back();
    }

    //返回队列中元素的个数
    size_t size() const
    {
        return data_.size();
    }

    //返回一个布尔值，表示队列是否为空
    bool empty() const
    {
        return data_.empty();
    }

private:
    std::vector<T> data_;
};



