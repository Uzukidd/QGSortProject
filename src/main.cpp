#include <iostream>
#include <cstring>
#include <ctime>
#include "util.cpp"
#include "../inc/qgsort.h"


#define ARR1_SIZE 10000
#define ARR2_SIZE 50000
#define ARR3_SIZE 200000

#define ARR4_SIZE 10

#define MSG " \
 0 - 9999  fByte -> arr1(10000 elements) \n \
 10000 - 59999  fByte -> arr2(50000 elements) \n \
 60000 - 259999  fByte -> arr3(200000 elements) \n \
 260000 - 10260000 fByte -> arr4 (100k * 100 elements) \n \
 Totall 10260000 elements. "

using namespace std;

/**
 * 0 - 9999  fByte -> arr1(10000 elements)
 * 10000 - 59999  fByte -> arr2(50000 elements) 
 * 60000 - 259999  fByte -> arr3(200000 elements)
 * 260000 - 10260000 fByte -> arr4 (100k * 100 elements)
 * Totall 10260000 elements.
 * */



int main() {


    int *arr4 = new int[ARR4_SIZE]; 
    //实验性测试数组模板

    int *inua = new int[ARR4_SIZE];
    //实验性数组

    int *temp = new int[ARR4_SIZE];
    //临时数组，个别排序需要用到

    int color[10] = {2, 0, 2, 1, 1, 2, 0, 2, 1, 1};
    //特典，颜色排序

    int callBack;

    double inter;

    try {

        srand((unsigned)time(nullptr));

        readData("randomTable.dat", rand() % 260000 * sizeof(int), arr4, ARR4_SIZE * sizeof(int));

    } catch(const char* e) {

        endl(cout << "未生成随机数表，请先运行\"randomTable.exe\"");

        system("pause");

        return 0;

    }
    
    endl(cout << "数据读取完毕！");

    endl(cout << "开始进行排序演示！（数组长度：" << ARR4_SIZE <<"）");

    endl(cout << "插入排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    insertSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);


    endl(cout << "归并排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    MergeSort(inua, 0, ARR4_SIZE, temp);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);


    endl(cout << "递归式快速排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    QuickSort_Recursion(inua, 0, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);


    endl(cout << "非递归式快速排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    QuickSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);



    endl(cout << "计数排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    CountSort(inua, ARR4_SIZE, arrayGetMaxElement(inua, ARR4_SIZE));

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);



    endl(cout << "基数计数排序：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    RadixCountSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);


    endl(cout << "颜色排序：");

    memcpy(inua, color, 10 * sizeof(int));

    arrayPrint(inua, 10);

    startRecord();

    ColorSort(inua, 10);

    inter = stopRecord();

    arrayPrint(inua, 10);

    endl(cout << "共耗时：" << inter << "ms");

    endl(cout);


    callBack = rand() % ARR4_SIZE;

    endl(cout << "寻找第" << callBack + 1 <<"个小的元素：");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    findNoKElements(inua, 0, ARR4_SIZE, callBack);

    inter = stopRecord();

    endl(cout << "此元素为：" << inua[callBack]);

    endl(cout << "共耗时：" << inter << "ms");

    QuickSort_Recursion(inua, 0, ARR4_SIZE);

    endl(cout << "排序后的数组参照：");

    arrayPrint(inua, ARR4_SIZE);

    endl(cout);


    system("pause");

    return 0;
}