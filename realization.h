//
// Created by Лёня Кучук on 28.05.2024.
//

#ifndef LABMEPHI2_REALIZATION_H
#define LABMEPHI2_REALIZATION_H

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T>
class DynamicArray{
private:
    int capacity_, size_;
    T* array_;
    void reserve(int new_capacity){
        capacity_ = new_capacity;
        T* newarray_ = new T[capacity_];
        for(int i = 0; i < size_; i++){
            newarray_[i] = array_[i];
        }
        delete[] array_;
        array_ = newarray_;
    }
public:
    DynamicArray() : size_(0), capacity_(2), array_(new T[2]){}
    DynamicArray(T* array, int count) : size_(count), capacity_(count * 2), array_(new T[capacity_]){
        for(int i = 0; i < size_; i++){
            array_[i] = array[i];
        }
    }
    DynamicArray(const DynamicArray<T> &array) : size_(array.size_), capacity_(array.capacity_), array_(new T[capacity_]){
        for(size_t i = 0; i < array.size_; i++){
            array_[i] = array.array_[i];
        }
    }
    DynamicArray(int size) : size_(size), capacity_(size * 2), array_(new T[capacity_]){}
    ~DynamicArray(){
        delete[] array_;
        array_ = nullptr;
    }
    T& Get(int index){
        if(index >= size_ || index < 0) throw out_of_range("IndexOutOfRange");
        return array_[index];
    }
    int GetSize(){
        return size_;
    }
    void Add(T value){
        if(size_ == capacity_){
            reserve(capacity_ * 2);
        }
        size_++;
        array_[size_ - 1] = value;
    }
    void Set(int index, T value){
        array_[index] = value;
    }
    T& operator[](size_t index) {
        if(index >= size_) throw out_of_range("IndexOutOfRange");
        return array_[index];
    }
};

template<typename T>
class Node{
public:
    T value_;
    Node* next_;
    Node(T value) : value_(value), next_(nullptr){}
    Node* GetNext(){
        return next_;
    }
    T& GetValue(){
        return value_;
    }
};

template<typename T>
class LinkedList{
private:
    Node<T>* first_;
    Node<T>* last_;
    size_t size_;
public:
    LinkedList(T* items, int count) : first_(new Node<T>(items[0])), last_(first_), size_(count) {
        if (count > 1) {
            Node<T>* now;
            Node<T>* pred = first_;
            for (int i = 1; i < count; i++) {
                now = new Node<T>(items[i]);
                last_ = now;
                pred->next_ = now;
                pred = now;
            }
            last_->next_ = nullptr;
        }
        else {
            first_->value_ = items[0];
            first_->next_ = nullptr;
            last_ = first_;
        }
    }
    LinkedList() : first_(nullptr), last_(nullptr), size_(0) {}
    LinkedList(const LinkedList<T>& list) : first_(nullptr), last_(nullptr), size_(0) {
        if (list.size_ > 0) {
            first_ = new Node<T>(list.first_->value_);
            Node<T>* current = first_;
            Node<T>* listCurrent = list.first_->next_;
            while (listCurrent != nullptr) {
                current->next_ = new Node<T>(listCurrent->value_);
                current = current->next_;
                listCurrent = listCurrent->next_;
            }
            last_ = current;
            size_ = list.size_;
        }
    }
    ~LinkedList() {
        Node<T>* now = first_;
        Node<T>* next;
        while (now != nullptr) {
            next = now->next_;
            delete now;
            now = next;
        }
    }
    T GetFirst(){
        if(size_ == 0) throw out_of_range("IndexOutOfRange");
        return first_->value_;
    }
    T GetLast(){
        if(size_ == 0) throw out_of_range("IndexOutOfRange");
        return last_->value_;
    }
    T& Get(int index){
        if(index >= size_ || index < 0) throw out_of_range("IndexOutOfRange");
        Node<T>* now = first_;
        for(int i = 0; i < index; i++){
            now = now->next_;
        }
        return now->value_;
    }
    T& operator[](size_t index) {
        if(index >= size_) throw out_of_range("IndexOutOfRange");
        Node<T>* now = first_;
        for(int i = 0; i < index; i++){
            now = now->next_;
        }
        return now->value_;
    }
    LinkedList<T> *GetSubList(int startIndex, int endIndex){
        if(startIndex < 0 || startIndex >= size_ || endIndex <= startIndex || endIndex >= size_) throw out_of_range("IndexOutOfRange");
        T* items = new T[endIndex - startIndex + 1];
        Node<T>* newfirst = first_;
        for(int i = 0; i < startIndex; i++){
            newfirst = newfirst->GetNext();
        }
        Node<T>* newend = newfirst;
        for(int i = startIndex; i < endIndex; i++){
            items[i - startIndex] = newend->GetValue();
            newend = newend->GetNext();
        }
        items[endIndex - startIndex] = newend->GetValue();
        LinkedList<T>* list = new LinkedList<T>(items, endIndex - startIndex + 1);
        delete[] items;
        return list;
    }
    int GetLength(){
        return size_;
    }
    void Append(T item){
        if(size_ == 0){
            first_ = new Node(item);
            last_ = first_;
        }
        else{
            Node<T>* newnode = new Node(item);
            Node<T>* peref = last_;
            last_->next_ = newnode;
            last_ = newnode;
        }
        size_++;
    }
    void Prepend(T item){
        Node<T>* newnode = new Node(item);
        newnode->next_ = first_;
        first_ = newnode;
        size_++;
    }
    void InsertAt(T item, int index){
        if(index > size_ || index < 0) throw out_of_range("IndexOutOfRange");
        Node<T>* now = first_;
        Node<T>* pred;
        if(index == 0){
            pred = new Node(item);
            pred->next_ = now;
            first_ = pred;
            size_++;
            return;
        }
        while (now->next_ != nullptr){
            if(index == 0){
                pred->next_ = new Node(item);
                pred->next_->next_ = now;
                size_++;
                return;
            }
            pred = now;
            now = now->next_;
            index--;
        }
        now->next_ = new Node(item);
        size_++;
    }
    LinkedList<T>* Concat(LinkedList<T>* list) {
        auto* newlist = new LinkedList<T>(*this);
        Node<T>* now = list->first_;
        while (now != nullptr) {
            newlist->Append(now->value_);
            now = now->GetNext();
        }
        return newlist;
    }
};

