//
// Created by user on 22.02.2026.
//

#ifndef ZADANIYE_1_CUSTOMINTARR_H
#define ZADANIYE_1_CUSTOMINTARR_H

#include <string>

class CustomIntArr{
private:
    int m_size;
    int* m_arr;
    int m_capacity;
    void changeCapacity();
public:
    void fillWithNulls();
    CustomIntArr(int size);
    CustomIntArr();
    ~CustomIntArr();
    int getSize() const;
    int at(const int index);
    int& operator[](int index);
    const int& operator[](int index) const;
    void swap(const int index1, const int index2);
    void sort();
    int sumAll();
    int sumOfPositiveElements();
    int elementsInRangeCount(const int a, const int b);
    int evenNumberCount();
    int negativeNumberCount();
    double average();
    int max();
    int min();
    void pushBack(const int value);
    CustomIntArr& operator=(const CustomIntArr& other);
    void print();
    void readFromFile(std::string filePath, int numbersToRead);


    //might not be working
    CustomIntArr resize(const int begin, const int end);



};

#endif //ZADANIYE_1_CUSTOMINTARR_H
