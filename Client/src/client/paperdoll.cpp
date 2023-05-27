#include "paperdoll.h"

void Paperdoll::reset()
{
    setHead(0);
    setBody(0);
    setLegs(0);
    setFeet(0);
}

void Paperdoll::setHead(uint16_t head) {
    if (m_head == head)
        return;

    m_head = head;
}
void Paperdoll::setBody(uint16_t body) {
    if (m_body == body)
        return;

    m_body = body;
}
void Paperdoll::setLegs(uint16_t legs) {
    if (m_legs == legs)
        return;

    m_legs = legs;
}
void Paperdoll::setFeet(uint16_t feet) {
    if (m_feet == feet)
        return;

    m_feet = feet;
}