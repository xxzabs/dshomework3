#include <iostream>
#include "../vector/vector1.h" 
#include <stdexcept>

template<typename T>
class Queue
{
protected:
    //Ĭ�Ϲ��캯�����ڳ�ʼ��ʱ����һ���ն���
    Queue() {}

    //��Ԫ��item���
    void enqueue(const T& item)
    {
        data_.push_back(item);
    }

    //������Ԫ�س��Ӳ�������ֵ���������Ϊ�գ����׳�std::out_of_range�쳣
    T dequeue()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::dequeue(): queue is empty");
        }
        T item = data_.front();
        data_.erase(data_.begin());
        return item;
    }

    //���ض���Ԫ�ص�ֵ���������Ϊ�գ����׳�std::out_of_range�쳣
    T& front()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::front(): queue is empty");
        }
        return data_.front();
    }

    //���ض�βԪ�ص�ֵ���������Ϊ�գ����׳�std::out_of_range�쳣
    T& back()
    {
        if (data_.empty()) {
            throw std::out_of_range("Queue<>::back(): queue is empty");
        }
        return data_.back();
    }

    //���ض�����Ԫ�صĸ���
    size_t size() const
    {
        return data_.size();
    }

    //����һ������ֵ����ʾ�����Ƿ�Ϊ��
    bool empty() const
    {
        return data_.empty();
    }

private:
    std::vector<T> data_;
};



