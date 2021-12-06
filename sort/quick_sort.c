#include<stdio.h>
#define MAXSIZE 10
int patrition(int* nums,int low,int high){
    int tmp = nums[low];
    while(low<high){
        while(high>low&&nums[high]>=tmp)
            high--;
        nums[low]  = nums[high];
        while(low<high&&nums[low]<=tmp)
            low++;
        nums[high] = nums[low];
    }
    nums[low] = tmp;
    return low;//下一次将数组一分为2的分界点
}

void quick_sort(int* nums,int low,int high){
    int mid;
    if(low<high){
        mid = patrition(nums,low,high);
        quick_sort(nums,low,mid-1);
        quick_sort(nums,mid+1,high);
    }
}

void print_nums(int* nums){
	for(int i=0;i<MAXSIZE;i++){
		printf("%d\t",nums[i]);
	}
	printf("\n");
}

int main(){
    int nums[MAXSIZE]={48,38,65,97,76,13,27,49,9,45};
    quick_sort(nums,0,MAXSIZE-1);
    print_nums(nums);
    return 0;
}
