#ifndef LINECOUNTER_INCLUDE_EXCEPTION_GENERAL_EXCEPTION_H
#define LINECOUNTER_INCLUDE_EXCEPTION_GENERAL_EXCEPTION_H

#include <sstream>

namespace exception {

/// GeneralException - std::exception wrapper
/// contains information about the source of the exception and the error that occurred
class GeneralException : public std::exception {
private:
    std::string _text;

public:
    GeneralException() = delete;
    GeneralException(const std::string& source, const std::string& text) noexcept {
        std::stringstream strm;
        strm << "exception from [" << source << "] message : " << text;
        _text = strm.str();
    };

    const char * what() const noexcept override {
        return _text.c_str();
    }
};

} // namespace exception


#endif //LINECOUNTER_INCLUDE_EXCEPTION_GENERAL_EXCEPTION_H
