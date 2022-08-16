#ifndef LINECOUNTER_INCLUDE_APPLICATION_BASE_APPLICATION_H
#define LINECOUNTER_INCLUDE_APPLICATION_BASE_APPLICATION_H

namespace application {

/// IRunnable - general start application interface
class IRunnable {
public:
    virtual ~IRunnable() = default;
    virtual int run(int argc, char *argv[]) = 0;
};

} // namespace application

#endif //LINECOUNTER_INCLUDE_APPLICATION_BASE_APPLICATION_H
