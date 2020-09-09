#include <computing.h>
#include <ctest.h>
#include <string.h>

CTEST(COMPUTING_TEST, COMMON)
{
    char* k1 = "shit";
    char* k2 = "am";
    int result = sort(k1, k2);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

