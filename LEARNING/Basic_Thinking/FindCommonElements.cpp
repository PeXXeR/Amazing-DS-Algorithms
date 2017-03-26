/*
	Given two arrays of positive integers and no duplicates,
	find common elements in the both arrays
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;


// Method 1 : It is a brute force method where we compare
// each element of array 1 with each element of array 2
// Complexity = O(m * n)
int bruteForceMethod1 (int *p1, int *p2, int len1, int len2)
{
	int numCommon = 0;

	for (int i=0; i<len1; ++i)
		for (int j=0; j<len2; ++j)
			if (p1[i] == p2[j])
				numCommon++;

	return numCommon;
}

////////////////////////////////////////////////////////////////////////////////////////////

// Mehtod 2 : Sort both arrays and move pointers as per comparison
// Complexity = O(mlogm + nlogn + m+n)
int sortBothAndFind2 (int *p1, int *p2, int len1, int len2)
{
	sort(p1, p1+len1);
	sort(p2, p2+len2);

	int i = 0, j = 0, numCommon = 0;

	// Since arrays are sorted, if one element is greater than others,
	// than greater one is not likely to match with anyone else
	while (i < len1 && j < len2)
	{
		if ( p1[i] > p2[j])
			j++;
		else if (p1[i] < p2[j])
			i++;
		else
		{
			numCommon++;
			i++; j++;
		}
	}
	return numCommon;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Method 3: Sort only one array and apply binary search for each element of 2nd array
// Complexity = O(mlogm + nlogn)
int sortOneAndBSearch3 (int *p1, int *p2, int len1, int len2)
{
	sort (p1, p1+len1);

	int numCommon = 0;

	// Now, apply binary search for each element of p2
	for (int j=0; j<len2; j++)
	{
		if (binary_search(p1, p1+len1, p2[j]))
			++numCommon;
	}
	return numCommon;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Method 4 : Store elements of one array in a set and then, find if elements of
// other array are already in set or not
// Since, C++ set's give faster find, we can use them
// Maps can also be used
// Complexity = O(mlogm), Space = O(n)
int findInASet4 (int *p1, int *p2, int len1, int len2)
{
	int numCommon = 0;

	set<int> mySet;
	for (int i=0; i<len1; ++i)
		mySet.insert(p1[i]);

	for (int j=0; j<len2; ++j)
	{
		if (mySet.find(p2[j]) != mySet.end())
			numCommon++;
	}
	return numCommon;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	// Take sizes of arrays as input
	cout<<"Enter the size of both arrays respectively : "<<endl;
	int size1, size2;
	cin>>size1>>size2;

   // srand(time(NULL));

	// Initialize two arrays and array elements as inputs from user
	int a1[size1], a2[size2];
	cout<<"=== Enter elements of two arrays ==="<<endl;

	// To properly test the alogirhtm, arrays should be taken random
	// But, as this would contain duplicates. So, we currently take input from user only
	for (int i=0; i<size1; i++)
        cin>>a1[i];
    for (int i=0; i<size2; i++)
        cin>>a2[i];

/*
	for (int i=0; i<size1; i++)
		a1[i] = rand()%10 + 1;

	for (int i=0; i<size2; i++)
		a2[i] = rand()%10 + 1;

    // Display the filled random arrays
    for (int i=0; i<size1; i++)
        cout<<a1[i]<<" ";
    cout<<endl;
    for (int i=0; i<size2; i++)
        cout<<a2[i]<<" ";
*/

	// Pass the arrays to function which returns number of common elements present
	//int common = bruteForceMethod1 (a1, a2, size1, size2);

	//int common = sortBothAndFind2 (a1, a2, size1, size2);

	//int common = sortOneAndBSearch3 (a1, a2, size1, size2);

	int common = findInASet4 (a1, a2, size1, size2);

	cout<<"The number of common elements is : "<<common<<endl;

	return 0;
}

