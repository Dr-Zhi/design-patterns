//
//  Singleton.h
//  design-patterns
//
//  Created by Yanling Zhi on 5/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __design_patterns__Singleton__
#define __design_patterns__Singleton__

#include <iostream>

class Singleton {
public:
    static Singleton * instance() {
        static Singleton s;
        return &s;
    }
private:
    Singleton() {}
    Singleton (const Singleton &);
    void operator=(const Singleton &);
};

#endif /* defined(__design_patterns__Singleton__) */
