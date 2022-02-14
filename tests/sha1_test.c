#define SHA1_IMPLEMENTATION
#include "../sha1.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int do_test(size_t iterationCount, const char* input, const char* expected)
{
    unsigned char hash[SHA1_SIZE];
    char hashStr[SHA1_SIZE_FORMATTED];
    sha1_context ctx;

    sha1_init(&ctx);
    {
        size_t i;
        size_t inputSize = strlen(input);
        for (i = 0; i < iterationCount; i += 1) {
            sha1_update(&ctx, input, inputSize);
        }
    }
    sha1_finalize(&ctx, hash);

    /* Check and compare results. */
    sha1_format(hashStr, sizeof(hashStr), hash);

    printf("%s = %s : ", input, hashStr);
    if (strcmp(hashStr, expected) == 0) {
        printf("success\n");
        return 0;
    } else {
        printf("failed\n");
        return -1;
    }
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    do_test(1,       "",                                                                 "da39a3ee5e6b4b0d3255bfef95601890afd80709");
    do_test(1,       "a",                                                                "86f7e437faa5a7fce15d1ddcb9eaeaea377667b8");
    do_test(1,       "abc",                                                              "a9993e364706816aba3e25717850c26c9cd0d89d");
    do_test(1,       "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",         "84983e441c3bd26ebaae4aa1f95129e5e54670f1");
    do_test(1000000, "a",                                                                "34aa973cd4c4daa4f61eeb2bdbad27316534016f");
    do_test(1,       "0123456701234567012345670123456701234567012345670123456701234567", "e0c094e867ef46c350ef54a7f59dd60bed92ae83");

    return 0;
}
