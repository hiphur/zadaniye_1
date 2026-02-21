#include <iostream>
using std::cout;
using std::endl;
struct Span{
    int* arr;
    int length;
};
class CustomIntArr{
private:
    int m_length;
    int* m_arr;

public:
    void fillWithNulls(){
        for(int i = 0; i < m_length; i++){
            m_arr[i] = 0;
        }
    }
    CustomIntArr(int length = 0)
    : m_length(length), m_arr(new int[length]){
        fillWithNulls();
    }
    CustomIntArr(Span span)
    : m_arr(span.arr), m_length(span.length){
        fillWithNulls();
    }
    ~CustomIntArr(){
        delete[] m_arr;
    }
    int getLength(){
        return m_length;
    };
    int at(int index){
        return m_arr[index];
    }
    int sumAll(){
        int sum = 0;
        for(int i = 0; i < m_length; i++){
            sum += m_arr[i];
        }
        return sum;
    }
    Span getSpanCopy(){
        Span span;
        span.arr = m_arr;
        span.length = m_length;
        return span;
    }

};

int main() {
    CustomIntArr a(8);
    cout << a.at(5);
    return 0;
}
