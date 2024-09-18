//
// Created by Лёня Кучук on 29.05.2024.
//

#ifndef LABMEPHI2_VECTOR_H
#define LABMEPHI2_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "realization.h"
#include <complex>

template<typename T>
class Vector : Sequence<T>{
private:
    size_t capacity_, size_;
    T* arr_;
public:
    Vector() : capacity_(2), size_(0), arr_(new T[2]){}
    Vector(T* arr, size_t size) : capacity_(size * 2), size_(size), arr_(new T[capacity_]){
        for(size_t i = 0; i < size; i++){
            arr_[i] = arr[i];
        }
    }
    Vector(vector<T>& arr) : capacity_(arr.size() * 2), size_(arr.size()), arr_(new T[capacity_]){
        for(size_t i = 0; i < arr.size(); i++){
            arr_[i] = arr[i];
        }
    }
    Vector(const Vector<T>& arr) : capacity_(arr.capacity_), size_(arr.size_), arr_(new T[capacity_]){
        for(size_t i = 0; i < arr.size_; i++){
            arr_[i] = arr.arr_[i];
        }
    }
    ~Vector() override{
        delete arr_;
    }
    void Reserve(int new_capacity){
        capacity_ = new_capacity;
        T* newarray_ = new T[capacity_];
        for(int i = 0; i < min(size_, capacity_); i++){
            newarray_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = newarray_;
    }
    void Resize(int new_size){
        size_ = new_size;
        if(size_ > capacity_){
            Reserve(size_ * 2);
        }
    }
    int GetLength() override{
        return size_;
    }
    size_t Capacity(){
        return capacity_;
    }
    T Get(int i) override{
        return arr_[i];
    }
    void Set(int i, T value){
        arr_[i] = value;
    }
    void Append(T value) override{
        if(size_ == capacity_){
            Reserve(capacity_ * 2);
        }
        size_++;
        arr_[size_ - 1] = value;
    }
    T GetFirst() override{
        if(size_ == 0) throw out_of_range("SizeZero");
        return arr_[0];
    }
    T GetLast() override{
        if(size_ == 0) throw out_of_range("SizeZero");
        return arr_[size_ - 1];
    }
    T Max(){
        T result = arr_[0];
        for(size_t i = 1; i < size_; i++){
            if(result < arr_[i]){
                result = arr_[i];
            }
        }
        return result;
    }
    T Min(){
        T result = arr_[0];
        for(size_t i = 1; i < size_; i++){
            if(result > arr_[i]){
                result = arr_[i];
            }
        }
        return result;
    }
    T Norm(){
        T result = 0;
        for(size_t i = 0; i < size_; i++){
            result+=arr_[i]*arr_[i];
        }
        return sqrt(result);
    }
    Vector<T>* FilterPrime(){
        size_t size = max(int(Max()) + 1, 2);
        Vector<T>* result = new Vector<T>();
        bool* matrix = new bool[size];
        for(size_t i = 0; i < size; i++){
            matrix[i] = 1;
        }
        matrix[0] = 0;
        matrix[1] = 0;
        for(size_t i = 2; i < size; i++){
            if(matrix[i]){
                for(size_t j = i * 2; j < size; j+=i){
                    matrix[j] = 0;
                }
            }
        }
        for(size_t i = 0; i < size_; i++){
            if(int(arr_[i]) == arr_[i]) {
                if (matrix[size_t(arr_[i])]) {
                    result->Append(arr_[i]);
                }
            }
        }
        return result;
    }
    T& operator[](size_t index) override{
        if(index >= size_) throw out_of_range("IndexOutOfRange");
        return arr_[index];
    }
    Vector<T>& operator*(T value){
        T* arr = new T[size_];
        for(size_t i = 0; i < size_; i++){
            arr[i] = arr_[i] * value;
        }
        auto* result = new Vector<T>(arr, size_);
        return *result;
    }
    Vector<T>& operator+(Vector<T>& arr){
        if(arr.size_ != size_) throw out_of_range("DifferentSize");
        T* ar = new T[size_];
        for(size_t i = 0; i < size_; i++){
            ar[i] = arr_[i] + arr.arr_[i];
        }
        auto* result = new Vector<T>(ar, size_);
        return *result;
    }
    Vector<T>& operator-(Vector<T>& arr){
        if(arr.size_ != size_) throw out_of_range("DifferentSize");
        T* ar = new T[size_];
        for(size_t i = 0; i < size_; i++){
            ar[i] = arr_[i] - arr.arr_[i];
        }
        auto* result = new Vector<T>(ar, size_);
        return *result;
    }
    T operator*(Vector<T>& arr){
        if(arr.size_ != size_) throw out_of_range("DifferentSize");
        T result;
        for(size_t i = 0; i < size_; i++){
            result+=arr_[i]*arr.arr_[i];
        }
        return result;
    }
};

#endif //LABMEPHI2_VECTOR_H
