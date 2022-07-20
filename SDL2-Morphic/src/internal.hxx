#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

#if defined(_MSC_VER)
#    include <SDL.h>
#    include <SDL2_gfxPrimitives.h>
#else /* defined(_MSC_VER) */
#    include <SDL2/SDL.h>
#    include <SDL2/SDL2_gfxPrimitives.h>
#endif /* not defined(_MSC_VER) */
