//
//  slidingwindowRatelimiter.cpp
//  myratelimiter
//
//  Created by DYJ on 10/12/21.
//

#include "slidingwindowRatelimiter.hpp"

SlidingWindowRateLimiter::SlidingWindowRateLimiter(int ratePerMinute):cursor(0), ratePerMinute(ratePerMinute) {
    
    arr = std::vector<LONG>(ratePerMinute, 0);
}

SlidingWindowRateLimiter::~SlidingWindowRateLimiter(){}


bool SlidingWindowRateLimiter::tryAdd(int cnt) {
    LONG time_ms = timeSinceEpochMillisec();
    if (time_ms - this->arr[cursor] < MINUTE_IN_MILLI_SEC) {
        return false;
    }
    this->arr[cursor] = time_ms;
    increaseCursor();
    return true;
}

LONG SlidingWindowRateLimiter::timeSinceEpochMillisec() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
