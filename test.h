//
// Created by Лёня Кучук on 28.05.2024.
//

#ifndef LABMEPHI2_TEST_H
#define LABMEPHI2_TEST_H

#include "realization.h"
#include "vector.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <complex>


void ListTest(){
    int* arr = new int[5];
    for(int i = 0; i < 5; i++){
        arr[i] = i;
    }
    LinkedListSequence<int> list = LinkedListSequence<int>(arr, 5);
    for(int i = 0; i < 5; i++){
        assert(list[i] == arr[i]);
    }
    list.Append(5);
    assert(list[5] == 5);
    assert(list.Get(1) == 1);
    arr = new int[5];
    for(int i = 6; i < 11; i++){
        arr[i - 6] = i;
    }
    LinkedListSequence<int>* list2 = new LinkedListSequence<int>(arr, 5);
    Sequence<int>* result = list.Concat(list2);
    LinkedListSequence<int>* resultlist = dynamic_cast<LinkedListSequence<int>*>(result);
    for(int i = 0; i < 11; i++){
        assert(i == resultlist->Get(i));
    }
    resultlist->insertAt(1, 3);
    assert(resultlist->Get(3) == 1);
    assert(resultlist->GetLength() == 12);
    assert(resultlist->GetLast() == 10);
    assert(resultlist->GetFirst() == 0);
    resultlist->Prepend(10);
    assert(resultlist->GetFirst() == 10);
    resultlist = dynamic_cast<LinkedListSequence<int>*>(resultlist->GetSubsequence(10, 11));
    for(int i = 0; i < resultlist->GetLength(); i++){
        assert(i + 8 == resultlist->Get(i));
    }
}
void ArrayTest(){
    int* arr = new int[5];
    for(int i = 0; i < 5; i++){
        arr[i] = i + 1;
    }
    ArraySequence<int> array = ArraySequence<int>(arr, 5);
    for(int i = 0; i < 5; i++){
        assert(array[i] == arr[i]);
    }
    assert(array.GetLength() == 5);
    assert(array.GetFirst() == 1);
    assert(array.GetLast() == 5);
    array.Append(6);
    assert(array.Get(5) == 6);
    array.Set(5, 7);
    assert(array[5] == 7);
}
void VectorTestDouble(){
    double* arr = new double[5];
    for(int i = 0; i < 5; i++){
        arr[i] = i + 1;
    }
    Vector<double> array = Vector<double>(arr, 5);
    for(int i = 0; i < 5; i++){
        assert(array[i] == arr[i]);
    }
    assert(array.GetLength() == 5);
    assert(array.GetFirst() == 1);
    assert(array.GetLast() == 5);
    array.Append(6);
    assert(array.Get(5) == 6);
    array.Set(5, 7);
    assert(array[5] == 7);
    array.Reserve(10);
    assert(array.Capacity() == 10);
    array.Resize(1);
    assert(array.GetLast() == array.GetFirst());
    double* newarr = new double[5];
    for(int i = 0; i < 5; i++){
        newarr[i] = i + 1;
    }
    Vector<double> newarray = Vector<double>(newarr, 5);
    assert(newarray.Max() == 5);
    assert(newarray.Min() == 1);
    assert(int(newarray.Norm()) == int(7.4162));
    Vector<double>* filter = newarray.FilterPrime();
    assert(filter->Get(1) == 3);
    Vector<double> multiply = Vector<double>(*filter * 2.0);
    assert(multiply[1] == 6);
    Vector<double> plus = Vector<double>(*filter + multiply);
    assert(plus[1] == 9);
    Vector<double> minus = Vector<double>(plus - multiply);
    assert(minus[1] == 3);
    double multiplyvectors = plus * multiply;
    assert(multiplyvectors == 228);
}
void VectorTestComplex(){
    complex<double>* arr = new complex<double>[5];
    for(int i = 0; i < 5; i++){
        arr[i].real(i + 1);
        arr[i].imag(i + 2);
    }
    Vector<complex<double>> array = Vector<complex<double>>(arr, 5);
    for(int i = 0; i < 5; i++){
        assert(array[i] == arr[i]);
    }
    assert(array.GetLength() == 5);
    assert(array.GetFirst().real() == 1);
    assert(array.GetFirst().imag() == 2);
    assert(array.GetLast().real() == 5);
    assert(array.GetLast().imag() == 6);
    complex<double> value(6, 7);
    array.Append(value);
    assert(array.Get(5) == value);
    complex<double> newvalue(7, 8);
    array.Set(5, newvalue);
    assert(array[5] == newvalue);
    array.Reserve(10);
    assert(array.Capacity() == 10);
    array.Resize(1);
    assert(array.GetLast() == array.GetFirst());
    complex<double>* newarr = new complex<double>[5];
    for(int i = 0; i < 5; i++){
        newarr[i].real(i + 1);
        newarr[i].imag(i + 2);
    }
    Vector<complex<double>> newarray = Vector<complex<double>>(newarr, 5);
    assert(int(newarray.Norm().real()) == int(7.4162));
    assert(int(newarray.Norm().imag()) == int(9.4686));
}
void MainTest(){
    ListTest();
    ArrayTest();
    VectorTestDouble();
    VectorTestComplex();
}

#endif //LABMEPHI2_TEST_H
