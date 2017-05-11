#pragma once
#define MAX 10000000000
class kOrder {
public:
	kOrder(int);
	void print();
	long long int kOquick(int);
	int kORquick(int);
	int kO5group();

private:

	long long int *A;
	int size;

	long long int getLRand();
	int partition(long long int * , int , int );
	int rndPartition(long long int *, int, int);
	void quick_sort(long long int * , int , int );
	void quick_sort_rand(long long int *, int, int);
};
