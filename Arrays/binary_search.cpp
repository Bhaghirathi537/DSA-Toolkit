#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else{
            if(target<arr[mid]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int *arr,n,target;
    cout<<"Enter no.of elements:";
    cin>>n;
    arr=new int[n];
    cout<<"Fill the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>arr[i];
    }
    cout<<"Enter the target:";
    cin>>target;
    int result=binarySearch(arr,n,target);
    if(result!=-1){
        cout<<"Element found at index "<<result<<" and position "<<result+1<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}