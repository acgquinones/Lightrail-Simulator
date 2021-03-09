// Ara Carmel Quinones

#include "Passenger.h"

// Name: Passenger(string, int, string, string)
// Desc - Overloaded Constructor for a passenger including name, age,
//        start location (where they board), final destination (where they get off)
// Preconditions - Data Available
// Postconditions - Creates a new Passenger
Passenger::Passenger(string name, int age, string startLocation, string finalDestination){
  m_fullName = name; //Name of the Passenger
  m_age = age; //Age of the passenger
  m_startLocation = startLocation; //Starting location (Where they get on)
  m_finalDestination = finalDestination; //Final destination (where they get off)
}
// Name: GetName
// Desc - Returns name
// Preconditions - Data Available
// Postconditions - Returns passenger name
string Passenger::GetName() {
  return m_fullName;
}
// Name: GetStartLocation
// Desc - Returns starting location
// Preconditions - Data Available
// Postconditions - Returns starting location
string Passenger::GetStartLocation(){
  return m_startLocation;
}
// Name: GetFinalDestination
// Desc - Returns final location
// Preconditions - Data Available
// Postconditions - Returns final destination
string Passenger::GetFinalDestination(){
  return m_finalDestination;
}
