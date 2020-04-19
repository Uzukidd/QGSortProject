#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <Windows.h>

#define RTPATH "randomTable.dat"

using namespace std;

LARGE_INTEGER freq, start, ending;

// clock_t start;


void writeData(const char* path, int offset, int* array, size_t size);

void readData(const char* path, int offset, int* array, size_t size);

void randomGenerator(int* array, int length, int max);

void updateRandomTable(int length, int max);

void arrayPrint(int* array, int length);

int arrayGetMaxElement(int* array, int length);


void writeData(const char* path, int offset, int* array, size_t size) {

    ofstream result;

    result.open(path, ios_base::binary);

    if (!result) return;

    result.seekp(offset, ios::beg);

    result.write((char*)array, size);

    result.close();

}

void readData(const char* path, int offset, int* array, size_t size) {

    ifstream result;

    result.open(path, ios_base::binary);

    if (!result) throw "FILE NOT FOUND";

    result.seekg(offset, ios::beg);

    result.read((char*)array, size);

    result.close();

}




void randomGenerator(int* array, int length, int max) {

    srand((unsigned) time(0));

    for(int i = 0;i < length;i++) {

        array[i] = ((int)rand()) % max;

    }

}

void updateRandomTable(int length, int max) {

    int *arr = new int[length];

    randomGenerator(arr, length, max);

    writeData(RTPATH, 0, arr, length * sizeof(int));

    delete[] arr;

}




int arrayGetMaxElement(int* array, int length) {

    int res = 0;

    while(length--) res = max(res, array[length]);

    return res;
    
}

void arrayPrint(int* array, int length) {

    for(int i = 0;i < length;i++) {

        cout << array[i] << ' ';

    }

    endl(cout);

}

void startRecord() {

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

}

double stopRecord() {

    QueryPerformanceCounter(&ending);

    return (ending.QuadPart - start.QuadPart) / (double)freq.QuadPart * 1000.0f;

}

// void startRecord() {

//     start = clock();

// }

// clock_t stopRecord() {

//     return clock() - start;

// }