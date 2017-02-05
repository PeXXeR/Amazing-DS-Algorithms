/*
	Given two arrays of positive integers and no duplicates,
	find common elements in the both arrays
*/

#include <iostream>

using namespace std;


// Method 1 : It is a brute force method where we compare
// each element of array 1 with each element of array 2
int bruteForceMethod (int *p1, int *p2, int len1, int len2)
{
	int numCommon = 0;

	for (int i=0; i<len1; ++i)
	{
		for (int j=0; j<len2; ++j)
		{
			if (p1[i] == p2[j])
				numCommon++;
		}
	}
	return numCommon;
}

int main(int argc, char const *argv[])
{
	// Take sizes of arrays as input
	cout<<"Enter the size of both arrays respectively : "<<endl;
	int size1, size2;
	cin>>size1>>size2;


	// Initialize two arrays and array elements as inputs from user
	int a1[size1], a2[size2];
	cout<<"=== Enter elements of two arrays ==="<<endl;
	for (int i=0; i<size1; i++)
		cin>>a1[i];

	for (int i=0; i<size2; i++)
		cin>>a2[i];


	// Pass the arrays to function which returns number of common elements present
	int common = bruteForceMethod (a1, a2, size1, size2);

	cout<<"The number of common elements is : "<<common<<endl;

	return 0;
}

