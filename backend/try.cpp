#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

int main(){

    int r = rand();
    random_device rd;
    mt19937_64 gen(rd());
    cout<<gen()<<endl;
    // uniform_int_distribution
    cout<<r<<endl;

    return 0;
}
