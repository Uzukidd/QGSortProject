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
    //ʵ���Բ�������ģ��

    int *inua = new int[ARR4_SIZE];
    //ʵ��������

    int *temp = new int[ARR4_SIZE];
    //��ʱ���飬����������Ҫ�õ�

    int color[10] = {2, 0, 2, 1, 1, 2, 0, 2, 1, 1};
    //�ص䣬��ɫ����

    int callBack;

    double inter;

    try {

        srand((unsigned)time(nullptr));

        readData("randomTable.dat", rand() % 260000 * sizeof(int), arr4, ARR4_SIZE * sizeof(int));

    } catch(const char* e) {

        endl(cout << "δ�������������������\"randomTable.exe\"");

        system("pause");

        return 0;

    }
    
    endl(cout << "���ݶ�ȡ��ϣ�");

    endl(cout << "��ʼ����������ʾ�������鳤�ȣ�" << ARR4_SIZE <<"��");

    endl(cout << "��������");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    insertSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);


    endl(cout << "�鲢����");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    MergeSort(inua, 0, ARR4_SIZE, temp);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);


    endl(cout << "�ݹ�ʽ��������");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    QuickSort_Recursion(inua, 0, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);


    endl(cout << "�ǵݹ�ʽ��������");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    QuickSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);



    endl(cout << "��������");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    CountSort(inua, ARR4_SIZE, arrayGetMaxElement(inua, ARR4_SIZE));

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);



    endl(cout << "������������");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    RadixCountSort(inua, ARR4_SIZE);

    inter = stopRecord();

    arrayPrint(inua, ARR4_SIZE);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);


    endl(cout << "��ɫ����");

    memcpy(inua, color, 10 * sizeof(int));

    arrayPrint(inua, 10);

    startRecord();

    ColorSort(inua, 10);

    inter = stopRecord();

    arrayPrint(inua, 10);

    endl(cout << "����ʱ��" << inter << "ms");

    endl(cout);


    callBack = rand() % ARR4_SIZE;

    endl(cout << "Ѱ�ҵ�" << callBack + 1 <<"��С��Ԫ�أ�");

    memcpy(inua, arr4, ARR4_SIZE * sizeof(int));

    arrayPrint(inua, ARR4_SIZE);

    startRecord();

    findNoKElements(inua, 0, ARR4_SIZE, callBack);

    inter = stopRecord();

    endl(cout << "��Ԫ��Ϊ��" << inua[callBack]);

    endl(cout << "����ʱ��" << inter << "ms");

    QuickSort_Recursion(inua, 0, ARR4_SIZE);

    endl(cout << "������������գ�");

    arrayPrint(inua, ARR4_SIZE);

    endl(cout);


    system("pause");

    return 0;
}