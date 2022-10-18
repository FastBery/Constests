#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

int main(){
    // int n;
    // std::cin >> n;
    std::vector <int> v;
    int x;
    while(std::cin>>x){
        v.push_back(x);
    }
    std::sort(v.begin(),v.end(),std::greater<int>());
    for(auto now : v){
        std::cout << now << " ";
    }
}