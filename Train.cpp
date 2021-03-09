//Ara Carmel Quinones


#include "Train.h"

//Train is the main linked list of the project.
//Each train has a route and can load/unload passengers
//class Train {
//public:
// Name: Train() - Overloaded Constructor
// Desc - Creates a new train with one car and a size of one. A train is a linked list of cars
//        The train is passed a route which is a list of stops for the train
// Preconditions - None
// Postconditions - Creates a new train
Train::Train(Route* route)
{
  //Car* m_head; //Front of the trains
  //Route* m_route; //Route assigned to the train
  //int m_totalCars; //Total cars in the train (number of nodes)
  

  m_head = nullptr; //Front of the train
  m_route = route; //Route assigned to the train
  m_totalCars = 0; //Total cars in the train (number of nodes)

}

// Name: ~Train() - Destructor
// Desc - Removes each car from the train and deallocates each passenger in each car.
//        Resets each of the linked list pointers
// Preconditions - None
// Postconditions - Removes all cars and passengers
Train::~Train()
{
  
}

// Name: AddCar
// Desc - Dynamically allocates a new car and inserts it at the end of the train.
//        Increments m_totalCars
// Preconditions - Train must exist
// Postconditions - New car node inserted at end of train
void Train::AddCar()
{
  Car *curr = m_head;
  m_totalCars++;
  Car *newCar = new Car(CAR_CAPACITY, m_totalCars);

  if (m_head == nullptr)
    {
      m_head = newCar;
    }
  else
    {
      //create a while loop to point at next newCar
      while(curr->m_next != nullptr)
	{
	  cout << "WHILE LOOP IN ADDCAR RUNS" << endl;
	  //curr->m_next = newCar; 
	  curr = curr->m_next;

	}
      curr->m_next = newCar;
      cout << "END OF WHILE LOOP IN ADDCAR RUN" << endl;
    }

  //  cout << "Add Car Runs Total Car Nodes: " << m_totalCars << endl;
}

// Name: RemoveCar(Car*)
// Desc - Removes a car from either the beginning, middle or end of train linked list
// Preconditions - Train exists
// Postconditions - Removes specific car (including passengers)
// UNUSED - 3 Bonus Pts for completing if rest of project is completed
void Train::RemoveCar(Car*)
{


}

// Name: TrainStatus
// Desc - Displays number of cars, number of passengers, and the route details
// Preconditions - Train is populated
// Postconditions - Displays information at a specific location
void Train::TrainStatus()
{

  Car *curr = m_head;
  int totalCarsCounter = 0;
  
  cout << "Number of cars: " << m_totalCars << endl;

  while (totalCarsCounter != m_totalCars)
    {
      cout << "Car " << curr->m_carNumber << ": Number of passengers: " << int(curr -> m_passengers.size()) << endl;
      curr = curr->m_next;
      totalCarsCounter++;
    }

  cout << "Current stop: " << m_route->GetCurrentStop()->GetName() << endl;
  cout << "Next stop is: " << m_route->GetCurrentStop()->GetNextStop()->GetName() << endl;
  
}

// Name: LoadPassengers(filename)
// Desc - Iterates through an input file and if the name of the "start location"
//        matches m_curLocation then creates a new passenger and has them BoardPassenger
// **Note - If you run this twice at any stop, it will load the same people over
//          and over again - you do not need to check for this
// Preconditions - Valid input file with first name, last name, age, start location,
//                 end location all comma separated with one passenger on each line
// Postconditions - Loads all passengers at this into cars
void Train::LoadPassengers(string passName)
{
  
  ifstream inputStream;
  string firstName;
  string lastName;
  string fullName;
  string age;
  string startLocation;
  string finalDestination;
  int numPassenger = 0;
  
  inputStream.open(passName);
  
  while(getline(inputStream, firstName, ','))
    {
      getline(inputStream, lastName, ',');
      getline(inputStream, age, ',');
      getline(inputStream, startLocation, ',');
      getline(inputStream, finalDestination);
      
      //      cout << "This is start location: " <<  startLocation << endl;
      //      cout << "\tTHIS IS CURRENT STOP: " << m_route->GetCurrentStop()->GetName();
      fullName = firstName + ' ' + lastName;
      if (startLocation == m_route->GetCurrentStop()->GetName())
	{
	  numPassenger++;
	  Passenger *newPassenger = new Passenger(fullName, stoi(age), startLocation, finalDestination);
	  BoardPassenger(newPassenger);
	}
    }
 cout << "Boarded " << numPassenger << " passengers"  << endl;  
}


