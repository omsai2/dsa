#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[100];
    int age;
    // Add other employee data fields as needed
};

// Function to read employee data from file
void readEmployeeData(FILE *file, struct Employee employees[], int *numEmployees) {
    while (fscanf(file, "%99s %d", employees[*numEmployees].name, &employees[*numEmployees].age) == 2) {
        (*numEmployees)++;
    }
}

// Counting Sort
void countingSort(struct Employee employees[], int numEmployees) {
    // Find the maximum age to determine the size of the count array
    int maxAge = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].age > maxAge) {
            maxAge = employees[i].age;
        }
    }

    int *count = (int *)malloc((maxAge + 1) * sizeof(int));
    struct Employee *sortedArray = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    // Initialize count array
    for (int i = 0; i <= maxAge; i++) {
        count[i] = 0;
    }

    // Count occurrences of each age
    for (int i = 0; i < numEmployees; i++) {
        count[employees[i].age]++;
    }

    // Modify count array to store the position of each age in the sorted array
    for (int i = 1; i <= maxAge; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    for (int i = numEmployees - 1; i >= 0; i--) {
        sortedArray[count[employees[i].age] - 1] = employees[i];
        count[employees[i].age]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < numEmployees; i++) {
        employees[i] = sortedArray[i];
    }

    free(count);
    free(sortedArray);
}

// Merge Sort
void merge(struct Employee employees[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Employee *leftArray = (struct Employee *)malloc(n1 * sizeof(struct Employee));
    struct Employee *rightArray = (struct Employee *)malloc(n2 * sizeof(struct Employee));

    for (int i = 0; i < n1; i++) {
        leftArray[i] = employees[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = employees[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].age <= rightArray[j].age) {
            employees[k] = leftArray[i];
            i++;
        } else {
            employees[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        employees[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        employees[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(struct Employee employees[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(employees, left, mid);
        mergeSort(employees, mid + 1, right);
        merge(employees, left, mid, right);
    }
}

// Quick Sort
int partition(struct Employee employees[], int low, int high) {
    int pivot = employees[high].age;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (employees[j].age < pivot) {
            i++;
            struct Employee temp = employees[i];
            employees[i] = employees[j];
            employees[j] = temp;
        }
    }

    struct Employee temp = employees[i + 1];
    employees[i + 1] = employees[high];
    employees[high] = temp;

    return i + 1;
}

void quickSort(struct Employee employees[], int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);
        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
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
        fprintf(file, "%s %d\n", employees[i].name, employees[i].age);
    }

    fclose(file);
}

// Function to display sorted employee data
void displayEmployeeData(struct Employee employees[], int numEmployees) {
    printf("Sorted Employee Data:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s %d\n", employees[i].name, employees[i].age);
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

    // Sort based on age using Counting Sort
    countingSort(employees, numEmployees);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponage_countingsort.txt");

    // Sort based on age using Merge Sort
    mergeSort(employees, 0, numEmployees - 1);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponage_mergesort.txt");

    // Sort based on age using Quick Sort
    quickSort(employees, 0, numEmployees - 1);
    displayEmployeeData(employees, numEmployees);
    writeSortedDataToFile(employees, numEmployees, "sortedemponage_quicksort.txt");

    return 0;
}

