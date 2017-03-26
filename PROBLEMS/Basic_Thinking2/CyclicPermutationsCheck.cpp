/*Write a program that two strings s1 and s2 as input and returns true if s2 is a
cyclic permutation of s1.

Input : s1 = "ABCD", s2="CDAB"
Output : True

Input : s1 = "ABCD", s2="ACBD"
Output : False*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// Here, we will make temp string = s1+s1.
// This tmp will surely contain s2 if it is cyclic permutation.
// TC: O(n)
bool addAndCheck2 (string s1, string s2)
{
	string tmp = s1 + s1;

	// Now, search s2 inside tmp string
	if (tmp.find(s2) != string::npos)
		return true;
	return false;
}

int main(int argc, char **argv) {
	cout<<"\n Enter two strings s1 and s2 as input : "<<endl;
	string s1, s2;

	cin>>s1>>s2;

	// Initial check
	if (s1.length() != s2.length()){
		cout<<"Alas :( . s2 is not Cyclic Permutation of s1."<<endl;
		return 0;
	}

	bool retVal = addAndCheck2(s1, s2);

	if (retVal)
		cout<<"Oh yes!!! s2 is Cyclic Permutation of s1."<<endl;
	else
		cout<<"Alas :( . s2 is not Cyclic Permutation of s1."<<endl;
}
