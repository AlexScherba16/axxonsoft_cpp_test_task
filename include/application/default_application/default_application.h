#ifndef LINECOUNTER_INCLUDE_APPLICATION_DEFAULT_APPLICATION_DEFAULT_APPLICATION_H
#define LINECOUNTER_INCLUDE_APPLICATION_DEFAULT_APPLICATION_DEFAULT_APPLICATION_H

#include "application/base_application.h"
#include <string>

namespace application {
namespace default_application {

/// DefaultApplication - the simplest application class
class DefaultApplication final : public IRunnable {
protected:
    std::string _tag;
public:
    DefaultApplication();
    ~DefaultApplication() = default;
    int run(int argc, char *argv[]) override;
};

} // namespace default_application
} // namespace application

#endif //LINECOUNTER_INCLUDE_APPLICATION_DEFAULT_APPLICATION_DEFAULT_APPLICATION_H
