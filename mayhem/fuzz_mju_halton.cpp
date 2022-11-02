#include <stdint.h>
#include <stdio.h>
#include "mujoco/mujoco.h"
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    int index = provider.ConsumeIntegral<int>();
    int base = provider.ConsumeIntegral<int>();

    mju_Halton(index, base);

    return 0;
}