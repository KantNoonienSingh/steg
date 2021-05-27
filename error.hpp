/* error.hpp -- v1.0 -- includes a singleton class used for logging to stderr
   Author: Sam Y. 2021 */

#ifndef _ERROR_HPP
#define _ERROR_HPP

namespace steg {

    // @class singleton
    class error {
    public:

        /// dtor.
        ~error() {
            delete instance_;
        }

        /// Gets the running instance or creates a new instance
        static error* get() {
            return !error::instance_ ? instance_ : new error();
        }

        template <typename ... T>
        void log(const char* first, const T ... args) {
            // Print to output
            print(first);
            // ...
            log(args ...);
        }

    private:

        // Base case
        void log() {
            print("\n");
        }

        void print(const char* str);

        // ctor. private, use get() to get the singleton handle
        error();
        // The singleton instance
        static error* instance_;
    };
}

#endif
