#include <iostream>
#include <algorithm>

using namespace std;

void Nhap(int *&A, int n);
void Xuat(int *A, int n);
void MergeSort(int *A, int n);
void merge(int *A, int l, int m, int r);
int min(int a, int b);

void main()
{
	int n;
	cin >> n;
	int *A = new int[n];
	Nhap(A,n);
	MergeSort(A,n);
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
}
// Gop hai mang con arr[l...m] và arr[m+1..r]
void merge(int *A, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l+1;
    int n2 =  r - m;
    int *L = new int[n1];
	int *R = new int[n2];
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
	delete []L;
	delete []R;
}
void MergeSort(int *A, int n)
{
    int l=1;
	while ( l < n )
	{
		int k=0;
		int i=0;
		int m=min(i+l-1,n-1);
		int j = min(m+l,n-1);
		do
		{
			merge(A, i, m, j);
			i=min(j+1,n-1);
			m=min(i+l-1,n-1);
			j=min(m+l,n-1);
			k+=2;
		}
		while ( k<n/l );
		l*=2;
	}
}
int min(int a, int b)
{
	if ( a>b )
		return b;
	else 
		return a;

}