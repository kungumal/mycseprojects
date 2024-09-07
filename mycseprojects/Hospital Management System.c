#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define NAME_LENGTH 50

// Patient and Doctor structures
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char type[20]; // "inpatient" or "outpatient"
} Patient;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char specialty[NAME_LENGTH];
} Doctor;

// Global arrays to store patients and doctors
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;

// Function declarations
void addPatient();
void listPatients();
void searchPatient();
void addDoctor();
void searchDoctor();
void displayMenu();

int main() {
    int choice;
    
    // Adding some demo doctors
    doctorCount = 2;
    doctors[0] = (Doctor){1, "Dr. Smith", "Cardiology"};
    doctors[1] = (Doctor){2, "Dr. Johnson", "Neurology"};
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                listPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                addDoctor();
                break;
            case 5:
                searchDoctor();
                break;
            case 0:
                printf("Exiting the application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Hospital Management System ---\n");
    printf("1. Add Patient\n");
    printf("2. List Patients\n");
    printf("3. Search Patient\n");
    printf("4. Add Doctor\n");
    printf("5. Search Doctor\n");
    printf("0. Exit\n");
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    Patient p;
    printf("Enter patient ID: ");
    scanf("%d", &p.id);
    getchar();  // Consume the newline character
    printf("Enter patient name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0';  // Remove newline character
    printf("Enter patient age: ");
    scanf("%d", &p.age);
    getchar();  // Consume the newline character
    printf("Enter patient type (inpatient/outpatient): ");
    fgets(p.type, sizeof(p.type), stdin);
    p.type[strcspn(p.type, "\n")] = '\0';  // Remove newline character

    patients[patientCount++] = p;
    printf("Patient added successfully.\n");
}

void listPatients() {
    int i;  // Declare loop variable outside the loop
    if (patientCount == 0) {
        printf("No patients to display.\n");
        return;
    }

    printf("\n--- Patient List ---\n");
    for (i = 0; i < patientCount; i++) {
        printf("ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Type: %s\n", patients[i].type);
        printf("-------------------\n");
    }
}

void searchPatient() {
    int id, i;  // Declare loop variable outside the loop
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    getchar();  // Consume the newline character

    for (i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\n--- Patient Details ---\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Type: %s\n", patients[i].type);
            return;
        }
    }

    printf("Patient not found.\n");
}

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor list is full.\n");
        return;
    }

    Doctor d;
    printf("Enter doctor ID: ");
    scanf("%d", &d.id);
    getchar();  // Consume the newline character
    printf("Enter doctor name: ");
    fgets(d.name, sizeof(d.name), stdin);
    d.name[strcspn(d.name, "\n")] = '\0';  // Remove newline character
    printf("Enter doctor specialty: ");
    fgets(d.specialty, sizeof(d.specialty), stdin);
    d.specialty[strcspn(d.specialty, "\n")] = '\0';  // Remove newline character

    doctors[doctorCount++] = d;
    printf("Doctor added successfully.\n");
}

void searchDoctor() {
    int id, i;  // Declare loop variable outside the loop
    printf("Enter doctor ID to search: ");
    scanf("%d", &id);
    getchar();  // Consume the newline character

    for (i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            printf("\n--- Doctor Details ---\n");
            printf("ID: %d\n", doctors[i].id);
            printf("Name: %s\n", doctors[i].name);
            printf("Specialty: %s\n", doctors[i].specialty);
            return;
        }
    }

    printf("Doctor not found.\n");
}

