//
// srecord - manipulate eprom load files
// Copyright (C) 2000-2003, 2006-2008, 2010 Peter Miller
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef SRECORD_CRC32_H
#define SRECORD_CRC32_H

#include <stddef.h>

namespace srecord
{

/**
  * The crc32 class is used to represent the running value of a 32-bit
  * cyclic redundancy check of series of bytes.
  */
class crc32
{
public:

    struct config 
    {
        unsigned long poly;
        unsigned long seed;
        unsigned long final_xor;
    };

    enum seed_mode_t
    {
        seed_mode_ccitt, // all ones
        seed_mode_xmodem // all zero
    };

    static const unsigned long DEFAULT_POLY = 0xedb88320;

    static const config DEFAULT_CONFIG;

    /**
      * The destructor.
      */
    virtual ~crc32();

    /**
      * The default constructor.
      */
    crc32(const config& crc_config);
#if 0
    /**
      * The default constructor.
      */
    crc32(seed_mode_t seed_mode = seed_mode_ccitt);

    /**
      * The default constructor.
      */
    crc32(seed_mode_t seed_mode, unsigned long poly);
#endif
    /**
      * The copy constructor.
      */
    crc32(const crc32 &);

    /**
      * The assignment operator.
      */
    crc32 &operator=(const crc32 &);

    /**
      * The get method is used to obtain the running value of the cyclic
      * redundancy check.
      */
    unsigned long get() const;

    /**
      * The next method is used to advance the state by one byte.
      */
    void next(unsigned char);

    /**
      * The nextbuf method is used to advance the state by a series of bytes.
      */
    void nextbuf(const void *, size_t);

private:
    /**
      * The state instance variable is used to remember the running
      * value of the 32-bit cyclic redundancy check.
      */
    unsigned long state;

    config cfg;
};

};

#endif // SRECORD_CRC32_H
