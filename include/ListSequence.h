#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"
#include <functional>

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> data;
public:
    ListSequence();
    ListSequence(int size, T defaultValue);
    ListSequence(T *items, int count);
    ListSequence(const ListSequence<T> &other);
    ListSequence(const LinkedList<T> &list);
    ~ListSequence() = default;

    ListSequence<T> &operator=(const ListSequence<T> &other);

    int GetLength() const override;
    T Get(int index) const override;
    T GetFirst() const override;
    T GetLast() const override;

    void Set(int index, const T &item) override;
    void Append(const T &item) override;
    void Prepend(const T &item) override;
    void InsertAt(const T &item, int index) override;
    void RemoveAt(int index) override;
};

template<typename T>
ListSequence<T>::ListSequence() : data(LinkedList<T>()) {}

template<typename T>
ListSequence<T>::ListSequence(int size, T defaultValue) {
    for (int i = 0; i < size; i++) {
        Append(defaultValue);
    }
}

template<typename T>
ListSequence<T>::ListSequence(T *items, int count) : data(LinkedList<T>(items, count)) {}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence<T> &other) : data(LinkedList<T>(other.data)) {}

template<typename T>
ListSequence<T>::ListSequence(const LinkedList<T> &list) : data(LinkedList<T>(list)) {}

template<typename T>
ListSequence<T> &ListSequence<T>::operator=(const ListSequence<T> &other) {
    if (this != &other){
        data = other.data;
    }
    return *this;
}

template<typename T>
int ListSequence<T>::GetLength() const {
    return data.GetLength();
}

template<typename T>
T ListSequence<T>::Get(int index) const {
    if(index < 0 || index >= GetLength()){
        throw IndexOutOFBoundsException("Index out of range");
    }
    return data.Get(index);
}

template<typename T>
T ListSequence<T>::GetFirst() const {
    if(GetLenght() == 0){
        throw SizeException("Empty list");
    }
    return data.GetFirst();
}

template<typename T>
T ListSequence<T>::GetLast() const {
    if(GetLenght() == 0){
        throw SizeException("Empty list");
    }
    return data.GetLast();
}

template<typename T>
void ListSequence<T>::Set(int index, const T &item){
    if(index < 0 || index >= GetLength()){
        throw IndexOutOFBoundsException("Index out of range");
    }
    LinkedList<T> newList;
    for(int i = 0; i < index; i++){
        newList.push_back(data.Get(i));
    }
    newList.push_back(item);
    for(int i = index + 1; i < GetLength(); i++){
        newList.push_back(data.Get(i));
    }
    data = newList;
}

template<typename T>
void ListSequence<T>::Append(const T &item){
    data.push_back(item);
}

template<typename T>
void ListSequence<T>::Prepend(const T &item){
    data.push_front(item);
}

template<typename T>
void ListSequence<T>::InsertAt(const T &item, int index){
    if(index < 0 || index >= data.GetLength()){
        throw IndexOutOFBoundsException("Index out of range");
    }
    data.insertAt(item, index);
}

template<typename T>
void ListSequence<T>::RemoveAt(int index){
    if(index < 0 || index >= data.GetLength()){
        throw IndexOutOFBoundsException("Index out of range");
    }
    LinkedList<T> newList;
    for(int i = 0; i < index; i++){
        newList.push_back(data.Get(i));
    }
    for(int i = index + 1; i < GetLength; i++){
        newList.push_back(data.Get(i));
    }
    data = newList;
}

#endif // LISTSEQUENCE_H