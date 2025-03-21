
#include <iostream>
#include "clsQueueLine.h"

using namespace std;


int main()
{
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);


    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();


    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeNextClient();
    SubscriptionsQueue.PrintAllTickets();

    cout << "\nSubscriptions Queue After Serving One client\n";
    SubscriptionsQueue.PrintAllTickets();

}