#include <cstddef>
#include <iostream>

using namespace std;

void pp(int & a) {
    cout << &a << " " << a << " " << sizeof(a) << endl;
}

template <typename T>
class dynamicArray {
    T * m_arr;
    size_t m_size;

public:
    dynamicArray(size_t size)
        : m_arr(new T[size]), m_size(size) {}

    ~dynamicArray() {
        delete [] m_arr;
        cout << "deleted" << endl;
    }

    T get(size_t index) const {
        return m_arr[index];
    }

    void set(size_t index, T val) {
        m_arr[index] = val;
    }

    void print() const {
        for(size_t i = 0; i < m_size; i++) {
            cout << i << " " << m_arr[i] << endl;
        }
    }

    // define operator functionality
    T & operator [](size_t index) {
        return m_arr[index];
    }

    // good ot have const version for optimization
    const T & operator [](size_t index) const {
        return m_arr[index];
    }
};

int main(int argc, char * argv[]) {

    int a = 10;
    int b = 20;

    // stack allocation
    int arr[10] = {}; // give base value to elements

    // heap allocation
    int * harr = new int[10];

    int* pa = &a;
    int* pb = &b;

    *pa = 17; // == *(&a) = 17;
    // *(pb-1) = 17 modifies a !!!!dangerous!!!!

    dynamicArray<int> myArr(10);

    myArr.set(4, 10);
    myArr.set(8, 200);

    dynamicArray<float> myFloatArr(5);

    myFloatArr[1] = 3.14159;
    myFloatArr[2] = 5.5;
    myFloatArr[3] = 12.13;

    myFloatArr.print();

    cout << myArr[3] << endl;

    return 0;
}
