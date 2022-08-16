#ifndef LINECOUNTER_INCLUDE_COUNTER_BASE_COUNTER_H
#define LINECOUNTER_INCLUDE_COUNTER_BASE_COUNTER_H

#include <stdint.h>

namespace counter {

/// ICounter - general item counter interface
class ICounter {
public:
    virtual ~ICounter() = default;
    virtual uint64_t count() = 0;
};

} // namespace counter

#endif //LINECOUNTER_INCLUDE_COUNTER_BASE_COUNTER_H
