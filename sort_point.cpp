#include <iostream>
using namespace std;

struct IntRange
{
    int *begin;
    int *end;
}; 

void sort(IntRange range){
    int n;
    n = range.end - range.begin;
    cout << n << endl;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if ( *(range.begin + j) < *(range.begin + i) ){
                int x = *(range.begin + i);
                *(range.begin + i) = *(range.begin + j);
                *(range.begin + j) = x; 
            }
        }
    }
}

int main(){
    int n = 5;
    int m[5];
    cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
    IntRange da;
    da.begin = &m[0];
    da.end = &m[5];
    sort(da);

    cout << *da.begin << *(da.begin+1) << *(da.begin+2) << *(da.begin+3) << *(da.begin+4);
}