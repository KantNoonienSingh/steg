/* cipher_ctl.hpp -- v1.0 -- used for libgcrypt cipher generation
   Author: Sam Y. 2021 */

#ifndef _CIPHER_CTL_HPP
#define _CIPHER_CTL_HPP

namespace steg {
    // Fwd. decl.
    struct cipher;

    /// Closes cipher and deallocates memory
    void cipher_close(cipher& cipher);

    /// Factory method, used for class initialization
    /// @param key: AES key
    /// @param initvec: initialization vector
    /// @return on success, return a non-null pointer to an initialized object
    cipher* cipher_init(const char* const key, const char* const initvec);
}

#endif
