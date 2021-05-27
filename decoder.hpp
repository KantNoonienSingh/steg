/* decoder.hpp -- v1.0 -- libgcrypt message decoding
   Author: Sam Y. 2021 */

#ifndef _DECODER_HPP
#define _DECODER_HPP

namespace steg {
    // Fwd. decl.
    struct cipher;

    /// @class: base
    class decoder {
    public:

        /// dtor.
        virtual ~decoder();
        /// ctor.
        /// @param cph: the cipher implementation
        inline explicit decoder(cipher* cph) : cph_(cph) {  }
        /// Decodes data in-place
        /// @param data: string (padded to a multiple of the cipher block length)
        /// @param size: size of string
        /// @return true on succss, false otherwise
        bool decode(char* const data, const std::size_t size);
        bool decode(const char* const data, const std::size_t size, char* const out, const std::size_t outSize);

        /// @return encapsulated cipher
        inline cipher* get() {
            return cph_;
        }

        /// @return encapsulated cipher
        inline const cipher* get() const {
            return cph_;
        }

    private:

        // The cipher implementation
        cipher* cph_;
    };
}

#endif
