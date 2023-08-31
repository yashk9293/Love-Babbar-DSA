// Jagged arrays are arrays that have different no. of columns in each of it 
// rows. They mave have same no. of columns.

#include <iostream>
#include <string>

using namespace std;

int main() {
	//dynamic arrays are used to declare an array in heap memory and we can change the size of these arrays at runtime, whereas we cannot change the size of static arrays at runtime
	//2D Jagged array in C++
	int rows;
	cout << "Enter no of rows of array: ";
	cin >> rows;
	int *numbers = new int[rows];   //array to store no of columns in each row;
	//declaration of array
	int **array = new int*[rows];   //jagged array

	for (int i = 0; i < rows; i++) {
		cout << "Enter no. of cols in row " << i << ": ";
		cin >> numbers[i];
		array[i] = new int[numbers[i]];
	}
	//Input values in array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < numbers[i]; j++)
		{
			cout << "Row " << i << ":- Enter value " << i*numbers[i] + j << ": ";
			cin >> array[i][j];
		}
	}
	//Output values of array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < numbers[i]; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}


// Enter no of rows of array: 3
// Enter no. of cols in row 0: 4
// Enter no. of cols in row 1: 3
// Enter no. of cols in row 2: 2
// Row 0:- Enter value 0: 6
// Row 0:- Enter value 1: 4
// Row 0:- Enter value 2: 9
// Row 0:- Enter value 3: 3
// Row 1:- Enter value 3: 8
// Row 1:- Enter value 4: 6
// Row 1:- Enter value 5: 2
// Row 2:- Enter value 4: 4
// Row 2:- Enter value 5: 5
// 6 4 9 3
// 8 6 2
// 4 5