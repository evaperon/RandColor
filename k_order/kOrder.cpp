#include "kOrder.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std;

kOrder::kOrder(int n) {

	size = n;
	A = new long long int[size];
	for (int i = 0; i < size;i++) {
		A[i] = getLRand();
	}
}

void kOrder::print() {

	for (int i = 0; i < size;i++) {
		cout << A[i] << endl;
	}

}

/**
* Sort the array using quicksort (O(nlongn) expected complexity)and then
* take the k-th element (A[k]) O(1)
*/


int kOrder::partition(long long int *arr, int lp, int rp) {
	long long int pivot = arr[lp];
	
	while (lp < rp) {
		while (lp < rp && arr[rp] >= pivot)
			rp--;
		if (lp < rp) {
			arr[lp++] = arr[rp];
		}
		while (lp < rp && arr[lp] <= pivot)
			lp++;
		if (lp < rp) {
			arr[rp--] = arr[lp];
		}
	} 
	arr[lp] = pivot;

	return lp;
}
//TODO
int kOrder::rndPartition(long long int *arr, int alp, int rp)
{
	int lp = alp + (rand() % (int)(rp - alp + 1));
	long long int pivot = arr[lp];

	while (lp < rp) {
		while (lp < rp && arr[rp] >= pivot)
			rp--;
		if (lp < rp) {
			arr[lp++] = arr[rp];
		}
		while (lp < rp && arr[lp] <= pivot)
			lp++;
		if (lp < rp) {
			arr[rp--] = arr[lp];
		}
	}
	arr[lp] = pivot;

	return lp;

	return 0;
}

void kOrder::quick_sort(long long int *arr, int lp, int rp) {
	if (rp - lp <= 0) {
		return;
	}

	int pivot;

	pivot = partition(arr, lp, rp);
	quick_sort(arr, lp, pivot - 1);
	quick_sort(arr, pivot + 1, rp);
}

void kOrder::quick_sort_rand(long long int *arr, int lp, int rp) {
	if (rp - lp <= 0) {
		return;
	}

	int pivot;

	pivot = rndPartition(arr, lp, rp);
	quick_sort(arr, lp, pivot - 1);
	quick_sort(arr, pivot + 1, rp);
}

long long int kOrder::kOquick(int k)
{
	quick_sort(A, 0, size - 1);
	return A[k-1];
}

/**
* Sort the array using C++'s qsort (quicksort) (O(nlongn) expected complexity)and then
* take the k-th element (A[k]) O(1)
*/

int kOrder::kORquick(int k)
{
	quick_sort_rand(A, 0, size - 1);
	return A[k - 1];
}

int kOrder::kO5group()
{
	return 0;
}

long long int kOrder::getLRand()
{

	long long result = 0;

	const int len = 1 + rand()*10 /RAND_MAX;

	for (int i = 0;i < len;i++) {
		int dig = rand()*10 / RAND_MAX;
		
		result = result * 10 + dig;
	}
	result++;
	return result;
}

