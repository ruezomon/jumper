#include <stdexcept>
#include <string>

namespace ruezo {
    class InitializeException : public std::runtime_error {
    private:
        int errorCode;
    public:
        inline InitializeException(std::string msg, int errorCode) : 
            std::runtime_error(msg), errorCode(errorCode) {}
        inline int getErrorCode() const noexcept { return this->errorCode; }
    };
}