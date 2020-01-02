#include <bits/stdc++.h>

void printArray(int* arr,int n){
    for (int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}

void printVector(std::vector<int> arr){
    for (int i=0;i<arr.size();i++){
        std::cout<<arr.at(i)<<" ";
    }
}

void printAllSubsetsHelper(int* arr,int arraySize,std::vector<int> subsetArray,int index){
    if (index==arraySize){
        printVector(subsetArray);
        std::cout<<std::endl;
        return ;
    }

    printAllSubsetsHelper(arr,arraySize,subsetArray,index+1);
    subsetArray.push_back(arr[index]);
    printAllSubsetsHelper(arr,arraySize,subsetArray,index+1);
}

void printAllSubsets(int* arr,int arraySize){
    std::vector<int> subsetArray;
    printAllSubsetsHelper(arr,arraySize,subsetArray,0);
}

int main()
{
	int arr[]={1,2,3,4,5};
	printAllSubsets(arr,5);
	return 0;
}
