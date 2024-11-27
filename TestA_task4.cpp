#include <iostream>

//This program with given array will check which numbers, in their binary form, has even 1 bits at the even places and remove them from the given array

using namespace std;

void ReadArray(int array[]);
void PrintArray(int array[], int size);
bool IsSorted(int array[]);
void CountEvenEvenNumbers(int array[]);
void clearArray(int array[], int& size);

int main()
{
	int size = 5;
	int numbersArray[5] = {};
	int evenNumbers = 0;

	cout << "Enter 5 natural numbers:" << endl;
	ReadArray(numbersArray);
	PrintArray(numbersArray, size);

	if (IsSorted(numbersArray)) {
		cout << "Sorted";
		cout << endl << endl;
	}
	else {
		cout << "Not Sorted";
		cout << endl << endl;
	}

	CountEvenEvenNumbers(numbersArray);
	clearArray(numbersArray, size);
	PrintArray(numbersArray, size);


}

//This function takes as input the numbers of the array
void ReadArray(int array[]) {
	for (int i = 0; i < 5; i++) {
		cin >> array[i];
	}
	cout << endl;
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

	cout << endl << endl;
}

//This function checks if the program is sorted or not
bool IsSorted(int array[]) {
	bool ascending = true;
	bool descending = true;

	for (int i = 0; i < 4; ++i) {
		if (array[i] > array[i + 1]) {
			ascending = false;
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (array[i] < array[i + 1]) {
			descending = false;
		}
	}
	

	return ascending || descending;
}

//The function will count the the even bits only at the even positions in binary form
void CountEvenEvenNumbers(int array[]) {

	int countNumber = 0;

	for (int i = 0; i < 5; i++) {
		int countEvenBits = 0;
		int a = 1;
		int pos = 0;
		for (int j = 0; j < 16; j++) {
			if (array[i] & a) {
				countEvenBits++;	
			}
			a = a << 2;
		}
		cout << endl;
		cout << "Number of even bits at even places in the number '" << array[i] << "' is " << countEvenBits << endl;

		if (countEvenBits == 0) {
			continue;
		}
		//This will show at which place in the array is the number
		if (countEvenBits % 2 == 0) {
			pos = i;										
			cout << "Number is at position: " << pos << endl;
			countNumber++;
		}
	
	}

	cout << endl;
	cout << countNumber << " number(s) have even bits at the even places in binary form!";
	cout << endl << endl;

}

//This program will delete the elements that have even number of 1 bits at the even places in the binary form of the number
void clearArray(int array[], int& size) {
	int newArray[5] = {};
	int newSize = 0;

	for (int i = 0; i < 5; i++) {
		int countEvenBits = 0;
		int a = 1;
		//This checks only the even places of the bits
		for (int j = 0; j < 16; j++) {
			if (array[i] & a) {
				countEvenBits++;
			}
			a = a << 2;
		}

		//This saves the number if the number of even bits is odd or 0
		if (countEvenBits == 0 || countEvenBits % 2 != 0) {
			newArray[newSize++] = array[i];
		}
	}

	//This re-writes the array only with the needed elements
	for (int i = 0; i < newSize; i++) {
		array[i] = newArray[i];
	}

	size = newSize;
}