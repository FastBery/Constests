#include <iostream>
using namespace std;

struct IntRange
{
    int *begin;
    int *end;
};

void swap(int *x,int* y){
    int a = *x;
    *x = *y;
    *y = a;
}

void siftDown(IntRange range, int i){
    int n = range.end - range.begin;
    while (2 * i + 1 < n){    // heapSize — количество элементов в куче
        int left = 2 * i + 1;             // left — левый сын
        int right = 2 * i + 2;            // right — правый сын
        int j = left;
        if (right < n and range.begin[right] > range.begin[left]){
            j = right;
        }
        if (range.begin[i] >= range.begin[j]){
            break;
        }
        swap(&range.begin[i], &range.begin[j]);
        i = j;
    }
}

void siftUp(IntRange range, int i){
    while (range.begin[i] < range.begin[(i - 1) / 2]){     // i  0 — мы в корне
        swap(&range.begin[i], &range.begin[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void make_heap(IntRange range){
    int i = range.end - range.begin;
    i /= 2;
    while(i > -1){
        siftDown(range,i);
        i--;
    }
}

void heap_sort(IntRange range){
    make_heap(range);
    int n = range.end - range.begin;
    for (int i=0; i<n; i++){
        swap(&range.begin[0],range.end - 1);
        range.end--;
        siftDown(range,0);
    }
}

void heap_select(IntRange range,int *p){
    IntRange range2 = {range.begin,p+1};
    make_heap(range2);
    for(int *i=range.end-1;i>p;i--){
        if(*i<range.begin[0]){
            swap(i,&range.begin[0]);
            siftDown(range2,0);
        }
    }
    swap(p,&range.begin[0]);
    //swap(p,range.end-1);
}

// void heap_select(IntRange range,int *p){
//     IntRange range2 = {range.begin,p+1};
//     make_heap(range2);
//     for(int *i=range.end-1;i>p;i--){
//         swap(i,&range.begin[0]);
//         siftDown(range2,0);
//     }
//     swap(p,&range.begin[0]);
//     //swap(p,range.end-1);
// }

int main(){
    int n;
    cin >> n;
    int m[n];
    for (int i=0;i<n;i++){
        cin >> m[i];
    }
    IntRange range = {&m[0],&m[0] + n};
    // make_heap(range);
    
    // for (auto now:m){
    //     cout << now;
    // }
    cout<<endl;
    int *p = &m[0];
    heap_select(range,p);
    for (auto now:m){
        cout << now;
    }
    cout << endl;
    heap_sort(range);
    
    for (auto now:m){
        cout << now;
    }
}