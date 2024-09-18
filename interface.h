//
// Created by Лёня Кучук on 28.05.2024.
//

#include "realization.h"
#include "vector.h"
#include <iostream>
#include <stdexcept>
#include <vector>

#ifndef LABMEPHI2_INTERFACE_H
#define LABMEPHI2_INTERFACE_H

void startinterface(){
    cout << "1 - work with array\n2 - work with list\n3 - work with vector\n";
    int n;
    cin >> n;
    cout << "\n";
    if(n == 1){
        int length;
        cout << "1 - GetFirst\n2 - GetLast\n3 - Get\n4 - Set\n5 - GetLength\n6 - Append\n";
        cin >> n;
        cout << "write length array:\n";
        cin >> length;
        cout << "\n";
        int* array = new int[length];
        cout << "write array:\n";
        for(int i = 0; i < length; i++){
            cin >> array[i];
        }
        cout << "\n";
        ArraySequence<int> arr = ArraySequence<int>(array, length);
        if(n == 1){
            cout << arr.GetFirst() << "\n";
        }
        else if(n == 2){
            cout << arr.GetLast() << "\n";
        }
        else if(n == 3){
            cout << "write index:\n";
            cin >> n;
            cout << arr.Get(n);
            cout << "\n";
        }
        else if(n == 4){
            cout << "write index and value:\n";
            int index, value;
            cin >> index >> value;
            cout << "\n";
            arr.Set(index, value);
            for(int i = 0; i < arr.GetLength(); i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if(n == 5){
            cout << arr.GetLength() << "\n";
        }
        else if(n == 6){
            cout << "write value:\n";
            cin >> n;
            arr.Append(n);
            for(int i = 0; i < arr.GetLength(); i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "wrong input repeat input:\n";
        }
        startinterface();
    }
    else if(n == 2){
        int length;
        cout << "1 - GetFirst\n2 - GetLast\n3 - Get\n4 - insertAt\n5 - GetLength\n6 - Append\n7 - Prepend\n8 - GetSubsequence\n9 - Concat\n";
        cin >> n;
        cout << "write length array:\n";
        cin >> length;
        cout << "\n";
        int* array = new int[length];
        cout << "write array:\n";
        for(int i = 0; i < length; i++){
            cin >> array[i];
        }
        cout << "\n";
        LinkedListSequence<int> arr = LinkedListSequence<int>(array, length);
        if(n == 1){
            cout << arr.GetFirst() << "\n";
        }
        else if(n == 2){
            cout << arr.GetLast() << "\n";
        }
        else if(n == 3){
            cout << "write index:\n";
            cin >> n;
            cout << "\n";
            cout << arr.Get(n);
            cout << "\n";
        }
        else if(n == 4){
            cout << "write index and value:\n";
            int index, value;
            cin >> index >> value;
            cout << "\n";
            arr.insertAt(value, index);
            for(int i = 0; i < arr.GetLength(); i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if(n == 5){
            cout << arr.GetLength() << "\n";
        }
        else if(n == 6){
            cout << "write value:\n";
            cin >> n;
            cout << "\n";
            arr.Append(n);
            for(int i = 0; i < arr.GetLength(); i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if(n == 7){
            cout << "write value:\n";
            cin >> n;
            cout << "\n";
            arr.Prepend(n);
            for(int i = 0; i < arr.GetLength(); i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if(n == 8){
            int first, last;
            cout << "write first and last index:\n";
            cin >> first >> last;
            cout << "\n";
            LinkedListSequence<int>* result = dynamic_cast<LinkedListSequence<int>*>(arr.GetSubsequence(first, last));
            for(int i = 0; i < result->GetLength(); i++){
                cout << result->Get(i) << " ";
            }
            cout << "\n";
        }
        else if(n == 9){
            cout << "write length second array:\n";
            cin >> length;
            cout << "\n";
            int* newarray = new int[length];
            cout << "write second array:\n";
            for(int i = 0; i < length; i++){
                cin >> newarray[i];
            }
            cout << "\n";
            LinkedListSequence<int>* newarr = new LinkedListSequence<int>(newarray, length);
            Sequence<int>* result = arr.Concat(newarr);
            LinkedListSequence<int>* resultlist = dynamic_cast<LinkedListSequence<int>*>(result);
            for(int i = 0; i < resultlist->GetLength(); i++){
                cout << resultlist->Get(i) << " ";
            }
            cout << "\n";
        }
        else{
            cout << "wrong input repeat input:\n";
        }
        startinterface();
    }
    else if(n == 3){
        cout << "1 - double\n2 - complex\n";
        cin >> n;
        if(n == 1){
            int length;
            cout << "1 - Reserve\n2 - Resize\n3 - GetLength\n4 - Capacity\n5 - Get\n6 - Set\n7 - Append\n8 - GetFirst\n9 - GetLast\n10 - Max\n11 - Min\n12 - Norm\n13 - FilterPrime\n14 - multiplication by scalar\n15 - plus\n16 - minus\n17 - scalar multiplication by another vector:\n";
            cin >> n;
            cout << "write length array:\n";
            cin >> length;
            cout << "\n";
            double* array = new double[length];
            cout << "write array:\n";
            for(int i = 0; i < length; i++){
                cin >> array[i];
            }
            cout << "\n";
            Vector<double> arr = Vector<double>(array, length);
            if(n == 1){
                cout << "write new capacity:\n";
                cin >> n;
                cout << "\n";
                arr.Reserve(n);
                cout << arr.Capacity() << "\n";
            }
            else if(n == 2){
                cout << "write new size:\n";
                cin >> n;
                cout << "\n";
                arr.Resize(n);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 3){
                cout << arr.GetLength() << "\n";
            }
            else if(n == 4){
                cout << arr.Capacity() << "\n";
            }
            else if(n == 5){
                cout << "write index:\n";
                cin >> n;
                cout << "\n";
                cout << arr.Get(n) << "\n";
            }
            else if(n == 6){
                int index;
                double value;
                cin >> index >> value;
                cout << "\n";
                arr.Set(index, value);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 7){
                double value;
                cin >> value;
                cout << "\n";
                arr.Append(value);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 8){
                cout << arr.GetFirst() << "\n";
            }
            else if(n == 9){
                cout << arr.GetLast() << "\n";
            }
            else if(n == 10){
                cout << arr.Max() << "\n";
            }
            else if(n == 11){
                cout << arr.Min() << "\n";
            }
            else if(n == 12){
                cout << arr.Norm();
            }
            else if(n == 13){
                Vector<double>* result = arr.FilterPrime();
                for(int i = 0; i < result->GetLength(); i++){
                    cout << result->Get(i) << " ";
                }
                cout << "\n";
            }
            else if(n == 14){
                double scal;
                cout << "write scalar:\n";
                cin >> scal;
                cout << "\n";
                arr = Vector<double>(arr*scal);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 15){
                cout << "write length second array:\n";
                cin >> length;
                cout << "\n";
                double* array2 = new double[length];
                cout << "write second array:\n";
                for(int i = 0; i < length; i++){
                    cin >> array2[i];
                }
                cout << "\n";
                Vector<double> arr2 = Vector<double>(array2, length);
                arr = Vector<double>(arr + arr2);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 16){
                cout << "write length second array:\n";
                cin >> length;
                cout << "\n";
                double* array2 = new double[length];
                cout << "write second array:\n";
                for(int i = 0; i < length; i++){
                    cin >> array2[i];
                }
                cout << "\n";
                Vector<double> arr2 = Vector<double>(array2, length);
                arr = arr - arr2;
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 17){
                cout << "write length second array:\n";
                cin >> length;
                cout << "\n";
                double* array2 = new double[length];
                cout << "write second array:\n";
                for(int i = 0; i < length; i++){
                    cin >> array2[i];
                }
                cout << "\n";
                Vector<double> arr2 = Vector<double>(array2, length);
                cout << arr * arr2;
                cout << "\n";
            }
            else{
                cout << "wrong input repeat input:\n";
                startinterface();
            }
        }
        else if(n == 2){
            double real, imagen;
            int length;
            cout << "1 - Reserve\n2 - Resize\n3 - GetLength\n4 - Capacity\n5 - Get\n6 - Set\n7 - Append\n8 - GetFirst\n9 - GetLast\n10 - Norm\n";
            cin >> n;
            cout << "write length array:\n";
            cin >> length;
            cout << "\n";
            complex<double>* array = new complex<double>[length];
            cout << "write array:\n";
            for(int i = 0; i < length; i++){
                cin >> real >> imagen;
                array[i].real(real);
                array[i].imag(imagen);
            }
            cout << "\n";
            Vector<complex<double>> arr = Vector<complex<double>>(array, length);
            if(n == 1){
                cout << "write new capacity:\n";
                cin >> n;
                cout << "\n";
                arr.Reserve(n);
                cout << arr.Capacity() << "\n";
            }
            else if(n == 2){
                cout << "write new size:\n";
                cin >> n;
                cout << "\n";
                arr.Resize(n);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 3){
                cout << arr.GetLength() << "\n";
            }
            else if(n == 4){
                cout << arr.Capacity() << "\n";
            }
            else if(n == 5){
                cout << "write index:\n";
                cin >> n;
                cout << "\n";
                cout << arr.Get(n) << "\n";
            }
            else if(n == 6){
                int index;
                cin >> index >> real >> imagen;
                cout << "\n";
                complex<double> value(real, imagen);
                arr.Set(index, value);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 7){
                cin >> real >> imagen;
                cout << "\n";
                complex<double> value(real, imagen);
                arr.Append(value);
                for(int i = 0; i < arr.GetLength(); i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            else if(n == 8){
                cout << arr.GetFirst() << "\n";
            }
            else if(n == 9){
                cout << arr.GetLast() << "\n";
            }
            else if(n == 10){
                cout << arr.Norm();
            }
            else{
                cout << "wrong input repeat input:\n";
                startinterface();
            }
        }
        else{
            cout << "wrong input repeat input:\n";
            startinterface();
        }
    }
    else{
        cout << "wrong input repeat input:\n";
        startinterface();
    }
    startinterface();
}

#endif //LABMEPHI2_INTERFACE_H
