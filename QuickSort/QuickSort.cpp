#include <iostream>
#include <algorithm>
using namespace std;
 
void Nhap(int *&A, int n);
void Xuat(int *A, int n);
int partition (int *A, int low, int high);
void QuickSort(int *A, int low, int high);

void main()
{
	int n;
	cin >> n;
	int *A = new int[n];
	Nhap(A,n);
	QuickSort(A,0,n-1);
	Xuat(A,n);
	delete []A;
}
void Nhap(int *&A, int n)
{
	for(int i=0; i<n; i++)
		cin >> A[i];
}
void Xuat(int *A, int n)
{
	for(int i=0 ; i<n; i++)
		cout << A[i] << " ";
	cout << "\n";
}
int partition (int *A, int low, int high)
{
    int pivot = A[high];
    int left = low;
    int right = high-1 ;
    while(true){
        while(left <= right && A[left] < pivot) 
			left++;
        while(right >= left && A[right] > pivot) 
			right--;
        if (left >= right) 
			break;
        swap(A[left], A[right]);
        left++;
        right--;
    }
    swap(A[left], A[high]);
    return left;
}
 
void QuickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        QuickSort(A, low, pi - 1);
        QuickSort(A, pi + 1, high);
    }
}