
#pragma once

#include "thingtypemanager.h"

class Paperdoll
{
    struct Paperdoll_t
    {
        uint16_t value{ 0 };
        ThingType* type{ nullptr };
    };

public:

    void setHead(uint16_t head);
    void setBody(uint16_t body);
    void setLegs(uint16_t legs);
    void setFeet(uint16_t feet);

    void reset();

    ThingType* getHead() const { return m_head.type; }
    ThingType* getBody() const { return m_body.type; }
    ThingType* getLegs() const { return m_legs.type; }
    ThingType* getFeet() const { return m_feet.type; }

private:

    Paperdoll_t m_head;
    Paperdoll_t m_body;
    Paperdoll_t m_legs;
    Paperdoll_t m_feet;
};