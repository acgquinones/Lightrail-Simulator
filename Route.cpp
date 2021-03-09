//Ara Carmel Quinones
// need to work on revere route 

#include "Route.h"
#include "Train.h"

//Routes are the route a train would take from stop to stop
//In this case, it is a linked lists that is made up of stops (nodes)

// Name: Route() - Default Constructor
// Desc - Creates a new empty route
// Preconditions - None
// Postconditions - Sets everything to either nullptr or 0
Route::Route()
{
  m_head = nullptr; //Head of the route linked list
  m_tail = nullptr; //End of the route linked list
  m_currentStop = nullptr; //Stop of the current route
  m_totalStops = 0; //Total stops on the route (size of linked list)
}
// Name: ~Route - Destructor
// Desc - Removes all of the stops from the route
// Preconditions - Route must have nodes
// Postconditions - Route will be empty and m_head and m_tail and m_currentStop
//                  will be nullptr and m_totalStops will be 0
Route::~Route()
{
  cout << "Destructor" << endl;
}


// Name: LoadRoute(string)
// Desc - Reads the route file and calls AddStop once per line. Increments m_totalStops.
// Preconditions - Route allocated and file available
// Postconditions - Populates route with stops. Sets m_currentStop to m_head when load completed.
void Route::LoadRoute(string fileName)
{
  ifstream inputStream;
  string stopName;
  string stopNum;
  
  inputStream.open(fileName);

  while(getline(inputStream, stopName, ','))
    {
      getline(inputStream, stopNum);
      AddStop(stopName, stoi(stopNum));
      m_totalStops++;
      
      //      cout << m_tail->GetName() << "->";
    }

  SetCurrentStop(m_head);
  //  cout << "m_currentStop is:" << m_head->GetName() <<endl;
  cout << "Route Loaded with " << m_totalStops << " stops" << endl;

  return;
}

// Name: AddStop(string, int)
// Desc - Allocates new stop and inserts in end of route
// Preconditions - Route allocated and data for stop available
// Postconditions - New stop inserted in end of route
void Route::AddStop(string stopName, int stopNum)
{
  
  Stop *newStop = new Stop(stopName, stopNum);
    
  if (m_totalStops == 0)
    {
      //      cout << "No node/stop in the link" << endl;
      m_head = newStop;
      m_tail = newStop;
      //      cout << "Start of route link: " << newStop->GetName() << "->";
    }
  else
    {
      m_tail->SetNextStop(newStop);
      m_tail = newStop;
      //cout << newStop->GetName() << "->";
    }
  
  return;
}

// Name: PrintRouteDetails()
// Desc - Prints information about the next stop on the route
// Preconditions - Route allocated and data for next stop available
// Postconditions - Outputs data only

/*
void Route::PrintRouteDetails()
{
  int size = 0;

  //for(int i = 0; i <= m_totalStops; i++)
  while(m_currentStop != nullptr)
    {
      if (size == 0)
	{
	  m_currentStop = m_head;
	  cout << m_currentStop->GetName() << endl;
	}
      m_currentStop = m_currentStop->GetName();
      cout <<
      


    }
}
*/

// Name: GetCurrentStop
// Desc - Returns the m_currentStop
// Preconditions - m_currentStop has been assigned
// Postconditions - Returns the pointer
Stop* Route::GetCurrentStop()
{
  return m_currentStop;
}

// Name: SetCurrentStop
// Desc - Updates m_currentStop
// Preconditions - m_currentStop is available
// Postconditions - Updates m_currentStop as the train moves
void Route::SetCurrentStop(Stop* currStop)
{
  m_currentStop = currStop;
}


// Name: ReverseRoute
// Desc - At the end of a route, the route can be reversed (as in the train turns around)
// Recommendations - Code this function last (dead last)
// Preconditions - Route has been completed
// Postconditions - Replaces old route with new reversed route.


/*void Route::ReverseRoute()
{
  
  //Stop *curr = m_head;
  Stop *curr = m_head;
  int counter = 0;
  Stop* newStop;

  cout << "ReverseRoute Function" << endl;
  m_tail = prev;
  prev->SetNextStop(nullptr);

  if (m_currentStop->GetNextStop() == nullptr) 
    {
      m_head = nullptr;
      m_tail = nullptr;
      
      while (curr != nullptr)
	{
	  newStop = new Stop(curr->GetName(), curr->GetNumber());
	  newStop->SetNextStop(m_head);
	  if (m_head == nullptr)
	    {
	      m_head = newStop;
	      m_tail = newStop;
	    }
	  m_head = newStop;
	  curr = curr->GetNextStop();
	  counter++;
	}
      
      
    }
  //m_totalStops--;

}
*/
