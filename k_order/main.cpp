#include "kOrder.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int n = atoi(argv[1]);
	kOrder* K = new kOrder(n);
	
	K->print();
	long long int kk=K->kORquick(4);
	cout << "SORTED" << endl;
	K->print();
	cout << "kOrder: " << kk << endl;
	system("PAUSE");
	return 0;

}