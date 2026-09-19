#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIALITIES 4
#define WARDS 4
#define MAX_PATIENTS 100
#define MAX_BEDS 20

void displaySpecialties(int specialtyID[], char specialtyName[][30], float consultationFee[], int consultationTime[]);
void displayWards(int wardID[], char wardName[][30], float dailyBedRate[], int totalBedCapacity[], int bedOccupancy[][MAX_BEDS]);
void addPatient(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int *patientCount, int totalBedCapacity[], int bedOccupancy[][MAX_BEDS]);
void displayPatients(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount);
void searchPatient(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount);
void sortPatientsByPriority(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount);

int main()
{
    int specialtyID[SPECIALITIES] = {1, 2, 3, 4};

    char specialtyName[SPECIALITIES][30] =
    {
        "General Practice",
        "Paediatrics",
        "Cardiology",
        "Neurology"
    };

    float consultationFee[SPECIALITIES] =
    {
        1500.00,
        2500.00,
        4500.00,
        5000.00
    };

    int consultationTime[SPECIALITIES] =
    {
        15,
        20,
        30,
        30
    };

    int dailyPatientCap[SPECIALITIES] =
    {
        30,
        20,
        12,
        10
    };

    int wardID[WARDS] = {1,2, 3, 4};

    char wardName[WARDS][30] =
    {
        "General Ward",
        "Paediatric Ward",
        "Surgical Ward",
        "ICU"
    };

    float dailyBedRate[WARDS] =
    {
        3000.00,
        6000.00,
        12000.00,
        25000.00
    };

    int totalBedCapacity[WARDS] =
    {
        20,
        10,
        10,
        5
    };

    int bedOccupancy[WARDS][MAX_BEDS] = {0};

    int patientID[MAX_PATIENTS];
    char patientNames[MAX_PATIENTS][50];
    int patientAge[MAX_PATIENTS];
    int agencyLevel[MAX_PATIENTS];
    int patientSpecialty[MAX_PATIENTS];
    int patientWard[MAX_PATIENTS];
    int daysAdmitted[MAX_PATIENTS];
    int patientBed[MAX_PATIENTS];

    float waitingTime[MAX_PATIENTS];
    float baseFee[MAX_PATIENTS];
    float emergencySurcharge[MAX_PATIENTS];
    float wardStayCost[MAX_PATIENTS];
    float grossTotal[MAX_PATIENTS];
    float ageDiscount[MAX_PATIENTS];
    float finalPayable[MAX_PATIENTS];

    int patientCount = 0;

    int choice;

    do
    {
        printf("\n=====================================================\n");
        printf("\t\tSMART HOSPITAL SYSTEM\n");
        printf("=====================================================\n");
        printf("1. Display Specialties\n");
        printf("2. Display Wards\n");
        printf("3. Add Patient\n");
        printf("4. Display Patients\n");
        printf("5. Search Patient\n");
        printf("6. Display Patients by Priority\n");
        printf("7. Exit\n");
        printf("-----------------------------------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            displaySpecialties(specialtyID, specialtyName, consultationFee, consultationTime);
            break;

        case 2:
            displayWards(wardID, wardName, dailyBedRate, totalBedCapacity, bedOccupancy);
            break;

        case 3:
            addPatient(patientID, patientNames, patientAge, agencyLevel, patientSpecialty, patientWard, daysAdmitted, patientBed, &patientCount, totalBedCapacity, bedOccupancy);
            break;

        case 4:
            displayPatients(patientID, patientNames, patientAge, agencyLevel, patientSpecialty, patientWard, daysAdmitted, patientBed, patientCount);
            break;

        case 5:
            searchPatient(patientID, patientNames, patientAge, agencyLevel, patientSpecialty, patientWard, daysAdmitted, patientBed, patientCount);
            break;

        case 6:
            sortPatientsByPriority(patientID, patientNames, patientAge, agencyLevel, patientSpecialty, patientWard, daysAdmitted, patientBed, patientCount);
            break;

        case 7:
            printf("\nExiting Smart Hospital System...\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }


    } while(choice != 7);

    return 0;
}

void displaySpecialties(int specialtyID[], char specialtyName[][30], float consultationFee[], int consultationTime[])
{
    int i;

    printf("\n=====================================================\n");
    printf("\t\tDOCTOR SPECIALTIES\n");
    printf("=====================================================\n");
    printf("%-5s %-25s %-12s %-10s\n", "ID", "Specialty", "Fee", "Time");
    printf("-----------------------------------------------------\n");

    for (int i=0; i<SPECIALITIES; i++){
        printf("%-5d %-25s LKR %-8.2f %d mins\n", specialtyID[i], specialtyName[i], consultationFee[i], consultationTime[i]);

    }

    printf("\n=====================================================\n");
}

void displayWards(int wardID[], char wardName[][30], float dailyBedRate[], int totalBedCapacity[], int bedOccupancy[][MAX_BEDS])
{
    int i;

    printf("\n=====================================================\n");
    printf("\t\tWARD INFORMATION\n");
    printf("=====================================================\n");
    printf("%-5s %-20s %-15s %-10s\n", "ID", "Ward", "Daily Rate", "Capacity");
    printf("-----------------------------------------------------\n");

    for(i=0; i<WARDS; i++)
    {
        printf("%-5d %-20s LKR %-10.2f %-10d\n", wardID[i], wardName[i], dailyBedRate[i], totalBedCapacity[i]);
    }

    printf("=====================================================\n");
}

void addPatient(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int *patientCount, int totalBedCapacity[], int bedOccupancy[][MAX_BEDS])
{
    if(*patientCount >= MAX_PATIENTS)
    {
        printf("patient limit reached! Cannot add more patients\n");
        return;
    }

    printf("\n=====================================================\n");
    printf("\t\tADD PATIENT\n");
    printf("=====================================================\n");

    int i;

    printf("Enter Patient ID: ");
    scanf("%d", &patientID[*patientCount]);

    for(i=0; i < *patientCount; i++)
    {
        if(patientID[i] == patientID[*patientCount])
        {
            printf("\nPatient ID already exists!\n");
            return;
        }
    }

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patientNames[*patientCount]);

    printf("Enter Patient Age: ");
    scanf("%d", &patientAge[*patientCount]);

    if(patientAge[*patientCount] <= 0)
    {
        printf("\nInvalid age!\n");
        return;
    }

    printf("Enter Patient Agency Level: ");
    scanf("%d", &agencyLevel[*patientCount]);

    if(agencyLevel[*patientCount] < 1 || agencyLevel[*patientCount] > 3)
    {
        printf("\nInvalid Agency Level!\n");
        return;
    }

    printf("Enter Patient Specialty ID: ");
    scanf("%d", &patientSpecialty[*patientCount]);

    if(patientSpecialty[*patientCount] < 1 || patientSpecialty[*patientCount] > SPECIALITIES)
    {
        printf("\nInvalid Specialty ID!\n");
        return;
    }

    printf("Enter Patient Ward ID: ");
    scanf("%d", &patientWard[*patientCount]);

    if(patientWard[*patientCount] < 1 || patientWard[*patientCount] > WARDS)
    {
        printf("\nInvalid Ward ID!\n");
        return;
    }

    printf("Enter Days Admitted: ");
    scanf("%d", &daysAdmitted[*patientCount]);

    if(daysAdmitted[*patientCount] <= 0)
    {
        printf("\nInvalid number of days!\n");
        return;
    }

    printf("Enter Bed Number: ");
    scanf("%d", &patientBed[*patientCount]);

    if(patientBed[*patientCount] < 1 || patientBed[*patientCount] > totalBedCapacity[patientWard[*patientCount] - 1])
    {
        printf("\nInvalid Bed Number for this ward!\n");
        return;
    }

    if(bedOccupancy[patientWard[*patientCount] - 1][patientBed[*patientCount] - 1] == 1)
    {
        printf("\nBed is already occupied! Please choose another bed\n");
        return;
    }

    bedOccupancy[patientWard[*patientCount] - 1][patientBed[*patientCount] - 1] = 1;

    (*patientCount)++;

    printf("\nPatient added successfully!\n");
    printf("=====================================================\n");
}

void displayPatients(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount)
{
    int i;

    if(patientCount == 0)
    {
        printf("\nNo patients registered yet!\n");
        return;
    }

    printf("\n==============================================================================\n");
    printf("\t\t\tPATIENT INFORMATION\n");
    printf("==============================================================================\n");
    printf("%-6s %-20s %-6s %-8s %-10s %-8s %-8s %-6s\n", "ID", "Name", "Age", "Agency", "Specialty", "Ward", "Days", "Bed");
    printf("------------------------------------------------------------------------------\n");

    for(i=0; i < patientCount; i++)
    {
        printf("%-6d %-20s %-6d %-8d %-10d %-8d %-8d %-6d\n", patientID[i], patientNames[i], patientAge[i], agencyLevel[i], patientSpecialty[i], patientWard[i], daysAdmitted[i], patientBed[i]);
    }

    printf("==============================================================================\n");
}

void searchPatient(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount)
{
    int searchID;
    int i;
    int found = 0;

    if(patientCount == 0)
    {
        printf("\nNo patients registered yet!\n");
        return;
    }

    printf("\n=====================================================\n");
    printf("\t\tSEARCH PATIENT\n");
    printf("=====================================================\n");

    printf("Enter Patient ID to search: ");
    scanf("%d", &searchID);

    for(i=0; i < patientCount; i++)
    {
        if(patientID[i] == searchID)
        {
            printf("\nPatient Found!\n");
            printf("-----------------------------------------------------\n");
            printf("Patient ID    : %d\n", patientID[i]);
            printf("Patient Name  : %s\n", patientNames[i]);
            printf("Patient Age   : %d\n", patientAge[i]);
            printf("Agency Level  : %d\n", agencyLevel[i]);
            printf("Specialty ID  : %d\n", patientSpecialty[i]);
            printf("Ward ID       : %d\n", patientWard[i]);
            printf("Days Admitted : %d\n", daysAdmitted[i]);
            printf("Bed Number    : %d\n", patientBed[i]);
            printf("-----------------------------------------------------\n");

            found = 1;
            break;

        }
    }

    if(found == 0)
    {
        printf("\nPatient with ID %d not found!\n", searchID);
    }

    printf("=====================================================\n");

}

void sortPatientsByPriority(int patientID[], char patientNames[][50], int patientAge[], int agencyLevel[], int patientSpecialty[], int patientWard[], int daysAdmitted[], int patientBed[], int patientCount)
{
    int i, j;

    int tempID;
    int tempAge;
    int tempAgency;
    int tempSpecialty;
    int tempWard;
    int tempDays;
    int tempBed;

    char tempName[50];

    if(patientCount == 0)
    {
        printf("\nNo patients registered yet!\n");
        return;
    }

    /* Bubble sort:
    Higher urgency level gets higher priority.
    Registration order is maintained when urgency levels are equal, */

    for(i=0; i < patientCount - 1; i++)
    {
        for(j=0; j < patientCount - i - j; j++)
        {
            if(agencyLevel[j] < agencyLevel[j+1])
            {
                tempID = patientID[j];
                patientID[j] = patientID[j+1];
                patientID[j+1] = tempID;

                strcpy(tempName, patientNames[j]);
                strcpy(patientNames[j], patientNames[j+1]);
                strcpy(patientNames[j+1], tempName);

                tempAge = patientAge[j];
                patientAge[j] = patientAge[j+1];
                patientAge[j+1] = tempAge;

                tempAgency = agencyLevel[j];
                agencyLevel[j] = agencyLevel[j+1];
                agencyLevel[j+1] = tempAgency;

                tempSpecialty = patientSpecialty[j];
                patientSpecialty[j] = patientSpecialty[j+1];
                patientSpecialty[j+1] = tempSpecialty;

                tempWard = patientWard[j];
                patientWard[j] = patientWard[j+1];
                patientWard[j+1] = tempWard;

                tempDays = daysAdmitted[j];
                daysAdmitted[j] = daysAdmitted[j+1];
                daysAdmitted[j+1] = tempDays;

                tempBed = patientBed[j];
                patientBed[j] = patientBed[j+1];
                patientBed[j+1] = tempBed;
            }
        }
    }

    printf("\n=====================================================\n");
    printf("\t\tPATIENTS BY PRIORITY\n");
    printf("=====================================================\n");
    printf("%-6s %-20s %-6s %-10s %-10s\n", "ID", "Name", "Age", "Urgency", "Bed");
    printf("-----------------------------------------------------\n");

    for(i=0; i < patientCount; i++)
    {
        printf("%-6d %-20s %-6d %-10d %-10d\n", patientID[i], patientNames[i], patientAge[i], agencyLevel[i], patientBed[i]);
    }

    printf("=====================================================\n");
}

