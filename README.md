<h4 align="center">SHA-1 Hashing</h4>

<p align="center">
    <a href="https://discord.gg/9vpqbjU"><img src="https://img.shields.io/discord/712952679415939085?label=discord&logo=discord" alt="discord"></a>
    <a href="https://twitter.com/mackron"><img src="https://img.shields.io/twitter/follow/mackron?style=flat&label=twitter&color=1da1f2&logo=twitter" alt="twitter"></a>
</p>

A simple SHA-1 hashing implementation. Usage:

    unsigned char digest[SHA1_SIZE];
    sha1_context ctx;
    sha1_init(&ctx);
    {
        sha1_update(&ctx, src, sz);
    }
    sha1_finalize(&ctx, digest);

The above code is the literal implementation of `sha1()` which is a high level helper for hashing
data of a known size:

    unsigned char hash[SHA1_SIZE];
    sha1(hash, data, dataSize);

Use `sha1_format()` to format the digest as a hex string. The capacity of the output buffer needs to
be at least `SHA1_SIZE_FORMATTED` bytes.

This library does not perform any memory allocations and does not use anything from the standard
library except for `size_t` and `NULL`, both of which are drawn in from stddef.h. No other standard
headers are included.

There is no need to link to anything with this library. You can use SHA1_IMPLEMENTATION to define
the implementation section, or you can use sha1.c if you prefer a traditional header/source pair.

This implements both methods defined in RFC 3174. Method 1 will be used by default. If you want to
use Method 2, define `SHA1_USE_RFC_METHOD_2` at compile time.

    #define SHA1_USE_RFC_METHOD_2
    #define SHA1_IMPLEMENTATION
    #include "sha1.h"

No effort has been made to optimize this beyond the algorithms described in RGC 3174. If you're
looking for the fastest SHA-1 implementation you'll need to look elsewhere. An optimized
implementation may come later.