template<typename T>
class Sequence{
public:
    virtual ~Sequence(){}
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual T& operator[](size_t index) = 0;
};

template<typename T>
class ArraySequence : public Sequence<T>{
private:
    DynamicArray<T>* array_;
public:
    ArraySequence(T* items, int count) : array_(new DynamicArray<T>(items, count)){}
    ArraySequence() : array_(new DynamicArray<T>()){}
    ArraySequence(DynamicArray<T>* arr){
        array_ = new DynamicArray<T>(arr->GetSize());
        for(size_t i = 0; i < arr->GetSize(); i++){
            array_->Set(i, arr->Get(i));
        }
    }
    ArraySequence(const ArraySequence& array) : array_(DynamicArray<T>(array)){}
    ~ArraySequence() override{
        delete array_;
    }
    T GetFirst() override{
        return array_->Get(0);
    }
    T GetLast() override{
        return array_->Get(array_->GetSize() - 1);
    }
    T Get(int index) override{
        return array_->Get(index);
    }
    void Set(int index, T item) {
        array_->Set(index, item);
    }
    int GetLength() override{
        return array_->GetSize();
    }
    void Append(T item) override{
        array_->Add(item);
    }
    T& operator[](size_t index) override{
        return array_->Get(index);
    }
};

template<typename T>
class LinkedListSequence : public Sequence<T>{
private:
    LinkedList<T>* list_;
public:
    LinkedListSequence(T* items, int count) : list_(new LinkedList<T>(items, count)) {}
    LinkedListSequence() : list_(new LinkedList<T>()) {}
    LinkedListSequence(LinkedList<T>* list) : list_(new LinkedList<T>(*list)) {}
    LinkedListSequence(const LinkedListSequence& list) : list_(new LinkedList<T>(*list.list_)) {}
    ~LinkedListSequence() override {
        delete list_;
    }
    T GetFirst() override{
        return list_->GetFirst();
    }
    T GetLast() override{
        return list_->GetLast();
    }
    T Get(int index) override{
        return list_->Get(index);
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex){
        Sequence<T>* newlist = new LinkedListSequence<T>(list_->GetSubList(startIndex, endIndex));
        return newlist;
    }
    int GetLength() override{
        return list_->GetLength();
    }
    void Append(T item) override{
        list_->Append(item);
    }
    void Prepend(T item) {
        list_->Prepend(item);
    }
    void insertAt(T item, int index) {
        list_->InsertAt(item, index);
    }
    LinkedListSequence<T>* Concat(LinkedListSequence<T>* list) {
        auto* newlist = dynamic_cast<LinkedListSequence<T>*>(list);
        return new LinkedListSequence<T>(list_->Concat(newlist->list_));
    }
    T& operator[](size_t index) override{
        return list_->Get(index);
    }
};


#endif //LABMEPHI2_REALIZATION_H
