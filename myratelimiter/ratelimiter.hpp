//
//  ratelimiter.hpp
//  myratelimiter
//
//  Created by DYJ on 10/12/21.
//

#ifndef ratelimiter_hpp
#define ratelimiter_hpp

#include <stdio.h>

class MyRateLimiter {
public:
    MyRateLimiter(){};
    
    MyRateLimiter(int ratePerMinute):ratePerMinute(ratePerMinute){};
    
    ~MyRateLimiter(){};

    virtual bool tryAdd(int cnt) = 0;

    int getRatePerMinute() {
        return ratePerMinute;
    }

private:
    int ratePerMinute;
};

#endif /* ratelimiter_hpp */
