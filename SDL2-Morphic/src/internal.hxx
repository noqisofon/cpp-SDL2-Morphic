#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <iostream>

#if defined(_MSC_VER)
#    include <SDL.h>
#else /* defined(_MSC_VER) */
#    include <SDL2/SDL.h>
#endif /* not defined(_MSC_VER) */
