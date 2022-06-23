#include <iostream>
#include "./util/random.h"

using namespace  std;
using namespace leveldb;
int main() {
    /*测试s[-1]
    char* s = "abcd";
    while(*s++ != 'd') {
        cout << s[-1] <<endl;
    */
   //测试random
    uint32_t s = 102;
    Random random(s);
    cout << random.Next() <<endl;
    cout << random.Next() <<endl;
    cout << random.Uniform(10) <<endl;

    for (int i=0; i<=60; ++i) {
        cout << random.OneIn(10) <<endl;
    }

        for (int i=0; i<=60; ++i) {
        cout << random.Skewed(3) <<endl;
    }
    
}