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

template<typename Predicate>
int *partition(IntRange range, Predicate p){
    int *l = range.begin;
    int *h = range.end - 1;
    //int n= range.end - range.begin;
    while (true){
        while(l<range.end && p(*l) == true){
            l++;
        }
        while(h>range.begin && p(*h) == false){
            h--;
        }
        if(h>l){
            swap(l,h);
        }
        else{
            return l;
        }
    }
}

void quicksort(IntRange range){
    if (range.begin == range.end){return;}
    int y = range.begin[0];
    auto middle1 = partition(range,[y](int x){return x < y;});
    // IntRange r = {middle1,range.end};
    auto middle2 = partition({middle1,range.end},[y](int x){return x == y;});
    quicksort ({range.begin,middle1});
    quicksort ({middle2,range.end});
}

void quickselect(IntRange range,int *ptr){
    if (range.begin == range.end){return;}
    int y = range.begin[0];
    auto middle1 = partition(range,[y](int x){return x < y;});
    // IntRange r = {middle1,range.end};
    auto middle2 = partition({middle1,range.end},[y](int x){return x == y;});
    if(ptr>=middle2){
        quickselect ({middle2,range.end},ptr);
    }
    else{
        if(ptr>middle1 and ptr<middle2){
            return;
        }
        else{
            quickselect ({range.begin,middle1},ptr);
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    int m[n];
    for (int i=0;i<n;i++){
        cin >> m[i];
    }
    IntRange r = {&m[0],&m[0] + n};
    int *p = &m[4];
    quickselect(r,p);
    for (auto now : m){
        cout << now << " ";
    }
}