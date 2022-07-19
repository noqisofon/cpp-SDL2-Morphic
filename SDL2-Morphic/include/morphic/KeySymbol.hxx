#pragma once

namespace morphic {

    enum class Scancode : uint32_t {
        _0,
        _1,
        _2,
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,
        A,
        
    };
    
    struct KeySymbol {
        Scancode scancode;
        Keycode  keycode;
        uint16_t modify;
    };
}
