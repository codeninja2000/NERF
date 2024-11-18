//============================================================================
// Name        : NerfGun.cpp
// Author      : Grant Simpson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>
#include <string>

#include "NerfGun.h"

// Constructor that takes three parameters.
NerfGun::NerfGun(const std::string& model, int range, int capacity) {
    if (capacity < 1 || capacity > 144)
        throw std::invalid_argument("Capacity must be between 1-144.");
    m_model = model;
    m_range = range;
    m_capacity = m_dartCount = capacity;
}

// Function to get nerf gun model.
std::string NerfGun::getModel() const { return m_model; }

// Function to get the gun's capacity for darts.
int NerfGun::getCapacity() const { return m_capacity; }

// Function to get gun's dartCount.
int NerfGun::getDartCount() const { return m_dartCount; }

// Function to "fire" the gun. It reduces the dart count in the gun.
// void NerfGun::fire() {
//   // The operator will throw an underflow exception if there's and attempt to
//   // fire with no bullets
//   operator--(0);
// }

void NerfGun::fire() {
    if ((m_dartCount - 1) < 1)
        throw std::overflow_error("No more bullets, reload needed.");
    else {
        // std::cout << "Shot fired from " << getModel() << '.' << std::endl;
        m_dartCount--;
    }
}

// Function to increase the dart count by an amount "quantity".
void NerfGun::reload(int quantity) {
    if ((m_dartCount + quantity) > m_capacity)
        throw std::overflow_error("Too many rounds, less needed.");
    else {
        // std::cout << "Cha-ching! Reloaded!" << std::endl;
        m_dartCount += quantity;
    }
}

// Compound assignment overload
NerfGun& NerfGun::operator+=(const int rounds) {
    reload(rounds); // reload() throws an exception if capacity is exceeded
    return *this;
}

// Pre-decrement overload
NerfGun& NerfGun::operator--() {
    fire(); // fire() throws an exception if inventory is exhausted
    return *this;
}

// Post-decrement overload
NerfGun NerfGun::operator--(int) {
    NerfGun old = *this;
    fire();
    return old;
}

// Overloaded equality operator
bool operator==(const NerfGun& lhs, const NerfGun& rhs) {
    return (lhs.m_dartCount == rhs.m_dartCount);
}

// Overloaaded less-than operator
bool operator<(const NerfGun& lhs, const NerfGun& rhs) {
    return (lhs.m_dartCount < rhs.m_dartCount);
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const NerfGun& nerf) {
    os << "Model: " << nerf.m_model << std::endl;
    os << "Range: " << nerf.m_range << std::endl;
    os << "Capacity: " << nerf.m_capacity << std::endl;
    os << "Dart Count: " << nerf.m_dartCount << std::endl;
    return os;
}
