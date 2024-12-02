#include <iostream>
#include <ctime>

using namespace std;

void part1(){

};

int main(){
    // start a timer
    clock_t start;
    start = clock();

    part1();
    
    // stop the timer
    cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms "  << endl;
    return 0;
}