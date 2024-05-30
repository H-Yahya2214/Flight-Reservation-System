#include <iostream>
#include <set>
#include <string>
using namespace std;

class Flight{
  private:
      int Flight_ID ;
      string Model ;
      int Capacity ;
      string Airline ;
      string Destination ;
      string Departure_Time ;
      double Ticket_Price ;
  public:
    Flight() {
    Flight_ID = 0;
    Model = "";
    Capacity = 0;
    Airline = "";
    Destination = "";
    Departure_Time = "";
    Ticket_Price = 0.0;
    }

     Flight(int FI ,string model,int capacity,string airline,string destination,string DepatureTime, double ticketPrice ){
          Flight_ID = FI;
          Model = model;
          Capacity = capacity;
          Airline = airline;
          Destination = destination;
          Departure_Time = DepatureTime;
          Ticket_Price = ticketPrice;
     }

      void setFlight_Id(int flight_id){Flight_ID = flight_id;}
      int getFlight_Id() {return Flight_ID; }

      void setModel(string model){Model = model;}
      string getModel(){return Model;}

      void setCapacity(int capacity){Capacity = capacity;}
      int getCapacity(){return Capacity;}

      void setAirline(string AL){Airline = AL;}
      string getAirline(){return Airline;}

      void setDestination(string destination){Destination = destination;}
      string getDestination(){return Destination;}

      void setDepatureTime(string DT){Departure_Time = DT;}
      string getDepatureTime(){return Departure_Time;}

      void setTicketPrice(double TP){Ticket_Price = TP;}
      double getTicketPrice(){return Ticket_Price;}

      void display_Flight_info(){
          cout<<"Flight ID:"<<getFlight_Id()<<'\n';
          cout<<"Capacity:"<<getCapacity()<<'\n';
          cout<<"Airline:"<<getAirline()<<'\n';
          cout<<"Destination:"<<getDestination()<<'\n';
          cout<<"Depature Time:"<<getDepatureTime()<<'\n';
          cout<<"Ticket Price:"<<getTicketPrice()<<'\n';
      }

};
template <class T>
class Node{
  public:
    T Data;
    Node<T>* Next;

    Node(T data){
        Data = data;
        Next = nullptr;
    }
};
template <class T>
class FlightList{

  public:
  Node<T>* head = nullptr;
  Node<T>* tail = nullptr;

     	void AddFlight(T num){
    		Node<T>* n = new Node<T>(num);
    		if(head==nullptr){
                    head=n;

    		}
    		else{
    		    Node<T>*tmp=head;
    		    while(tmp->Next!=nullptr){
                    tmp=tmp->Next;
    		    }
    		    tmp->Next=n;

    		}

    	}

    bool DelFlight(int FID){
        //check if the linkedd list is empty or not
        if (head==nullptr){
                return false;
        }
       // Check if the node to delete is the first one
       if (head->Data.getFlight_Id() == FID){
         Node<T>* temp = head;
         head = head->Next;
         delete temp;
         return true;
       }

        Node<T>* temp=head;
        Node<T>* prev = nullptr;

        // Search for the node to delete
        while (temp != nullptr && temp->Data.getFlight_Id() != FID) {
        prev = temp;
        temp = temp->Next;
        }
        //temp btb2a eli 3ayzen nms7ha w prev eli 2blaha

        // If the flight id is found
        if (temp != nullptr) {
          // Check if the node is the last one
          if (temp == tail) {
             tail = prev;
             prev->Next = nullptr;
          } else {
             prev->Next = temp->Next;
          }

        delete temp;
        return true;
        }

        // flight with that id not found
        return false;
}

    void DisplayAll(){
      Node<T>* temp=head;
      //print all the flight data
      while (temp!=nullptr){
        temp->Data.display_Flight_info();
        cout<<'\n';
        temp = temp->Next;
      }
    }

};

