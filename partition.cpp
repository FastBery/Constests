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

int *partition(IntRange range, auto p){
    int *l = range.begin;
    int *h = range.end;
    int n= range.end - range.begin;
    while (true){
        while(p(*l) && l<range.end){
            l++;
        }
        while(p(*h) && h>range.begin){
            h--;
        }
        if(h>l){
            swap(l,h)
        }
        else{
            return l;
        }
    }
}