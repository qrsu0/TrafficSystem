#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class TrafficLight {
public:
    string location;
    string state;

    TrafficLight(string loc, string st) : location(loc), state(st) {}

    void changeState(string newState) {
        state = newState;
    }
};

class TrafficCondition {
public:
    string location;
    int trafficDensity;
    string lastUpdated;

    TrafficCondition(string loc, int density) : location(loc), trafficDensity(density) {
        updateTraffic();
    }

    void updateTraffic() {
        trafficDensity = rand() % 100;
        time_t now = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &now);
        lastUpdated = buffer;
        lastUpdated.pop_back();
    }

};

class Incident {
public:
    string type;
    string location;
    string status;

    Incident(string t, string loc) : type(t), location(loc), status("Reported") {}

    void report() {
        cout << "Incident reported: " << type << " at " << location << endl;
    }
};

class Route {
public:
    string startPoint;
    string endPoint;

    Route(string start, string end) : startPoint(start), endPoint(end) {}

    void calculateRoute() {
        cout << "Calculating route from " << startPoint << " to " << endPoint << endl;
    }
};

void manageTrafficLights(vector<TrafficLight>& trafficLights) {
    cout << "Managing Traffic Lights" << endl;
    for (size_t i = 0; i < trafficLights.size(); ++i) {
        cout << i + 1 << ". " << trafficLights[i].location << " - " << trafficLights[i].state << endl;
    }

    int choice;
    cout << "Select a traffic light to change state: ";
    cin >> choice;
    if (choice < 1 || choice > trafficLights.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    string newState;
    cout << "Enter new state (Red/Yellow/Green): ";
    cin >> newState;

    trafficLights[choice - 1].changeState(newState);
    cout << "Traffic light at " << trafficLights[choice - 1].location << " is now " << trafficLights[choice - 1].state << endl;
}

void monitorTraffic(vector<TrafficCondition>& trafficConditions) {
    cout << "Monitoring Traffic" << endl;
    for (auto& condition : trafficConditions) {
        condition.updateTraffic();
        cout << condition.location << " - Density: " << condition.trafficDensity << " (last updated: " << condition.lastUpdated << ")" << endl;
    }
}

void reportIncident() {
    string type, location;
    cout << "Enter incident type (Accident/Breakdown): ";
    cin >> type;
    cout << "Enter incident location: ";
    cin >> location;

    Incident incident(type, location);
    incident.report();
}

void planRoute() {
    string startPoint, endPoint;

    cout << "Enter start point: ";
    cin >> startPoint;
    cout << "Enter end point: ";
    cin >> endPoint;

    Route route(startPoint, endPoint);
    route.calculateRoute();
}

int main() {
    srand(time(0));

    vector<TrafficLight> trafficLights = {
        TrafficLight("Intersection 1", "Red"),
        TrafficLight("Intersection 2", "Green")
    };

    vector<TrafficCondition> trafficConditions = {
        TrafficCondition("Intersection 1", 50),
        TrafficCondition("Main Street", 75)
    };

    while (true) {
        cout << "==============================" << endl;
        cout << "  Traffic Management System" << endl;
        cout << "==============================" << endl;
        cout << "1. Manage Traffic Lights" << endl;
        cout << "2. Monitor Traffic" << endl;
        cout << "3. Report Incident" << endl;
        cout << "4. Plan Route" << endl;
        cout << "5. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        if (choice == 1) {
            manageTrafficLights(trafficLights);
        }
        else if (choice == 2) {
            monitorTraffic(trafficConditions);
        }
        else if (choice == 3) {
            reportIncident();
        }
        else if (choice == 4) {
            planRoute();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
