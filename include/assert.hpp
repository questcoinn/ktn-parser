#ifndef _KTN_ASSERT_HPP_
#define _KTN_ASSERT_HPP_

#include <exception>
#include <iostream>

#define ASSERT(CONDITION, MESSAGE) \
    do { \
        if(!(CONDITION)) { \
            std::cerr \
                << "Assertion `" #CONDITION "` failed in " << __FILE__ \
                << " line " << __LINE__ << ": " << (MESSAGE) << "\n"; \
            std::terminate(); \
        } \
    } while(0)

#endif
