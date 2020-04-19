#include <iostream>
#include "util.cpp"
#define GENERATOR 10260000

using namespace std;

/**
 * 0 - 9999  fByte -> arr1(10000 elements)
 * 10000 - 59999  fByte -> arr2(50000 elements) 
 * 60000 - 259999  fByte -> arr3(200000 elements)
 * 260000 - 10260000 fByte -> arr4 (100k * 100 elements)
 * 
 * 
 * */



int main() {

    try {

        updateRandomTable(GENERATOR, 10000);

    } catch(const char* e) {

        cout << "随机数表生成错误" << endl;

    }


    endl(cout << "生成完毕：共" << GENERATOR << "个int元素");

    system("pause");

    return 0;
}