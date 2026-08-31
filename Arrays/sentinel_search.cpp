#include <iostream>
using namespace std;
int sentinelSearch(int arr[],int n,int target){
    int last=arr[n-1];
    arr[n-1]=target;
    int i=0;
    while(arr[i]!=target){
        i++;
    }
    arr[n-1]=last;
    if(i<n-1 || arr[n-1]==target){
        return i;
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
    int result=sentinelSearch(arr,n,target);
    if(result!=-1){
        cout<<"Element found at index "<<result<<" and position "<<result+1<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}
