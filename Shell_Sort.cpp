#include <iostream>

using namespace std;

void Shell(int a[], int n) {
	for (int gap = n/2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int key = data[i];
			int j = 0;
			for (j = i-gap; j >= 0 && data[j] > key; j -= gap) {
				
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int a[] = {1, 3, 10, 18, 7};
	Shell(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}	
}