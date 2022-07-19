#pragma once

#include "morphic/Event.hxx"
#include "morphic/KeySymbol.hxx"

namespace morphic {
    class KeyboardEvent : public Event {
        using _Super = Event;

    public:
        KeyboardEvent();
        KeyboardEvent(uint32_t _type, uint32_t _timestamp, uint32_t _window_id,
                      uint8_t _state, uint8_t _repeat, KeySymbol _symbol);

    public:
        uint8_t state() const { return state_; }
        uint8_t repeat() const { return repeat_; }
        
    private:
        uint8_t state_;
        uint8_t repeat_;
        KeySymbol symbol_;
    };
}
