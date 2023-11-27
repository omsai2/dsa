
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[100];
    // Add other employee data fields as needed
};

// Function to read employee data from file
void readEmployeeData(FILE *file, struct Employee employees[], int *numEmployees) {
    while (fscanf(file, "%99[^\n]%*c", employees[*numEmployees].name) != EOF) {
        (*numEmployees)++;
    }
}

// Function to find the maximum string length in the array
int findMaxLength(struct Employee employees[], int numEmployees) {
    int maxLength = 0;
    for (int i = 0; i < numEmployees; i++) {
        int currentLength = strlen(employees[i].name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    return maxLength;
}

// Counting Sort for Strings
void countingSortStrings(struct Employee employees[], int numEmployees, int position) {
    const int range = 128; // Assuming ASCII characters

    struct Employee *output = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));
    int count[range + 1];

    // Initialize count array
    for (int i = 0; i <= range; i++) {
        count[i] = 0;
    }

    // Count occurrences of characters at the specified position
    for (int i = 0; i < numEmployees; i++) {
        int index = (position < strlen(employees[i].name)) ? employees[i].name[position] : 0;
        count[index]++;
    }

    // Modify count array to store the position of each character in the sorted array
    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    for (int i = numEmployees - 1; i >= 0; i--) {
        int index = (position < strlen(employees[i].name)) ? employees[i].name[position] : 0;
        output[count[index] - 1] = employees[i];
        count[index]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < numEmployees; i++) {
        employees[i] = output[i];
    }

    free(output);
}

// Radix Sort for Strings
void radixSortStrings(struct Employee employees[], int numEmployees) {
    int maxLength = findMaxLength(employees, numEmployees);

    for (int position = maxLength - 1; position >= 0; position--) {
        countingSortStrings(employees, numEmployees, position);
    }
}

// Function to write sorted employee data to a file
void writeSortedDataToFile(struct Employee employees[], int numEmployees, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "%s\n", employees[i].name);
    }

    fclose(file);
}

// Function to display sorted employee data
void displayEmployeeData(struct Employee employees[], int numEmployees) {
    printf("Sorted Employee Data:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s\n", employees[i].name);
    }
}

int main() {
    FILE *file = fopen("employee.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Employee employees[100]; // Assuming a maximum of 100 employees
    int numEmployees = 0;

    // Read employee data from the file
    readEmployeeData(file, employees, &numEmployees);

    // Close the file after reading
    fclose(file);

    // Sort based on names using Radix Sort
    radixSortStrings(employees, numEmployees);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponname_radixsort.txt");

    return 0;
}

