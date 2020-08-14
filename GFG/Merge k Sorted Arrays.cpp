// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k)
{
//code here
    int* res = (int*)malloc(sizeof(int) * k * k);
    
    priority_queue< pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>>pq;
    
    //curr idx of each arr
    vector<int> idx(k, 0);
    
    for(int i=0; i<k; i++)
    {
        pq.push({arr[i][0], i});
    }
    
    for(int i=0; i<k*k; i++)
    {
        int ele = pq.top().first;
        int arr_number = pq.top().second;
        
        pq.pop();
        
        res[i] = ele;
        
        if(idx[arr_number] < k-1)
        {
            idx[arr_number]++;
            pq.push({arr[arr_number][idx[arr_number]], arr_number});
        }
    }
    
    return res;
    
}