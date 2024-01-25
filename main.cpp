#include <iostream>
#include <string>
#include <algorithm>

#include "Ordered.h"
#include "Unordered.h"
using namespace std;

static string toString(int *arr, int length) {
	if (0 == length)
		return "[]";
	string output = "[";
	for (int i = 0; i < length - 1; i++) {
		output += to_string(arr[i]) + ", ";
	}
	output += to_string(arr[length - 1]) + "]";
	return output;
}

static string toString(vector<int> arr) {
	int length = arr.size();
	if (0 == length)
		return "[]";
	string output = "[";
	for (int i = 0; i < length - 1; i++) {
		output += to_string(arr[i]) + ", ";
	}
	output += to_string(arr[length - 1]) + "]";
	return output;
}

static void testAlphabet() {
	int arr[] = { -5, 10, 45, 13, 89, -18, 34, 78, 23, 25, -5, 13, 78, 101, 89,
			25 };
	int len = sizeof(arr) / sizeof(int);
	printf("Original array is %s\n", toString(arr, len).c_str());
	printf("Alphabet in sorted order is %s\n",
			toString(Ordered().alphabet(arr, len)).c_str());
}

static void testZeroSumHelper(int *arr, int len) {
	int *zero = Ordered().zeroSumSubArray(arr, len);
	printf("\n%s", toString(arr, len).c_str());
	if (NULL == zero || 0 == sizeof(zero))
		printf(" has no subarray whose sum is zero.");
	else
		printf(" has a subarray from index %d to index %d whose sum is zero.",
				zero[0], zero[1]);
}

static void testZeroSum() {
	int arr1[] = { 12, -26, 1, 8, 9, -6, 4, -12, -3, 12 };
	testZeroSumHelper(arr1, sizeof(arr1) / sizeof(int));
	int arr2[] = { 1, 7, 19, -14, 1, -14, 12 };
	testZeroSumHelper(arr2, sizeof(arr2) / sizeof(int));
	int arr3[] = { 1, 7, 19, -14, 1, -14, 8, 9, -6, 4, -12, -3, 12 };
	testZeroSumHelper(arr3, sizeof(arr3) / sizeof(int));
	int arr4[] = { -6, 4, -12, -3, 12 };
	testZeroSumHelper(arr4, sizeof(arr4) / sizeof(int));
	int arr5[] = { -6, 4, -12, 0, -3, 12 };
	testZeroSumHelper(arr5, sizeof(arr5) / sizeof(int));
	int arr6[] = { 0, -6, 4, -12, -3, 12 };
	testZeroSumHelper(arr6, sizeof(arr6) / sizeof(int));
	int arr7[] = { 1, 8, 9, -6, 4, -12, -3 };
	testZeroSumHelper(arr7, sizeof(arr7) / sizeof(int));
	int arr8[] = { 1, 8, 9, 0 };
	testZeroSumHelper(arr8, sizeof(arr8) / sizeof(int));
}

static void testDuplicates() {
	int arr1[] = { 1, 5, 6, 19, 5, 1, 56, 34, 1, 7, 12, 13, 20 };
	int arr2[] = { 6, 19, 13, 56, 12, 20, 20, 12, 6 };
	int arr3[] = { 55, 54, 23, 18, 98 };

	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);
	int len3 = sizeof(arr3) / sizeof(int);

	string arr1_str = toString(arr1, len1);
	string arr2_str = toString(arr2, len2);
	string arr3_str = toString(arr3, len3);

	vector<int> dup12 = Unordered().findDuplicates(arr1, arr2, len1, len2);
	vector<int> dup13 = Unordered().findDuplicates(arr1, arr3, len1, len3);
	sort(dup12.begin(), dup12.end());

	string dup12_str = toString(dup12);
	string dup13_str = toString(dup13);

	printf("\n\nDuplicates among %s and %s are %s\n", arr1_str.c_str(),
			arr2_str.c_str(), dup12_str.c_str());
	printf("Duplicates among %s and %s are %s\n", arr1_str.c_str(),
			arr3_str.c_str(), dup13_str.c_str());
}

static void testAnagram() {
	string str1 = "integral";
	string str2 = "triangle";
	printf("\n%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "integral";
	str2 = "trianglex";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "integral";
	str2 = "triannle";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "aabxxb#(cb";
	str2 = "a#xbxa(bcb";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "aabxxb#(cb";
	str2 = "zzbxxb#(cb";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "aabxxb#(cb";
	str2 = "aabxxb#acb";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "aabxxb#(cbfrbt%ybbuuahh##61$$)%";
	str2 = "abbh#abyxbfab%t%bxuu)h(##61c$r$";
	printf("%s and %s are anagrams of each other? %s\n", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");

	str1 = "aabxxb#(cbfrbt%ybbuuahh##61$$)%";
	str2 = "abbh#abyxbfab%t%bxvu)h(##61c$r$";
	printf("%s and %s are anagrams of each other? %s", str1.c_str(),
			str2.c_str(), Unordered().areAnagrams(str1, str2) ? "YES" : "NO");
}

int main() {
	testAlphabet();
	testZeroSum();
	testDuplicates();
	testAnagram();
	return 1;
}
