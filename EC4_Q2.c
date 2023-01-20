#include <stdio.h>

int minAntennas(int housePositions[], int numberOfHouses, int coverageRadius) {
    
    int lastCoveredHouse = housePositions[0], numberOfAntennas = 1;
    
    for (int i = 1; i < numberOfHouses; i++) {
        if (housePositions[i] - lastCoveredHouse > coverageRadius) {
            lastCoveredHouse = housePositions[i];
            numberOfAntennas++;
        }
    }
    
    return numberOfAntennas;
}

int main() {
    int housePositions[] = {1, 4, 7, 10, 13, 16, 19, 21}, coverageRadius = 5, numberOfHouses = 8;
    
    printf("The minimum number of antennas required is: %d", minAntennas(housePositions, numberOfHouses, coverageRadius));
    
    return 0;
}
