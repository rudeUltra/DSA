//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int pivot=partition(arr,low,high);
            //divide based on the partition index siu
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // help.
       int pivot=arr[low]; //let's take the last element siu
       
       int i=low;
       int j=high;
       
       while(i<j){
           //find small in left and big in right then swap siu>
           while(i<=high-1 && arr[i]<=pivot){
               ++i;
           }
           while(j>=low+1 && arr[j]>pivot){
               --j;
           }
           
           if(i<j){
               //swap
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
               
               
           }
       }
       
       
       int temp=arr[low];
       arr[low]=arr[j];
       arr[j]=temp;
       return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends