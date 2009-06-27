#ifndef CipherException_class
#define CipherException_class

#include <string>

namespace odns {
    namespace internal {

        class CipherException {
        public:
            CipherException ( std::string s ) : m_s ( s ) {};
            ~CipherException (){};

            std::string description() { return m_s; }

        private:

            std::string m_s;
        }; // CipherException

    } // namespace internal
} // namespace odns
#endif

