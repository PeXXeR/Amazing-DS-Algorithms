/*
 * CountZeroesInArray.cpp
 *
 * Given an input array with some number of contiguous zeroes at the start
 * followed by arbitrary integers other than zero. Find number of zeroes in the array.
 *
 *	array : 0 0 0 0 0 2 3 3 6 1 5
 *	output : 5 zeroes
 *
 *  Created on: 12-Mar-2017
 *      Author: coder
 */

#include <iostream>
#include <algorithm>

using namespace std;

// Method 1 :
// Simply iterate through the whole array and count number of zeroes.
// Break from loop as soon as something other than zero occurs.
// TC : O(n)
int simpleIterationAndCount1(int inputArray[], int sizeOfArray)
{
	int zeroCount = 0;
	for (int i=0; i<sizeOfArray; ++i)
	{
		if (inputArray[i] != 0)
			break;
		zeroCount++;
	}
	return zeroCount;
}
/******************************************************************************/

// Auxillary method to compute number of zeroes for Method 2
int auxBSearchMethod2 (int inputArray[], int sIndex, int lIndex)
{

	while (lIndex > sIndex)
	{
		int midIndex = (sIndex + lIndex)/2;

		if (inputArray[midIndex] != 0)
		{
			if (inputArray[midIndex - 1] == 0)
				return midIndex;
			lIndex = midIndex - 1;
		}
		else
		{
			if (inputArray[midIndex + 1] != 0)
				return midIndex+1;
			sIndex = midIndex + 1;
		}
	}
	return lIndex;
}

// Method 2 :
// Can we make use of contiguous thing and do better than O(n)
// If we find out last occurance of a 0 in array, we are good.
// Binary Search can be modified to do the job.
// TC : O(log n)
int binarySearchMethod2(int inputArray[], int sizeOfArray)
{
	if (sizeOfArray == 0)
		return 0;
	else if(sizeOfArray == 1)
		return inputArray[0] ? 0 : 1;
	else if(inputArray[sizeOfArray-1] == 0)
		return sizeOfArray;

	// Calling auxillary function to compute rest part as user will only provide two things
	return auxBSearchMethod2(inputArray, 0 /* start index */, sizeOfArray-1 /*end index */);
}

/******************************************************************************/

int main() {
	cout<<"=== Enter the number of elements in array ==="<<endl;
	int n;
	cin>>n;

	int a[n];
	cout<<"\n Enter "<<n<<" array elements with zeroes followed by other integers ..."<<endl;
	for (int i=0; i<n; i++)
		cin>>a[i];

	//int zeroCount = simpleIterationAndCount1(a, n);
	int zeroCount = binarySearchMethod2(a, n);

	cout<<"\n The number of ZEROES in given array is : "<<zeroCount<<endl;
	return 0;
}
