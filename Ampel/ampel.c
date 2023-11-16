#include <stdio.h>
#include <unistd.h>

// Enumeration representing the state of the traffic light
enum TrafficLightState {
    RED,
    GREEN,
    YELLOW
};

// Function to display the current state of the traffic light
void displayState(enum TrafficLightState currentState) {
    switch (currentState) {
        case RED:
            printf("Traffic light: RED\n");
            break;
        case GREEN:
            printf("Traffic light: GREEN\n");
            break;
        case YELLOW:
            printf("Traffic light: YELLOW\n");
            break;
    }
}

// Function to simulate the passage of time
void delay(int seconds) {
    sleep(seconds);
}

// Function to control the traffic light
void controlTrafficLight() {
    enum TrafficLightState currentState = RED;

    while (1) { // Infinite loop for simulation

        // Display the current state
        displayState(currentState);

        // Control the traffic light based on the current state
        switch (currentState) {
            case RED:
                delay(5); // Red light for 5 seconds
                currentState = GREEN;
                break;
            case GREEN:
                delay(7); // Green light for 7 seconds
                currentState = YELLOW;
                break;
            case YELLOW:
                delay(3); // Yellow light for 3 seconds
                currentState = RED;
                break;
        }
    }
}

int main() {
    // Start simulating the traffic light
    controlTrafficLight();

    return 0;
}
