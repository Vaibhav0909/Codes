#include<bits/stdc++.h>
using namespace std;
void Merge(int *arr,int l,int r)
{
    int mid = (l+r)/2;
    int i=l;
    int j = mid+1;
    int k=l;
    int temp[10000];
    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
            {
                temp[k++] = arr[i++];
            }
        else
            {
                temp[k++] = arr[j++];
            }
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=r)
        temp[k++] = arr[j++];
    for(int i=l;i<=r;i++)
        arr[i] = temp[i];
}
void Mergesort(int arr[],int low,int high)
{
    if(low>=high)
         return;
    int mid = low+high/2;
    Mergesort(arr,low,mid);
    Mergesort(arr,mid+1,high);
    Merge(arr,low,high);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    Mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}
