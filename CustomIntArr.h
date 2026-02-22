//
// Created by user on 22.02.2026.
//

#ifndef ZADANIYE_1_CUSTOMINTARR_H
#define ZADANIYE_1_CUSTOMINTARR_H
struct Span{
    int* arr;
    int size;
};
class CustomIntArr{
private:
    int m_size;
    int* m_arr;
    int m_capacity;
    void changeCapacity() {
        if(m_capacity == 0) {
            m_capacity = 1;
        }
        else {
            m_capacity *= 2;
        }
        int* newArr = new int[m_capacity];
        for(int i = 0; i < m_capacity; i++) {
            newArr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = newArr;
    }
public:
    void fillWithNulls(){
        for(int i = 0; i < m_size; i++){
            m_arr[i] = 0;
        }
    }
    CustomIntArr(int size = 0)
    : m_size(size), m_arr(new int[size]), m_capacity(size){
        fillWithNulls();
    }
    CustomIntArr(Span span)
    : m_arr(span.arr), m_size(span.size), m_capacity(span.size){
        fillWithNulls();
    }
    ~CustomIntArr(){
        delete[] m_arr;
    }
    int getSize(){
        return m_size;
    };
    int at(int index){
        return m_arr[index];
    }
    int sumAll(){
        int sum = 0;
        for(int i = 0; i < m_size; i++){
            sum += m_arr[i];
        }
        return sum;
    }
    Span getSpanCopy(){
        Span span;
        span.arr = m_arr;
        span.size = m_size;
        return span;
    }
    int SumOfPositiveElements(){
        int sum = 0;
        for(int i = 0; i < m_size; i++){
            if(m_arr[i] > 0){
                sum += m_arr[i];
            }
        }
        return sum;
    }
    int evenNumberCount() {
        int count = 0;
        for (int i = 0; i < m_size; i++) {
            if (m_arr[i] % 2 == 0) {
                count++;
            }
        }
        return count;
    }
    int negativeNumberCount() {
        int count = 0;
        for (int i = 0; i < m_size; i++) {
            if (m_arr[i] < 0) {
                count++;
            }
        }
        return count;
    }
    void pushBack(int value) {
        if(m_size == m_capacity) {
            changeCapacity();
        }
        m_arr[m_size] = value;
        m_size++;
    }
    CustomIntArr& operator=(const CustomIntArr& other){
        if(this == &other){
            return *this;
        }

        delete[] m_arr;
//        m_size = other.m_size;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        if(other.m_arr == nullptr){
            m_arr = nullptr;
        }
        else{
            m_arr = new int[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                m_arr[i] = other.m_arr[i];
            }
        }
        return *this;
    }

    int max(){
        if(m_size == 0) {
            return 0;
        }
        int arrMax = m_arr[0];
        for (int i = 0; i < m_size; i++) {
            if (arrMax < m_arr[i]) {
                arrMax = m_arr[i];
            }
        }
        return arrMax;

    }
    int min(){
        if(m_size == 0) {
            return 0;
        }
        int arrMin = m_arr[0];
        for (int i = 0; i < m_size; i++) {
            if (arrMin < m_arr[i]) {
                arrMin = m_arr[i];
            }
        }
        return arrMin;
    }
};

#endif //ZADANIYE_1_CUSTOMINTARR_H
