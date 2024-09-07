#include <stdio.h>
#include <math.h>

#define NUM_SAMPLES 10

// Function declarations
void halfWaveRectify(double input[], double output[], int size);
void fullWaveRectify(double input[], double output[], int size);
void printArray(double array[], int size);

int main() {
    // Sample AC input values (representing one cycle of a sine wave)
    double acInput[NUM_SAMPLES] = {0, 0.5, 0.9, 1.0, 0.9, 0.5, 0, -0.5, -0.9, -1.0};
    double halfWaveOutput[NUM_SAMPLES];
    double fullWaveOutput[NUM_SAMPLES];

    // Perform rectification
    halfWaveRectify(acInput, halfWaveOutput, NUM_SAMPLES);
    fullWaveRectify(acInput, fullWaveOutput, NUM_SAMPLES);

    // Display results
    printf("AC Input Values:\n");
    printArray(acInput, NUM_SAMPLES);

    printf("\nHalf-Wave Rectifier Output:\n");
    printArray(halfWaveOutput, NUM_SAMPLES);

    printf("\nFull-Wave Rectifier Output:\n");
    printArray(fullWaveOutput, NUM_SAMPLES);

    return 0;
}

// Function to perform half-wave rectification
void halfWaveRectify(double input[], double output[], int size) {
    int i;  // Declare variable before the loop
    for (i = 0; i < size; i++) {
        output[i] = (input[i] > 0) ? input[i] : 0;
    }
}

// Function to perform full-wave rectification
void fullWaveRectify(double input[], double output[], int size) {
    int i;  // Declare variable before the loop
    for (i = 0; i < size; i++) {
        output[i] = fabs(input[i]);
    }
}

// Function to print an array
void printArray(double array[], int size) {
    int i;  // Declare variable before the loop
    for (i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

