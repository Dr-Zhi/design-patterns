//
//  Singleton.h
//  design-patterns
//
//  Created by Yanling Zhi on 5/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __design_patterns__Singleton__
#define __design_patterns__Singleton__

#include <mutex>

using std::mutex;

/** Meyers implementation. 
 * Question: is it thread-safe? In C++11, it IS indeed based on standard:
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
    
    // intentionally not implement copy constructor and assignment.
    // they are meaningless for singleton, right?
    Singleton (const Singleton &);
    void operator=(const Singleton &);
};

/** Single implemented in a double-checked locking way.
 * It is strongly recommended using a static initializer (shown above).
 * double-checked locking method is still not guaranteed thread-safe, and
 * memory barrier is needed to further improve that.
 * Ref:
 * http://trevinca.ei.uvigo.es/~formella/doc/cd11/meyers-2004-perils.pdf
 * http://docs.huihoo.com/ace_tao/double_checked_locking.html
 * http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/
 */
class SingletonDLC {
public:
    static SingletonDLC * instance() {
        if (s)
            return s;
        
        mtx.lock();
        if (!s) {
            s = new SingletonDLC;
        }
        mtx.unlock();
        return s;
    }
    
private:
    SingletonDLC();
    SingletonDLC(const SingletonDLC &);
    void operator=(const SingletonDLC &);

    static SingletonDLC * s;
    static mutex mtx;
};

#endif /* defined(__design_patterns__Singleton__) */