template <class T>
class FlightStack{
public:
    Node<T>* TOP;
    //for time complexty
    set<int> unique;
    FlightStack(){
        TOP=nullptr;}

    void PushFlight(T data){

     //if data found
     if (unique.find(data.getFlight_Id())!=unique.end()){
            cout<<"Flight is already there"<<'\n';
     }
     // if data don't found will push the data in the stack and in the set
     else {
         Node<T>* s = new Node<T>(data);
         s->Next=TOP;
         TOP=s;
         unique.insert(data.getFlight_Id());
     }
    }

    void PrintStack(){
      Node<T>* temp=TOP;
      //check if empty
      if (IsEmpty()){
            cout<<"Stack is empty"<<'\n';
            return ;
      }
      // display the data
      while(temp!=nullptr){
        temp->Data.display_Flight_info();
        cout<<"\n";
        temp=temp->Next;
      }
    }

    T peek(){
        if (IsEmpty()) {
            cout<<"stack is empty" <<'\n';
        }
        //return top data
        else TOP->Data.display_Flight_info();
    }

    bool IsEmpty(){
      return TOP==nullptr;
    }

    void DeleteStack(){
      //check if empty
      if (IsEmpty()) {
            cout << "stack is empty" << endl;
            return ;
        }
      //delete top
      Node<T>* temp = TOP;
      TOP = TOP->Next;
      delete temp;
    }

    void EditStack(T data){
        //Edit Top Data
        TOP->Data=data;
        }
};

