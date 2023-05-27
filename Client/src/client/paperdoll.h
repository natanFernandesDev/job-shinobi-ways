
#pragma once

#include "thingtypemanager.h"

class Paperdoll
{

public:

    void setHead(uint16_t head);
    void setBody(uint16_t body);
    void setLegs(uint16_t legs);
    void setFeet(uint16_t feet);

    void reset();

    uint16_t getHead() const { return m_head; }
    uint16_t getBody() const { return m_body; }
    uint16_t getLegs() const { return m_legs; }
    uint16_t getFeet() const { return m_feet; }

    bool operator==(const Paperdoll& other) const
    {
        return m_head == other.m_head &&
            m_body == other.m_body &&
            m_legs == other.m_legs &&
            m_feet == other.m_feet;
    }
    bool operator!=(const Paperdoll& other) const { return !(*this == other); }

private:

    uint16_t m_head{ 0 };
    uint16_t m_body{ 0 };
    uint16_t m_legs{ 0 };
    uint16_t m_feet{ 0 };
};