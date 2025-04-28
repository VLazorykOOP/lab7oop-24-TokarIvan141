#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int size);
    Array(const Array& other);
    ~Array();

    T& operator[](int index);
    Array& operator=(const Array& other);

    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);

    Array operator-(const Array& other) const;
    Array& operator-=(const Array& other);

    int getSize() const;
    void print() const;
};

template <typename T>
Array<T>::Array(int size) : size(size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) data[i] = T();
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) data[i] = other.data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](int index) {
    return data[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array& other) const {
    Array result(size);
    for (int i = 0; i < size; ++i) result.data[i] = this->data[i] + other.data[i];
    return result;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
    for (int i = 0; i < size; ++i) data[i] += other.data[i];
    return *this;
}

template <typename T>
Array<T> Array<T>::operator-(const Array& other) const {
    Array result(size);
    for (int i = 0; i < size; ++i) result.data[i] = this->data[i] - other.data[i];
    return result;
}

template <typename T>
Array<T>& Array<T>::operator-=(const Array& other) {
    for (int i = 0; i < size; ++i) data[i] -= other.data[i];
    return *this;
}

template <typename T>
int Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::print() const {
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;
}

#endif
