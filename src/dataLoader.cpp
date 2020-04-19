#include <iostream>
#include "util.cpp"

#define MSG " \
 0 - 9999  fByte -> arr1(10000 elements) \n \
 10000 - 59999  fByte -> arr2(50000 elements) \n \
 60000 - 259999  fByte -> arr3(200000 elements) \n \
 260000 - 10260000 fByte -> arr4 (100k * 100 elements) \n \
 Totall 10260000 elements. "

#define ARR1_SIZE 10000
#define ARR2_SIZE 50000
#define ARR3_SIZE 200000
#define ARR4_SIZE 10000000

using namespace std;

/**
 * 0 - 9999  fByte -> arr1(10000 elements)
 * 10000 - 59999  fByte -> arr2(50000 elements) 
 * 60000 - 259999  fByte -> arr3(200000 elements)
 * 260000 - 10260000 fByte -> arr4 (100k * 100 elements)
 * Totall 10260000 elements.
 * */



int main() {

    int *arr1 = new int[ARR1_SIZE];

    int *arr2 = new int[ARR2_SIZE];

    int *arr3 = new int[ARR3_SIZE];

    int *arr4 = new int[ARR4_SIZE];

    try {

        readData("randomTable.dat", 0 * sizeof(int), arr1, ARR1_SIZE * sizeof(int));

        readData("randomTable.dat", 10000 * sizeof(int), arr2, ARR2_SIZE * sizeof(int));

        readData("randomTable.dat", 60000 * sizeof(int), arr3, ARR3_SIZE * sizeof(int));

        readData("randomTable.dat", 260000 * sizeof(int), arr4, ARR4_SIZE * sizeof(int));

    } catch(const char* e) {

        cout << "未生成随机数表，请运行\"randomTable.exe\"" << endl;

        system("pause");

        return 0;

    }

    int opr = 0;
    
    endl(cout << "数据读取完毕！");

    endl(cout << MSG);

    endl(cout << "请输入1、2、3、4分别查看不同的数据集 arr1 arr2 arr3 arr4");

    while(cin >> opr) {

        switch(opr) {

            case 1:
                arrayPrint(arr1, ARR1_SIZE);
                break;

            case 2:
                arrayPrint(arr2, ARR2_SIZE);
                break;

            case 3:
                arrayPrint(arr3, ARR3_SIZE);
                break;

            case 4:
                arrayPrint(arr4, ARR4_SIZE);
                break;

        }

    }

    system("pause");

    return 0;
}