int main()
{
    Flight F1(1, "D1", 301, "Airlines", "Cairo", "1:30", 501);
    Flight F2(2, "D2", 302, "Airlines", "Cairo", "2:30", 502);
    Flight F3(3, "D3", 303, "Airlines", "Cairo", "3:30", 503);

    FlightList<Flight> list;
    list.AddFlight(F1);
    list.AddFlight(F2);
    list.AddFlight(F3);


    FlightStack<Flight> stack;
    stack.PushFlight(F1);
    stack.PushFlight(F2);
    stack.PushFlight(F3);

    int DAta;
    int choice;
    int inside;

    bool FlagMain=true;
    bool FlagMethod1=true;
    bool FlagMethod2=true;

    int id;
    string Model;
    int Capacity;
    string Airline;
    string Destination;
    string Departure_Time;
    int Ticket_Price;

    while (FlagMain){
        cout << "Hello"<<'\n'<<"Welcome To Our Airline Site System" <<'\n';
        cout << "To choose Linked List press 1:"<<'\n'<<"To choose Stack press 2:"<<'\n';
        cout<< "For another option click 0"<<'\n';
        cout << "Enter your choice: ";
        cin>>choice;

        FlagMethod1=true;
        FlagMethod2=true;

        while(FlagMethod1){

            if (choice==1){
             cout<<"choose which method you want to use in linked list: "<<'\n';
             cout<<"press 1  to insert new flight"<<'\n'
                 <<"press 2 to Delete Flight"<<'\n'
                 <<"press 3 to Display all flights"<<'\n'
                 <<"press 4 to close the program"<<'\n';
             cout << "Enter your choice: ";

            cin>>inside;

            if (inside==1){
                cout<<"Insert New flight Data";
                cout << '\n' << "Flight ID: "; cin >> id;
                cout << '\n' << "Model: "; cin >> Model;
                cout << '\n' << "Capacity: "; cin >> Capacity;
                cout << '\n' << "Airline: "; cin >> Airline;
                cout << '\n' << "Destination: "; cin >> Destination;
                cout << '\n' << "Departure Time: "; cin >> Departure_Time;
                cout << '\n' << "Ticket Price: "; cin >> Ticket_Price;
                cout<<'\n';
                Flight F4(id, Model, Capacity, Airline, Destination, Departure_Time, Ticket_Price);
                list.AddFlight(F4);
                cout<<"if you want to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod1=false; FlagMain=false;}
            }
            else if (inside==2){
                cout<<"insert id of the flight you want to delete";
                cin>>DAta;
                list.DelFlight(DAta);
                cout<<"if you want to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod1=false; FlagMain=false;}
            }
            else if (inside==3){
                cout<<"All Flight Data"<<'\n';
                list.DisplayAll();
                cout<<"if you want to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod1=false; FlagMain=false;}
            }
            else if (inside==4){
                FlagMethod1=false; FlagMain=false;
            }
            else {
                cout<<"we don't understand your choice.";
                cout<<"if you want to choose methods press any number  "<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod1=false; FlagMain=false;}
            }
           }
           else FlagMethod1=false;
        }
        while(FlagMethod2){
         if(choice==2){
           cout<<"choose which method you want to use in Stack: "<<'\n';
           cout<<"press 1  to insert new flight"<<'\n'
               <<"press 2 to Check the latest Added Flight"<<'\n'
               <<"press 3 to Print all the flights "<<'\n'
               <<"press 4 to Edit flight "<<'\n'
               <<"press 5 to Delete flight "<<'\n'
               <<"press 6 to close the program"<<'\n';
            cout << "Enter your choice: ";

           cin>>inside;
          if (inside==1){
                cout<<"Insert New flight Data"<<'\n';
                cout << '\n' << "Flight ID: "; cin >> id;
                cout << '\n' << "Model: "; cin >> Model;
                cout << '\n' << "Capacity: "; cin >> Capacity;
                cout << '\n' << "Airline: "; cin >> Airline;
                cout << '\n' << "Destination: "; cin >> Destination;
                cout << '\n' << "Departure Time: "; cin >> Departure_Time;
                cout << '\n' << "Ticket Price: "; cin >> Ticket_Price;
                cout<<'\n';
                Flight F4(id, Model, Capacity, Airline, Destination, Departure_Time, Ticket_Price);
                stack.PushFlight(F4);
                cout<<"if you to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
          else if (inside==2){
                cout<<"The latest added flight is"<<'\n';
                stack.peek();
                cout<<"if you to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
          else if (inside==3){
                cout<<"All Flight Data\n";
                stack.PrintStack();
                cout<<"if you to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
          else if (inside==4){
                cout<<"insert the edited data";
                cout << '\n' << "Flight ID: "; cin >> id;
                cout << '\n' << "Model: "; cin >> Model;
                cout << '\n' << "Capacity: "; cin >> Capacity;
                cout << '\n' << "Airline: "; cin >> Airline;
                cout << '\n' << "Destination: "; cin >> Destination;
                cout << '\n' << "Departure Time: "; cin >> Departure_Time;
                cout << '\n' << "Ticket Price: "; cin >> Ticket_Price;
                cout<<'\n';
                Flight F4(id, Model, Capacity, Airline, Destination, Departure_Time, Ticket_Price);
                stack.EditStack(F4);
                cout<<"if you to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
          else if (inside==5){
                stack.DeleteStack();
                cout<<"if you to choose another method press any number"<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
          else if (inside==6){
                FlagMethod2=false; FlagMain=false;
          }
          else {
                cout<<"we don't understand your choice.";
                cout<<"if you want to choose methods press any number  "<<'\n';
                cout<<"To close the program press 0"<<'\n';
                cout << "Enter your choice: ";
                cin>>inside;
                if (inside==0){FlagMethod2=false; FlagMain=false;}
          }
         }
        else FlagMethod2=false;
        }
     if (choice==0){
            cout<<"We don't have other options. if you want to terminate the program press 0."<<'\n';
            cout<<"if you want to to get back the program press any number."<<'\n';
            cout << "Enter your choice: ";
            cin>>inside;
                if (inside==0){FlagMain=false;}
        }

     else if(FlagMain) {

        cout<<"we don't understand your choice please choose again";
     }
    }
    return 0;
}
