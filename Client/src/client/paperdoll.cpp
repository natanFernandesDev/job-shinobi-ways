#include "paperdoll.h"

void Paperdoll::reset()
{
    setHead(0);
    setBody(0);
    setLegs(0);
    setFeet(0);
}

void Paperdoll::setHead(uint16_t head) {
    if (m_head.value == head)
        return;

    m_head.value = head;
    if (head != 0) {
        m_head.type = g_things.getThingType(head, ThingCategoryCreature).get();
    }
    else { m_head.type = nullptr; }
}
void Paperdoll::setBody(uint16_t body) {
    if (m_body.value == body)
        return;

    m_body.value = body;
    if (body != 0) {
        m_body.type = g_things.getThingType(body, ThingCategoryCreature).get();
    }
    else { m_body.type = nullptr; }
}
void Paperdoll::setLegs(uint16_t legs) {
    if (m_legs.value == legs)
        return;

    m_legs.value = legs;
    if (legs != 0) {
        m_legs.type = g_things.getThingType(legs, ThingCategoryCreature).get();
    }
    else { m_legs.type = nullptr; }
}
void Paperdoll::setFeet(uint16_t feet) {
    if (m_feet.value == feet)
        return;

    m_feet.value = feet;
    if (feet != 0) {
        m_feet.type = g_things.getThingType(feet, ThingCategoryCreature).get();
    }
    else { m_feet.type = nullptr; }
}