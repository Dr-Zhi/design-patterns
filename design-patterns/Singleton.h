//
//  Singleton.h
//  design-patterns
//
//  Created by Yanling Zhi on 5/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __design_patterns__Singleton__
#define __design_patterns__Singleton__

/** Meyers implementation. 
 * Q1: is it thread-safe? In C++11, it is, according to standard:
 * If control enters the declaration concurrently while the variable
 * is being initialized, the concurrent execution shall wait for 
 * completion of the initialization.
 *
 * References:
 * [1] http://stackoverflow.com/questions/1661529/is-meyers-implementation-of-singleton-pattern-thread-safe
 */
class Singleton {
public:
    inline static Singleton * instance() {
        static Singleton s;
        return &s;
    }
    
private:
    Singleton() {}
    Singleton (const Singleton &);
    void operator=(const Singleton &);
};

#endif /* defined(__design_patterns__Singleton__) */
