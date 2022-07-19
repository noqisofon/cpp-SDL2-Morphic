#pragma once

namespace morphic {
    class Event {
    protected:
        Event(uint32_t _event_type, uint32_t _timestamp, uint32_t _window_id);

    public:
        virtual ~Event();

    public:
        uint32_t type() const { return event_type_; }
        uint32_t timestamp() const { return timestamp_; }
        uint32_t windowId() const { return window_id_; }

    private:
        uint32_t event_type_;
        uint32_t timestamp_;
        uint32_t window_id_;
    };
}
