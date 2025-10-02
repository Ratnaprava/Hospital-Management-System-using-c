#include <stdio.h>

#define MAX_PATIENTS 100

// Structure to store patient information
struct Patient
 {
    char name[50];
    int age;
    char gender;
    char disease[50];
};

// Function prototypes
void addPatient(struct Patient patients[], int *numPatients);
void displayPatients(struct Patient patients[], int numPatients);
void searchPatient(struct Patient patients[], int numPatients);
void displayMenu();

int main()
 {
    struct Patient patients[MAX_PATIENTS];
    int numPatients = 0;
    int choice;

    do 
	{
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                addPatient(patients, &numPatients);
                break;
            case 2:
                displayPatients(patients, numPatients);
                break;
            case 3:
                searchPatient(patients, numPatients);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    }
	 while (choice != 4);

    return 0;
}

void addPatient(struct Patient patients[], int *numPatients) 
{
    if (*numPatients < MAX_PATIENTS) {
        printf("Enter patient details:\n");
        printf("Name: ");
        scanf("%s", patients[*numPatients].name);
        printf("Age: ");
        scanf("%d", &patients[*numPatients].age);
        printf("Gender (M/F): ");
        scanf(" %c", &patients[*numPatients].gender);
        printf("Disease: ");
        scanf("%s", patients[*numPatients].disease);

        (*numPatients)++;

        printf("Patient added successfully.\n");
    }
	 else
	  {
        printf("Maximum number of patients reached.\n");
    }
}

void displayPatients(struct Patient patients[], int numPatients) {
    if (numPatients > 0) {
        printf("List of Patients:\n");
        int i;
        for (i = 0; i < numPatients; ++i) {
            printf("Patient %d:\n", i + 1);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("Disease: %s\n", patients[i].disease);
            printf("--------------------------\n");
        }
    } else {
        printf("No patients in the system.\n");
    }
}

void searchPatient(struct Patient patients[], int numPatients) {
    char searchName[50];
    printf("Enter the name of the patient to search: ");
    scanf("%s", searchName);
	int i;
    for (i = 0; i < numPatients; ++i) {
        if (strcmp(patients[i].name, searchName) == 0) {
            printf("Patient found:\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("Disease: %s\n", patients[i].disease);
            return;
        }
    }

    printf("Patient with name '%s' not found.\n", searchName);
}

void displayMenu() {
    printf("\nHospital Management System\n");
    printf("1. Add Patient\n");
    printf("2. Display Patients\n");
    printf("3. Search Patient\n");
    printf("4. Exit\n");
}
