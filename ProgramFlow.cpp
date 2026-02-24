//
// Created by user on 24.02.2026.
//
#include <iostream>
#include <fstream>
#include <string>
#include "CustomIntArr.h"
#include "ProgramFlow.h"

using std::cout;
using std::endl;

void ProgramFlow::printCustomArr(const CustomIntArr &arr){
    for(int i = 0; i < arr.getSize(); i++){
        //operator[]
        cout << arr[i] << " ";
    }
    cout << endl;
}
void ProgramFlow::run(){
    cout << "initialisation of an array\n";
    int arrSize = 17;
    CustomIntArr a(arrSize);

    cout << "filling in an array from file\n";
    a.readFromFile("numbers.txt", arrSize);
    printCustomArr(a);

    cout << "max and min\n";
    cout << a.max() << " " << a.min() << endl;

    cout << "Copy of an array\n";
//    operator=
    CustomIntArr b;
    b = a;
    printCustomArr(b);

    cout << "sorting\n";
    b.sort();
    printCustomArr(b);


    cout << "sum of positive elements\n";
    cout << a.sumOfPositiveElements() << endl;

    cout << "evenNumberCount\n";
    cout << a.evenNumberCount() << endl;

    cout << "negativeNumberCount\n";
    cout << a.negativeNumberCount() << endl;

    cout << "average\n";
    cout << a.average() << endl;

    cout << "elementsInRangeCount 4, 100000\n";
    cout << a.elementsInRangeCount(4, 100000) << endl;
    cout << "elementsInRangeCount -8, 100000\n";
    cout << a.elementsInRangeCount(-8, 100000) << endl;
    cout << "elementsInRangeCount 2, 5\n";
    cout << a.elementsInRangeCount(2, 5) << endl;

}

ProgramFlow::~ProgramFlow() = default;
ProgramFlow::ProgramFlow() = default;




