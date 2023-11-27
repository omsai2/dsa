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

// Function to perform Bubble Sort on employee names
void bubbleSort(struct Employee employees[], int numEmployees) {
    int i, j;
    struct Employee temp;

    for (i = 0; i < numEmployees - 1; i++) {
        for (j = 0; j < numEmployees - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                // Swap if the names are in the wrong order
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort on employee names
void selectionSort(struct Employee employees[], int numEmployees) {
    int i, j, minIndex;
    struct Employee temp;

    for (i = 0; i < numEmployees - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < numEmployees; j++) {
            if (strcmp(employees[j].name, employees[minIndex].name) < 0) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = employees[minIndex];
        employees[minIndex] = employees[i];
        employees[i] = temp;
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

    // Sort based on names using Bubble Sort
    bubbleSort(employees, numEmployees);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponname_bubblesort.txt");

    // Sort based on names using Selection Sort
    selectionSort(employees, numEmployees);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponname_selectionsort.txt");

    return 0;
}

