#include <iostream>
using namespace std;
int probabilitySearch(int arr[],int n,int target){
    int i=0;
    while(i<n){
        if(arr[i]==target){
            if(i>0){
                int temp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
            }
            return i;
        }
        i++;
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
    int result=probabilitySearch(arr,n,target);
    if(result!=-1){
        cout<<"Element found at index "<<result<<" and position "<<result+1<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}