#include "person.h"

double Person::getWeight() const
{
    return m_weight;
}

void Person::setWeight(double weight)
{
    if (m_weight != weight) {
        m_weight = weight;
        emit weightChanged();
    }
}
