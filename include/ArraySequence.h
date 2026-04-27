#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"
#include <tuple>
#include <algorithm>
#include <functional>

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> data;
public:
    ArraySequence();
    ArraySequence(int size, T defaultValue);
    ArraySequence(T *items, int count);
    ArraySequence(const ArraySequence<T> &other);
    ArraySequence(const DynamicArray<T> &arr);
    ~ArraySequence() = default;
    
    ArraySequence<T> &operator=(const ArraySequence<T> &other);

    int GetLength() const override;
    T Get(int index) const override;

    void Set(int index, const T &item) override;
    void Append(const T &item) override;
    void Prepend(const T &item) override;
    void InsertAt(const T &item, int index) override;
    void RemoveAt(int index) override;

    T GetFirst() const override;
    T GetLast() const override;

    Sequence<T> *GetSubsequence(int startIndex, int endIndex) const override;

    T &operator[](int index) override;
    const T &operator[](int index) const override;


};

template<typename T>
ArraySequence<T>::ArraySequence() : data(DynamicArray<T>()) {}

template<typename T>
ArraySequence<T>::ArraySequence(int size, T defaultValue) : data(size, defaultValue) {}

template<typename T>
ArraySequence<T>::ArraySequence(T *items, int count) : data(DynamicArray<T>(items, count)) {}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &other) : data(DynamicArray<T>(other.data)) {}

template<typename T>
ArraySequence<T>::ArraySequence(const DynamicArray<T> &arr) : data(DynamicArray<T>(arr)) {}

template<typename T>
ArraySequence<T> &ArraySequence<T>::operator=(const ArraySequence<T> &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template<typename T>
int ArraySequence<T>::GetLength() const {
    return data.GetSize();
}

template<typename T>
T ArraySequence<T>::Get(int index) const {
    return data.Get(index);
}

template<typename T>
void ArraySequence<T>::Set(int index, const T &item) {
   data.Set(index, item);
}

template<typename T>
void ArraySequence<T>::Append(const T &item) {
    data.push_back(item);
}

template<typename T>
void ArraySequence<T>::Prepend(const T &item) {
    data.insert(0, item);
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &item, int index) {
    if (index < 0 || index > data.GetSize()) {
        throw IndexOutOFBoundsException("Index out of range");
    }
    data.insert(index, item);
}

template<typename T>
void ArraySequence<T>::RemoveAt(int index) {
    if (index < 0 || index > data.GetSize()) {
        throw IndexOutOFBoundsException("Index out of range");
    }
    data.erase(index);
}

template<typename T>
T ArraySequence<T>::GetFirst() const {
    if (GetLength() == 0) {
        throw SizeException("Empty array");
    }
    return data.Get(0);
}

template<typename T>
T ArraySequence<T>::GetLast() const {
    if (data.GetSize() == 0) {
        throw SizeException("Empty array");
    }
    return data.Get(data.GetSize() - 1);
}

template<typename T>
Sequence<T> *ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= GetLength() || startIndex > endIndex) {
        throw IndexOutOFBoundsException("Indexes out of range");
    }
    auto *result = new ArraySequence<T>();
    for (int i = startIndex; i <= endIndex; i++) {
        result->Append(data[i]);
    }
    return result;
}

#endif // ARRAYSEQUENCE_H