//
//  ReferenceCounting.h
//  design-patterns
//
//  Created by Yanling Zhi on 5/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef __design_patterns__ReferenceCounting__
#define __design_patterns__ReferenceCounting__

#include <iostream>

template<class T>
class ReferenceCounting {
public:
    ReferenceCounting(const T & data) : _data(new T(data)),
    _referenceCount(new int(1)) {}
    
    ReferenceCounting(const ReferenceCounting & rhs) : _data(rhs._data),
    _referenceCount(rhs._referenceCount) {
        ++*_referenceCount;
    }
    
    ReferenceCounting & operator=(const ReferenceCounting & rhs) {
        if (_data == rhs._data) {
            return *this;
        }
        
        if (--*_referenceCount == 0) {
            delete _data;
            delete _referenceCount;
        }
        
        _data = rhs._data;
        _referenceCount = rhs._referenceCount;
        return *this;
    }
    
    ~ReferenceCounting() {
        if (--*_referenceCount == 0) {
            delete _data;
            delete _referenceCount;
        }
    }
private:
    T * _data;
    int * _referenceCount;
};

#endif /* defined(__design_patterns__ReferenceCounting__) */
