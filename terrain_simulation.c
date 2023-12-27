#include <stdio.h>
#include <string.h>
//Created with ChatGPT (GPT 4.0) by Tsubasa Kato 12/27/2023 10:22AM
//Please visit our company: https://www.inspiresearch.io/en
// Define the possible terrain types
typedef enum {
    ROUGH,
    FLAT,
    GRAVEL
} TerrainType;

// Define the possible car types
typedef enum {
    JEEP,
    BUGGY,
    TRUCK_4WD // 4WD Truck
} CarType;

// Define the possible speed types
typedef enum {
    SLOW,
    MEDIUM,
    FAST
} Speed;

// Function to determine if car goes out of control
int isOutOfControl(CarType car, TerrainType terrain, Speed speed) {
    // Specific conditions where car might go out of control
    if (terrain == ROUGH && speed == FAST) return 1; // Fast on rough terrain
    if (terrain == GRAVEL && (car == BUGGY || speed == FAST)) return 1; // Buggy or fast on gravel
    return 0; // Otherwise, assume control is maintained
}

// Function to simulate driving a car through terrain
void simulateDrive(CarType car, TerrainType terrain, Speed speed) {
    printf("Simulating Drive...\n");
    printf("Terrain: ");
    switch(terrain) {
        case ROUGH: printf("Rough\n"); break;
        case FLAT: printf("Flat\n"); break;
        case GRAVEL: printf("Gravel\n"); break;
    }

    printf("Car Type: ");
    switch(car) {
        case JEEP: printf("Jeep\n"); break;
        case BUGGY: printf("Buggy\n"); break;
        case TRUCK_4WD: printf("4WD Truck\n"); break;
    }

    printf("Speed: ");
    switch(speed) {
        case SLOW: printf("Slow\n"); break;
        case MEDIUM: printf("Medium\n"); break;
        case FAST: printf("Fast\n"); break;
    }

    // Check if car goes out of control
    if (isOutOfControl(car, terrain, speed)) {
        printf("Result: The car has gone out of control! Reduce speed or choose a better car for this terrain.\n");
    } else {
        // Simulate the effects based on the terrain, car, and speed
        printf("Result: ");
        if (terrain == ROUGH && car == TRUCK_4WD && speed != FAST) {
            printf("Successfully navigated through rough terrain.\n");
        } else if (terrain == GRAVEL && car != BUGGY) {
            printf("Careful! Slipping on gravel.\n");
        } else if (terrain == FLAT) {
            printf("Smooth drive.\n");
        } else {
            printf("Difficult conditions, proceed with caution!\n");
        }
    }
}

int main() {
    // Nested loops to iterate through every combination of terrain, car, and speed
    for (int t = ROUGH; t <= GRAVEL; t++) {
        for (int c = JEEP; c <= TRUCK_4WD; c++) {
            for (int s = SLOW; s <= FAST; s++) {
                // Cast ints back to the respective enum type for clarity
                TerrainType terrain = (TerrainType)t;
                CarType car = (CarType)c;
                Speed speed = (Speed)s;

                // Simulate driving with the current combination of terrain, car, and speed
                simulateDrive(car, terrain, speed);
            }
        }
    }

    return 0;
}