// Name: BoardPassenger(Passenger*)
// Desc - Checks to see if the capacity of the train has been met. If so,
//        adds a new car and inserts the passenger in the first open car starting at the front.
//        Also, displays name and final destination of passenger being loaded.
// Preconditions - Passenger object already allocated and data populated. Train exists
// Postconditions - Adds new passenger to a car from front to back
void Train::BoardPassenger(Passenger *passenger)
{
  Car *curr = m_head;
  bool fullOrNot;
  
  //call IsTrainFull() to Check to see if the capacity of the train has been met
  fullOrNot = IsTrainFull();
  //  cout << "\tBoardPassenger() runs: IS THE TRAIN FULL? " << fullOrNot << endl;

  //if no car exist, call AddCar() to make a Car Node
  //if car is full, call AddCar() to add another car   
  if (fullOrNot == true)
    {
      AddCar();
      curr = m_head;
      while(curr->m_next != nullptr)
	{
	  //	  cout << "what is curr->m_next?: " << curr->m_next << endl;
	  //	  cout << "RUNNING WHILE LOOP AFTER ADDCAR()" << endl;
	  //cout << "curr->m_carNumber: " << curr->m_carNumber << endl;

	  curr = curr->m_next;

	}
      
      curr->AddPassenger(passenger);
      cout << passenger->GetName() << " Boards the Train (Destination: " <<
      passenger->GetFinalDestination() << ")" <<endl;

    }
  
  
  
  //if car is not full, insert the passenger in the first open car starting at the front  
  //  curr->AddPassenger(passenger);
  
  
  else if (curr->m_next == nullptr ) // there's 1 Car Node in the linkedlist
    {
      // check if it's full or not
     fullOrNot = curr->IsFull();
     if (fullOrNot == false)
       {
	 cout << "Adding Passenger ..." << endl;
	 //if car is not full, add passenger
	 curr->AddPassenger(passenger);
	 cout << passenger->GetName() << " Boards the Train (Destination: " <<
	   passenger->GetFinalDestination() << ")" <<endl;
       }
    }
  
  
  else if (curr->m_next != nullptr)
    {
      //if there's 2 or more than 1 Car Node in LinkedList
      //start from beginning of the list and check if each Car Node is full or not
      //if last Node if full too, return true to make new Car,
      //if not, return false
      
      cout << "ELSE IN BOARDPASSENGER RUNS (BEFORE ENTERING WHILE LOOP)" << endl;
      while(curr->m_next != nullptr)
	{
	  cout << "WHILE LOOP IN BOARDPASSENGER RUNS" << endl;
	  fullOrNot = curr->IsFull();
	  if (fullOrNot == false)
	    {
	      curr->AddPassenger(passenger);
	      cout << passenger->GetName() << " Boards the Train (Destination: " <<
		passenger->GetFinalDestination() << ")" <<endl;
	     
	    }
	  
	  curr = curr->m_next;
	  
	}
      //displays name and final destination of passenger being loaded.                                   */          
    }
}
  
// Name: DisembarkPassenger()
// Desc - For each passenger on the train, checks to see if they are at their final
//        destination. If they are, the passenger is removed from the train.
// Note - Deallocate the passenger first then you can use the m_passengers.erase command.
// Do not remove cars that are now unnecessary based on capacity (if you
// added a car to hold 17 passengers and one disembarks, do not remove it)
// Preconditions - Passengers reach their destination
// Postconditions - Passengers are removed from the m_passengers, deallocated, and erased
void Train::DisembarkPassengers()
{
  Car *curr = m_head;
  int disembarkPassengers = 0;
  
  for (int i = 0; i < int(curr->m_passengers.size()); i++)
    {
      // cout << "curr->m_passengers.at(i)->GetFinalDestination() is: " << curr->m_passengers.at(i)->GetFinalDestination() << endl;
      if (curr->m_passengers.at(i)->GetFinalDestination() == m_route->GetCurrentStop()->GetName())
	{
	  
	  delete curr->m_passengers[i];
	  curr->m_passengers[i] = nullptr;
	  curr->m_passengers.erase(curr->m_passengers.begin() + i);
	  cout << curr->m_passengers[i]->GetName() << " Disembark the Train (Destination: " <<
                curr->m_passengers[i]->GetFinalDestination() << ")" <<endl;
	  disembarkPassengers++; 
	}
    }
  cout << disembarkPassengers  << " passengers disembarked" << endl;
}

// Name: TravelToNextStop
// Desc - When chosen from the menu, moves the train to the next stop. If you have
//        reached last stop, indicates this.
//        When at end, also recommends turning train around.
// Preconditions - Valid train on valid route
// Postconditions - Updates SetCurrentStop to next stop on route
void Train::TravelToNextStop()
{
  m_route->SetCurrentStop(m_route->GetCurrentStop()->GetNextStop());
  cout << "Arriving at: " << m_route->GetCurrentStop()->GetName() << endl;
}

// Name: TurnTrainAround()
// Desc - When chosen from the menu at the end of the route, reverses the Route by
//        calling ReverseRoute
// Preconditions - Valid train on valid route
// Postconditions - The entire route is reversed and the train starts at the new front
void Train::TurnTrainAround()
{
  
}

// Name: IsTrainFull()
// Desc - Iterates through train to see if total number of passengers is greater
//        than maximum capacity
// Preconditions - Valid train on valid route
// Postconditions - Returns true if full else false
bool Train::IsTrainFull()
{
  Car *curr = m_head;
  bool fullOrNot;
  
  if (m_head == nullptr) // no car node exist, linkedlist is empty
    {
      return true; // return true to make car1
    }
  /*  else if (curr->m_next == nullptr ) 
    {
      // there's 1 Car Node in the linkedlist
      // check if it's full or not
      //if full, return true to make Car2
      //if not, return fallse
      
      fullOrNot = curr->IsFull();
      return fullOrNot;
	  
      }*/
  else
    {
      cout << "ELSE IN ISTRAINFULL RUNS" << endl;
      //if there's 2 or more than 1 Car Node in LinkedList
      //start from beginning of the list and check if each Car Node is full or not
      //if last Node if full too, return true to make new Car,
      //if not, return false
      while(curr->m_next != nullptr)
	{
	  cout << "WHILE LOOP RUNS IN ISTRAINFULL" << endl;
	  fullOrNot = curr->IsFull();
	  if (fullOrNot == false)
	    {
	      return false;
	    }
	  else //car is full
	    //{
	    //if car is full and no next car node, return true to make a new car
	    // if (curr->m_next == nullptr)
	    //	return true;
	    //else
	    //if car is full and there exist next car node, check next car if its full
	    curr = curr->m_next;
	}
      return true;
    }  
}



//private:
//Car* m_head; //Front of the train
//Route* m_route; //Route assigned to the train
//int m_totalCars; //Total cars in the train (number of nodes)

