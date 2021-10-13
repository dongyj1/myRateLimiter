//
//  slidingwindowRatelimiter.hpp
//  myratelimiter
//
//  Created by DYJ on 10/12/21.
//

#ifndef slidingwindowRatelimiter_hpp
#define slidingwindowRatelimiter_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <cstdint>
#include "ratelimiter.hpp"
#define LONG uint64_t

class SlidingWindowRateLimiter : public MyRateLimiter {
public:
    
    SlidingWindowRateLimiter(int ratePerMinute);
    ~SlidingWindowRateLimiter();

    bool tryAdd(int cnt);
    
    LONG timeSinceEpochMillisec();

private:
    /* data */
    std::vector<LONG> arr;
    int ratePerMinute;
    int cursor;
    const int MINUTE_IN_MILLI_SEC = 60 * 1000;
    
    void increaseCursor() {
        cursor++;
        if (cursor == arr.size()) {
            cursor = 0;
        }
    }
};



#endif /* slidingwindowRatelimiter_hpp */
