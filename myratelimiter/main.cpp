//
//  main.cpp
//  myratelimiter
//
//  Created by DYJ on 10/12/21.
//

#include <iostream>
#include "slidingwindowRatelimiter.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    SlidingWindowRateLimiter limiter(10);
    using namespace std;
    for (int i = 0; i < 11; i++) {
        cout << i << " " << limiter.tryAdd(1) << "\n";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
