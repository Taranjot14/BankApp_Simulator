/*
 * BankSimApp.cpp
 * 
 * Description: Application file for bank simulation using PriorityQueue and Queue
 *
 * 
 * Author: Taranjot Singh and Matthias Zelleke
 * Date of last modification: November 17 2023
 */



#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


int main() {
    //Varaibles and objects for Storing Event
    Queue<Event> bankLine; 
    PriorityQueue<Event> eventPriorityQueue; 
    bool tellerAvailable = true;
    int currentTime;
    double totalCustomers = 0;
    double totalWaitingTime = 0;

    int arrivalTime, transactionTime;
    std::string line;

    while (std::getline(std::cin, line)) {
        

        std::istringstream iss(line);

        if (!(iss >> arrivalTime >> transactionTime)) {
            std::cerr << "Reading Line Error " << line << std::endl;
            continue;
        }
        Event newArrivalEvent('A', arrivalTime, transactionTime);
        eventPriorityQueue.enqueue(newArrivalEvent);
    }


    //Loops and prints all the arrival times and departure times for events
    std::cout << "Simulation Begins" << std::endl;
    while (!eventPriorityQueue.isEmpty()) {
        Event newEvent = eventPriorityQueue.peek();
        currentTime = newEvent.getTime();
        int departureTime;
        Event customer = newEvent;


        //processing Arrival times for each customer
        if (newEvent.getType() == 'A') {
            std::cout << "Processing an arrival event at time: " << std::setw(6) << newEvent.getTime() << std::endl;
            eventPriorityQueue.dequeue();
            if (bankLine.isEmpty() && tellerAvailable) {
                departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('D', departureTime);
                eventPriorityQueue.enqueue(newDepartureEvent);
                tellerAvailable = false;
            } else {
                bankLine.enqueue(customer); 
            }
        }

        //processing Departure times for each customer
        else {
            std::cout << "Processing an departure event at time: " << std::setw(4) << newEvent.getTime() << std::endl;
            eventPriorityQueue.dequeue();
            if (!bankLine.isEmpty()) {
                customer = bankLine.peek();
                bankLine.dequeue();

                //Change in departuretime after getting customer length
                departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('D', departureTime);
                eventPriorityQueue.enqueue(newDepartureEvent);
            } else {
                tellerAvailable = true;
            }
            totalCustomers++;
            totalWaitingTime += currentTime - customer.getTime();
    
        }
    }

    
    std::cout << "Simulation Ends" << std::endl;

    //Displaying the final statistics for bank simulator
    std::cout << "\nFinal Statistics:" << std::endl;
    std::cout << std::endl;
    std::cout << "    Total number of people processed: " << totalCustomers << std::endl;
    if (totalCustomers > 0) {
        double averageWaitingTime = totalWaitingTime/totalCustomers;
        std::cout << "    Average amount of time spent waiting: " << averageWaitingTime << std::endl;
    } else {
        std::cout << "    Average amount of time spent waiting: N/A (no customers processed)" << std::endl;
    }
    return 0;
}
