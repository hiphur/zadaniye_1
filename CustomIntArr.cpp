//
// Created by user on 22.02.2026.
//
#include "CustomIntArr.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

//struct Span{
//    int* arr;
//    int size;
//};
CustomIntArr::~CustomIntArr() {
    delete[] m_arr;
}
void CustomIntArr::changeCapacity() {
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
CustomIntArr::CustomIntArr(int size)
        : m_size(size), m_arr(new int[size]), m_capacity(size){
    fillWithNulls();
}
CustomIntArr::CustomIntArr()
        : CustomIntArr(0){
}

void CustomIntArr::fillWithNulls() {
    for(int i = 0; i < m_size; i++){
        m_arr[i] = 0;
    }
}


int CustomIntArr::getSize() const{
    return m_size;
}
int CustomIntArr::at(const int index){
    if(index < m_size && index >= 0){
        return m_arr[index];
    }
    else{
        throw std::invalid_argument("index is not in range");
    }
}
int& CustomIntArr::operator[](int index){
    return m_arr[index];
}
const int& CustomIntArr::operator[](int index) const{
    return m_arr[index];
}
void CustomIntArr::swap(const int index1, const int index2){
    if(index1 < m_size && index1 >= 0
       && index2 < m_size && index2 >= 0 ){
        int t = m_arr[index1];
        m_arr[index1] = m_arr[index2];
        m_arr[index2] = m_arr[index1];
    }
    else{
        throw std::invalid_argument("index is not in range");
    }
}
void CustomIntArr::sort() {
    for (int step = 0; step < m_size -1; ++step) {


        for (int i = 0; i < m_size - step - 1; ++i) {
            if (m_arr[i] > m_arr[i + 1]) {
                int temp = m_arr[i];
                m_arr[i] = m_arr[i + 1];
                m_arr[i + 1] = temp;
            }
        }
    }
}
int CustomIntArr::sumAll(){
    int sum = 0;
    for(int i = 0; i < m_size; i++){
        sum += m_arr[i];
    }
    return sum;
}
int CustomIntArr::sumOfPositiveElements(){
    int sum = 0;
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] > 0){
            sum += m_arr[i];
//            std::cout << sum << '\n';
        }
    }
    return sum;
}


int CustomIntArr::elementsInRangeCount(const int a, const int b){
    int left = std::max(a, 0);
    int right = std::min(b, m_size);

    if (left <= right) {
        return (right - left);
    }
    else{
        return 0;
    }
}
int CustomIntArr::evenNumberCount() {
    int count = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
int CustomIntArr::negativeNumberCount() {
    int count = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] < 0) {
            count++;
        }
    }
    return count;
}
double CustomIntArr::average() {
    int sum = 0;
    for (int i = 0; i < m_size; i++) {
        sum += m_arr[i];

    }
    return (double)sum / m_size;
}
void CustomIntArr::pushBack(const int value) {
    if(m_size == m_capacity) {
        changeCapacity();
    }
    m_arr[m_size] = value;
    m_size++;
}
CustomIntArr& CustomIntArr::operator=(const CustomIntArr& other){
    if(this == &other){
        return *this;
    }

    delete[] m_arr;
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
//might not be working
CustomIntArr CustomIntArr::resize(const int begin, const int end){
    int newSize = end - begin;
    int* newArr = new int[newSize];
    for(int i = begin, j = 0; i < end; i++, j++){
        newArr[j] = m_arr[i];
    }
    m_arr = newArr;
    m_size = newSize;
    m_capacity = newSize;
}
int CustomIntArr::max(){
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
int CustomIntArr::min(){
    if(m_size == 0) {
        return 0;
    }
    int arrMin = m_arr[0];
    for (int i = 0; i < m_size; i++) {
        if (arrMin > m_arr[i]) {
            arrMin = m_arr[i];
        }
    }
    return arrMin;
}

void CustomIntArr::readFromFile(std::string filePath, int numbersToRead){
    std::ifstream file(filePath);

    if (file.is_open()) {
        for(int i = 0; i < numbersToRead; i++){
            file >> m_arr[i];
            if(file.fail()){
                throw std::runtime_error("Couldn't read the file correctly.");
            }
        }
        file.close();
    }
    else {
        throw std::runtime_error("Couldn't open the file.");
    }
}

void CustomIntArr::print() {
    for(int i = 0; i < m_size; i++){
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}
/*class CustomIntArr{
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
    CustomIntArr(int size)
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
    int at(const int index){
        if(index < m_size && index >= 0){
            return m_arr[index];
        }
        else{
            throw std::invalid_argument("index is not in range");
        }
    }
    void swap(const int index1, const int index2){
        if(index1 < m_size && index1 >= 0
           && index2 < m_size && index2 >= 0 ){
            int t = m_arr[index1];
            m_arr[index1] = m_arr[index2];
            m_arr[index2] = m_arr[index1];
        }
        else{
            throw std::invalid_argument("index is not in range");
        }
    }
    void sort() {
        int n = m_size;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {

                if (m_arr[j] > m_arr[j + 1]) {
                    this->swap(j, j + 1);
                }
            }
        }
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
    int sumOfPositiveElements(){
        int sum = 0;
        for(int i = 0; i < m_size; i++){
            if(m_arr[i] > 0){
                sum += m_arr[i];
            }
        }
        return sum;
    }
    int elementsInRangeCount(const int a, const int b){
        int left = std::max(a, 0);
        int right = std::min(b, m_size);

        if (left <= right) {
            return (right - left);
        }
        else{
            return 0;
        }
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
    double average() {
        int sum = 0;
        for (int i = 0; i < m_size; i++) {
            sum += m_arr[i];

        }
        return sum / m_size;
    }
    void pushBack(const int value) {
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

    //might not be working
    CustomIntArr resize(const int begin, const int end){
        int newSize = end - begin;
        int* newArr = new int[newSize];
        for(int i = begin, j = 0; i < end; i++, j++){
            newArr[j] = m_arr[i];
        }
        m_arr = newArr;
        m_size = newSize;
        m_capacity = newSize;
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
};*/