#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

#ifndef UNORDERED_H_
#define UNORDERED_H_

class Unordered {

public:

	/*
	 * Complete this method that returns the duplicates, i.e., the numbers present
	 * in both arr1 and arr2. You must use an unordered_set for this method.
	 * You must achieve complexity O(len1 + len2)
	 */
	static vector<int> findDuplicates(int *arr1, int *arr2, int len1,
			int len2) {
        //This is similar to the alphabet finder stuff. The difference is that you will use an unordered set and duplicates are across arrays.  
        //First create two integer unordered sets – checker and duplicates.
          unordered_set<int> checker;
          unordered_set<int> duplicates;

        //Take all the numbers from one of the arrays and insert them one-by-one to checker
          for(int i = 0; i < len1; i++)
            {
              checker.insert(arr1[i]);
            }

        //Now, loop over the other array. If a number in this array is present in checker, then this number is a duplicate; so, insert it into duplicates.
          for(int i = 0; i < len2; i++)
            {
              if(checker.find(arr2[i]) != checker.end())
                {
                  duplicates.insert(arr2[i]); 
                }
            }

        //Once you are done, duplicates, being a set, will contain a duplicate number once. So, at this point, iterate through duplicates and add the numbers to a dynamic array.
          vector<int> dynamicArray;
          for(unordered_set<int>::iterator i = duplicates.begin(); i != duplicates.end(); i++)
            {
              //cout<<*i<<" "; //Dont need this
              dynamicArray.push_back(*i);
            }

        //Finally, return the dynamic array.
          return dynamicArray;
	}


//Frequencies Method Function
static unordered_map<char, int> frequencies(string str)
  {
    //Need an unordered_map
    //Loops through the length of parameter string
      unordered_map<char, int> unorderedMap;
      for(int i = 0; i < str.size(); i++)
        {
          //See if str is in the unordered_map
            if(unorderedMap.find(str[i]) != unorderedMap.end())
              {
                //str = 1
                  unorderedMap[str[i]] = 1;
              }
            else
              {
                //Increment str
                  unorderedMap[str[i]]++;
              }
        }

      return unorderedMap;

  }


	/**
	 * Complete this method that checks if str1 is an anagram of str2.
	 * You must use an unordered_map for this method.
	 * You must achieve complexity O(|str1| + |str2|).
	 */
	static bool areAnagrams(string &str1, string &str2) {
    
    //If two strings are of different length, they cannot be anagrams of each other. So, return false if they are of unequal lengths.
      if(str1.size() != str2.size())
        {
          return false;
        }
    
    //Call the frequency method that you have written to obtain the frequencies of each character in each string and store them in two unordered maps.
      unordered_map<char, int> unorderedMap1 = frequencies(str1);
      unordered_map<char, int> unorderedMap2 = frequencies(str2);
        
    //Now, loop over the string.
    //If the current character in the string is not in the map as a key,
    for(int i = 0; i < str1.size(); i++)
      {
        if(unorderedMap1[str1[i]] != unorderedMap2[str1[i]])
        {
          //If these frequencies are different, then the strings are not anagrams of each other.So, return false
            return false;
        }
      
        if(unorderedMap1[str2[i]] != unorderedMap2[str2[i]])
          {
            //If these frequencies are different, then the strings are not anagrams of each other.So, return false
              return false;
          }
      }
  //Once the loop has terminated, you have ensured that all characters in the first string also occur in the second string; moreover, they have the same frequencies in both the strings. Also, the strings are of equal length; so, the second string does not contain a character which is not present in the first string. So, the strings must be anagrams of each other – return true.
    return true;    
	}
  
};

#endif /* UNORDERED_H_ */
