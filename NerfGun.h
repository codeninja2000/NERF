/*Program name:
  Author: Grant Simpson
  Date last updated: Nov 14, 2024
  Purpose:
*/
#ifndef NERFGUN_H_
#define NERFGUN_H_

#include <iostream>
#include <string>

class NerfGun {
  // Overloaded equality operator
  friend bool operator==(const NerfGun &, const NerfGun &);

  // Overloaded less-than operator
  friend bool operator<(const NerfGun &, const NerfGun &);

  // Overloaded stream insertion operator
  friend std::ostream &operator<<(std::ostream &, const NerfGun &);

public:
  // Constructor that takes three parameters.
  // Postcondition: m_model = model, m_range = range, and if capacity is a
  //                positive integer less than or equal to 144, then
  //                m_capacity = capacity and m_dartCount = capacity.
  NerfGun(const std::string &model, int range, int capacity);

  // Function to get nerf gun model.
  // Postcondition: return m_model.
  std::string getModel() const;

  // Function to get the gun's capacity for darts.
  // Postcondition: return m_dartCount.
  int getCapacity() const;

  // Function to get gun's dartCount.
  // Postcondition: return m_dartCount.
  int getDartCount() const;

  // Function to "fire" the gun. It reduces the dart count in the gun.
  // Postcondition: m_dartCount--. If the gun is fired when there are no darts
  //                left, then an underflow exception is thrown.
  void fire();

  // Function to increase the dart count by an amount "quantity".
  // Postcondition: m_dartCount = m_dartCount + quantity. If the number of darts
  //                exceeds the toys capacity, then an overflow exception is
  //                thrown.
  void reload(int quantity);

  // Compound assignment overload
  NerfGun &operator+=(const int);

  // Pre-decrement overload
  NerfGun &operator--();

  // Post-decrement overload
  NerfGun operator--(int);

private:
  std::string m_model;
  int m_range;
  int m_capacity;
  int m_dartCount;
};

#endif /* NERFGUN_H_ */
