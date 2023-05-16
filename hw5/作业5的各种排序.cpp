#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generateRandomArray(int a[], int n);
void printArray(int a[], int n);
void bubbleSort(int a[], int n);
void selectionSort(int a[], int n);
void swap(int a[], int i, int j);
int partition(int a[], int left, int right);
void quickSort(int a[], int left, int right);
void insertionSort(int a[], int n);
void merge(int a[], int left, int mid, int right);
void mergeSort(int a[], int left, int right);


// 生成随机数组
void generateRandomArray(int a[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // 生成0~99之间的随机数
    }
}
//生成顺序序列
 
void generateSortedArray(int a[],int n){
	for(int i=0;i<n;i++)
	a[i]=i+2;
} 

//生成逆序序列 
void generateReverseArray(int a[],int n){
	for(int i=99;i<n;i--)
	a[i]=i-2;
}
// 打印数组
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 冒泡排序函数
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

// 选择排序函数
void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;
        }
    }
}

// 交换数组中两个元素的位置
void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int main() {
    int n = 10;  // 数组长度
    int a[n];
    
    // 生成随机数组
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    generateSortedArray(a,n); 
    printf("Original array:\n");
    printArray(a, n);
    // 冒泡排序
    bubbleSort(a, n);
    printf("After bubble sort:\n");
    printArray(a, n);
    
    // 生成随机数组
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    // 选择排序
    selectionSort(a, n);
    printf("After selection sort:\n");
    printArray(a, n);
    
   /* // 生成随机数组
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    // 快速排序
    quickSort(a, 0, n-1);
    printf("After quick sort:\n");
    printArray(a, n);
    
    // 生成随机数组
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    // 插入排序
    insertionSort(a, n);
    printf("After insertion sort:\n");
    return 0;
}*/
   return 0;
}
