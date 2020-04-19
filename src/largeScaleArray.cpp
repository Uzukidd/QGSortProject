#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "util.cpp"
#include "../inc/qgsort.h"

#define ARR1_SIZE 10000
#define ARR2_SIZE 50000
#define ARR3_SIZE 200000
#define ARR4_SIZE 10000000

#define MSG " \
 0 - 9999  fByte -> arr1(10000 elements)  \n \
 10000 - 59999  fByte -> arr2(50000 elements) \n \
 60000 - 259999  fByte -> arr3(200000 elements) \n \
 260000 - 10260000 fByte -> arr4 (100k * 100 elements) \n \
 Totall 10260000 elements. "

using namespace std;

/**
 * 0 - 9999  fByte -> arr1(10000 elements) / arr[100][100] (100 * 100 elements)
 * 10000 - 59999  fByte -> arr2(50000 elements) 
 * 60000 - 259999  fByte -> arr3(200000 elements)
 * 260000 - 10260000  fByte -> arr4 (100k * 100 elements)
 * Totall 10260000 elements.
 * */



int main() {

    int *arr1 = new int[ARR1_SIZE];

    int *arr2 = new int[ARR2_SIZE];

    int *arr3 = new int[ARR3_SIZE];

    int *arr4 = new int[ARR4_SIZE];


    int *inua = new int[ARR4_SIZE];
    //实验性数组

    int *temp = new int[ARR4_SIZE];
    //临时数组，个别排序需要用到

    double inter;

    cout << setiosflags(ios::fixed) << setprecision(4);

    try {

        readData("randomTable.dat", 0 * sizeof(int), arr1, ARR1_SIZE * sizeof(int));

        readData("randomTable.dat", 10000 * sizeof(int), arr2, ARR2_SIZE * sizeof(int));

        readData("randomTable.dat", 60000 * sizeof(int), arr3, ARR3_SIZE * sizeof(int));

        readData("randomTable.dat", 260000 * sizeof(int), arr4, ARR4_SIZE * sizeof(int));

    } catch(const char* e) {

        endl(cout << "未生成随机数表，请先运行\"randomTable.exe\"");

        system("pause");

        return 0;

    }
    
    endl(cout << "数据读取完毕！");

    endl(cout << "开始进行排序演示！");


    endl(cout << "插入排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    insertSort(inua, ARR1_SIZE);

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");



    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    insertSort(inua, ARR2_SIZE);

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");



    memcpy(inua, arr3, ARR3_SIZE * sizeof(int));

    startRecord();

    insertSort(inua, ARR3_SIZE);

    inter = stopRecord();

    endl(cout << "200000规模共耗时：" << inter << "ms");


    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        insertSort(inua + i * 100, 100);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);



    endl(cout << "归并排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    MergeSort(inua, 0, ARR1_SIZE, temp);

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");


    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    MergeSort(inua, 0, ARR2_SIZE, temp);

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");


    memcpy(inua, arr3, ARR3_SIZE * sizeof(int));

    startRecord();

    MergeSort(inua, 0, ARR3_SIZE, temp);

    inter = stopRecord();

    endl(cout << "200000规模共耗时：" << inter << "ms");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        MergeSort(inua + i * 100, 0, 100, temp);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);



    endl(cout << "递归式快速排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    QuickSort_Recursion(inua, 0, ARR1_SIZE);

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");


    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    QuickSort_Recursion(inua, 0, ARR2_SIZE);

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");


    memcpy(inua, arr3, ARR3_SIZE * sizeof(int));

    startRecord();

    QuickSort_Recursion(inua, 0, ARR3_SIZE);

    inter = stopRecord();

    endl(cout << "200000规模共耗时：" << inter << "ms");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        QuickSort_Recursion(inua + i * 100, 0, 100);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);


    endl(cout << "非递归式快速排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    QuickSort(inua, ARR1_SIZE);

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");


    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    QuickSort(inua, ARR2_SIZE);

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");



    memcpy(inua, arr3, ARR3_SIZE * sizeof(int));

    startRecord();

    QuickSort(inua, ARR3_SIZE);

    inter = stopRecord();

    endl(cout << "200000规模共耗时：" << inter << "ms");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        QuickSort(inua + i * 100, 100);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);




    endl(cout << "计数排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    CountSort(inua, ARR1_SIZE, arrayGetMaxElement(inua, ARR1_SIZE));

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");

    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    CountSort(inua, ARR2_SIZE, arrayGetMaxElement(inua, ARR2_SIZE));

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");


    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    CountSort(inua, ARR3_SIZE, arrayGetMaxElement(inua, ARR3_SIZE));

    inter = stopRecord();

    endl(cout << "200000规模共耗时：" << inter << "ms");


    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        CountSort(inua + i * 100, 100, 10000);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);

    



    endl(cout << "基数计数排序：");

    memcpy(inua, arr1, ARR1_SIZE * sizeof(int));

    startRecord();

    RadixCountSort(inua, ARR1_SIZE);

    inter = stopRecord();

    endl(cout << "10000规模共耗时：" << inter << "ms");


    memcpy(inua, arr2, ARR2_SIZE * sizeof(int));

    startRecord();

    RadixCountSort(inua, ARR2_SIZE);

    inter = stopRecord();

    endl(cout << "50000规模共耗时：" << inter << "ms");

    memcpy(inua, arr3, ARR3_SIZE * sizeof(int));

    startRecord();

    RadixCountSort(inua, ARR3_SIZE);

    inter = stopRecord();


    endl(cout << "200000规模共耗时：" << inter << "ms");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    startRecord();

    for(int i = 0;i < 100000;i++) {

        RadixCountSort(inua + i * 100, 100);

    }

    inter = stopRecord();

    endl(cout << "100K * 100规模共耗时：" << inter << "ms");

    endl(cout);


    system("pause");

    return 0;
}