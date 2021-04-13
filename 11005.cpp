#include<iostream>
#include<algorithm>
using namespace std;
 
void BinarySearch(int *arr, int start, int end, int searchNum){
     // 반복문을 통한 이진 탐색 
    int mid;
    
    while(end - start >= 0){
        mid = (start+end)/2;
        
        if(arr[mid] == searchNum){
            printf("1 \n");
            return;
        }else if(arr[mid] > searchNum){
            end = mid - 1;
        }else { // arr[mid] < searchNum
            start = mid + 1;
        }
    }
    
    printf("0 \n");
    return;
    
}
int main() {
    
    // https://www.acmicpc.net/problem/1920
    
    int n,m;
    scanf("%d", &n);
    
    int nArr[n];
    
    for(int i=0; i<n; i++)
        scanf("%d", &nArr[i]);
        
    sort(nArr, nArr + n ); 
 // sort 함수를 이용해 오름차순 정렬. sort(배열의 시작점 '주소', 배열의 마지막점 '주소');
    
    scanf("%d", &m);
    
    int tmp;
    int end = sizeof(nArr)/sizeof(nArr[0]);
        
    for(int i=0; i<m; i++){
        scanf("%d",&tmp);
        BinarySearch(nArr, 0, end, tmp);
    }
}