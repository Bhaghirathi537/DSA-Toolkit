#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            int flag=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=flag;
            j=j-1;
        }
        arr[j+1]=temp;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
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
    cout<<"AFTER SORTING"<<endl;
    insertionSort(arr,n);
    cout<<"FINAL ARRAY:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}