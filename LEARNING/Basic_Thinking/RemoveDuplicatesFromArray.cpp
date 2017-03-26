// Program to remove duplicate elements from a given array

#include <iostream>
#include <set>
#include <cstdlib>
#include <climits>
#include <algorithm>


using namespace std;

int nDistinct = 0;

// Method 1 : Here, we are modifying the given array itself.
// TC : O(n*n + n)
int * bruteForceMethod1 (int *inArray, int sizeOfArray)
{
    for (int i=0; i<sizeOfArray-1; ++i)
    {
        if (inArray[i] != INT_MIN)
        {
            ++nDistinct;
            for (int j=i+1; j<sizeOfArray; ++j)
            {
                if (inArray[i] == inArray[j])
                    inArray[j] = INT_MIN;
            }
        }
    }

    // Make a new array to return of size nDistinct
    int *ptr = new int[nDistinct];
    int j = 0;
    for (int i=0; i<sizeOfArray; ++i)
    {
        if (inArray[i] != INT_MIN)
        {
            ptr[j++] = inArray[i];
        }
    }
    return ptr;
}

// Method 2 :
// Sort the array so that common elements come near to each other. Then, remove
// TC : O(nlogn + n + n)
int * sortAndRemoveDuplicates2 (int *inArray, int sizeOfArray)
{
    sort(inArray, inArray+sizeOfArray);

    for (int i=0; i<sizeOfArray; ++i)
    {
        if (inArray[i] != INT_MIN)
        {
            ++nDistinct;
            int j = i+1;
            while (j<sizeOfArray && inArray[i] == inArray[j])
            {
                inArray[j] = INT_MIN;
                ++j;
            }
        }
    }

    // Make a new array to return of size nDistinct
    int *ptr = new int[nDistinct];
    int j = 0;
    for (int i=0; i<sizeOfArray; ++i)
    {
        if (inArray[i] != INT_MIN)
        {
            ptr[j++] = inArray[i];
        }
    }
    return ptr;
}

// Method 3 :
// Store array elements in a set which doesn't allow duplicates and then, copy from set to output array
// TC : O(n + n), SC : O(n)
int * useSetAndRemoveDup3 (int *inArray, int sizeOfArray)
{
    set<int> mySet;
    for (int i=0; i<sizeOfArray; ++i)
        mySet.insert(inArray[i]);

    // Make a new array to return of size nDistinct
    int *ptr = new int[mySet.size()];
    int j = 0;
    for (set<int>::iterator it=mySet.begin(); it != mySet.end(); ++it)
    {
        ptr[j++] = *it;
        ++nDistinct;
    }

    return ptr;
}

int main()
{
    cout<<"Please enter the number of elements in ARRAY ==="<<endl;
    int n;
    cin>>n;

    int myArray[n];         // My array of size n

    srand(time(NULL));    // Pass the initial seed value
    // We are creating an array of elements from 1 to 10 only
    for (int i=0; i<n; i++)
        myArray[i] = rand()%10 + 1;

    cout<<"=== Displaying array BEFORE duplicate removal ==="<<endl;
    for (int i=0; i<n; i++)
        cout<<myArray[i]<<" ";

    cout<<"\n### Displaying array AFTER duplicate removal ###"<<endl;
    // Since, we are passing an array to a function which removes duplicates so size will change.
    // Hence, our function returns new array
    int *outArray = useSetAndRemoveDup3(myArray, n);
    for (int i=0; i<nDistinct; ++i)
        cout<<outArray[i]<<" ";
}
