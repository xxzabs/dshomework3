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


// �����������
void generateRandomArray(int a[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // ����0~99֮��������
    }
}
//����˳������
 
void generateSortedArray(int a[],int n){
	for(int i=0;i<n;i++)
	a[i]=i+2;
} 

//������������ 
void generateReverseArray(int a[],int n){
	for(int i=99;i<n;i--)
	a[i]=i-2;
}
// ��ӡ����
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// ð��������
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

// ѡ��������
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
/*void merge(int a[],int left,int mid ,int right) {
	int i,j,k;
	int n1=mid-left+1;
	int n2=right-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)L[i]=a[left+1];
	for(j=0;j<n2;j++)R[j]=a[mid+1+j];
	i=0;
	j=0;
	k=left;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;	
		}else {
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
		
	}
} 
     void mergeSort(int a[],int left,int mid,int right){
     	if(left<right){
     		int mid=(left+right)/2;
     		mergeSort(a,left,mid);
     		mergeSort(a,mid+1,right);
     		merge(a,left,mid,right);
		 }
	 }*/
	 void merge(int a[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++) L[i] = a[left + i];
    for(j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if(left < right) {
        int mid = ( left + right) / 2;
mergeSort(a, left, mid);
mergeSort(a, mid+1, right);
merge(a, left, mid, right);
}
}
// ��������������Ԫ�ص�λ��
void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int main() {
    int n = 10;  // ���鳤��
    int a[n];

    // �����������
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    generateSortedArray(a,n); 
    printf("Sorted array:\n");
    printArray(a, n);
    // ð������
    bubbleSort(a, n);
    printf("After bubble sort:\n");
    printArray(a, n);
    
    // �����������
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    
    // ѡ������
    selectionSort(a, n);
    printf("After selection sort:\n");
    printArray(a, n);
    // �����������
    generateRandomArray(a, n);
    printf("Original array:\n");
    printArray(a, n);
    //mergesort
    mergeSort(a,0,n-1);
    printf("After mergesort:\n");
    printArray(a,n);
   return 0;
}
