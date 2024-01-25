#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

#ifndef ORDERED_H_
#define ORDERED_H_

class Ordered {

public:

	/**
	 * Complete this method that returns the distinct numbers in an array in sorted
	 * order using a set. You must use a set. You must achieve O(len * log (len)) complexity.
	 */
	static vector<int> alphabet(int *arr, int len) {
    //Note that the ordered set will essentially solve this straightaway. So, create an ordered set and just take all the numbers from the array and insert them one-by-one into the ordered set. 
      set<int, less<int> > orderedSet;
      for(int i = 0; i < len; i++)
        {
          orderedSet.insert(arr[i]); 
        }

    //Since sets will only keep unique numbers, you are pretty much done – all duplicates have been removed. Just an use iterator on the set to retrieve the numbers one-by-one, and insert them into a dynamic array.
    
      vector<int> dynamicArray;
      for(set<int>::iterator i = orderedSet.begin(); i != orderedSet.end(); i++)
        {
          //cout<<*i<<" "; //Prints out DONT NEED THIS
          dynamicArray.push_back(*i); //Inserts the printed out numbers into the Dynamic Array

        }

    //Once all numbers have been added, return the dynamic array.
      return dynamicArray;
    
	}

	/**
	 * This method checks if the argument array arr contains a subarray whose sum is
	 * zero. You must use a map for this method. You must achieve O(len * log (len)) time.
	 * If such a zero array exists, this method will return its start and end indexes, else return NULL.
	 */
	static int *zeroSumSubArray(int *arr, int len) {
    //Create an integer-integer ordered map.
      map<int, int> myMap;

    //Initialize prefixSum to 0
      int prefixSum = 0;

    //Traverse through the array and do the following:
      for(int i = 0; i < len; i++)
        {
          //Update prefixSum by adding the current number in the array to i
            //EXAMPLE - myMap[key] = value; So something like that 
            prefixSum = prefixSum + arr[i];  

          //If prefixSum is zero, then there is obviously a zero-sum array starting at index 0 and ending at the current index. So, simply return these indexes in an array of length 2 – first 0 and then the current index. – Now, check if the ordered map contains the prefix sum as a key. If it does, then retrieve the value from the ordered map (which is essentially the index of the last occurrence of the same prefix sum). Also, return the appropriate indexes in an array of length 2. Read the section before the pseudo-code to figure out what “appropriate indexes” means.
              if(prefixSum == 0)
                {
                  int *arr2 = new int[2] {0, i};
                  return arr2; //Returns current index
                                  
                }
              
              if(myMap.find(prefixSum) != myMap.end())
                {
                  int val = myMap[prefixSum] + 1;
                  int *arr3 = new int[2] {val,i};
                  return arr3;
                }

          //A match with prefix sum was not found. So, insert the current index as value with the prefix sum as key into the ordered set.
            myMap[prefixSum] = i; 
        }
      

    //You never found a zero-sum sub-array; so, return null.
      return NULL;
	}
};

#endif /* ORDERED_H_ */
