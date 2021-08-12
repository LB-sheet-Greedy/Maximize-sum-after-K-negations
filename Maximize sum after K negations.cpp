/*
Approach (Using Sort): 

>> we will first sort the given array

>> Then for a given value of k we will continue to iterate through the array till k remains greater than 0, 
   If the value of the array at any index is less than 0 we will change its sign and decrement k by 1.

>> If we find a 0 in the array we will immediately set k equal to 0 to maximize our result.

>> In some cases, if we have all the values in an array greater than 0 we will change the sign of positive 
   values, as our array is already sorted we will be changing signs of lower values present in the array which will
   eventually maximize our sum.
   
   Input : arr[] = {-2, 0, 5, -1, 2} 
        K = 4
Output: 10
Explanation:
1. Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
2. Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
3. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
4. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
   
   
Time Complexity: O(n*logn) 
Auxiliary Space: O(1)

  

*/

#include <bits/stdc++.h>
using namespace std;

int sol(int arr[], int n, int k)
{
    int sum = 0;
    int i = 0;
   
    // Sorting given array using in-built sort function
    sort(arr, arr + n);
    
    cout<<"\nSorted array => \n";
    for(int i=0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
	}
    
    //jo changes hoge vo starting ke elements ke saath hi hoge and apne ko exactly k times modify karna hi hai
    while (k > 0)
    {
        // If we find a 0 in our
        // sorted array, we stop
        if (arr[i] >= 0)
            k = 0;
        else
        {
            arr[i] = (-1) * arr[i];
            k = k - 1;
        }
        i++;
        
    }
    cout<<"\nWhile loop breaks at k="<<k;
 
    // Calculating sum
    for(int j = 0; j < n; j++)
    {
        sum += arr[j];
    }
    cout<<"\n";
    return sum;
}

// Driver code
int main()
{
    int arr[] = {9, 8, 8, 5};
 
    int n=sizeof(arr) / sizeof(arr[0]);
    int k=3;
     
    cout << sol(arr, n, 4) << endl;
 
    return 0;
}


