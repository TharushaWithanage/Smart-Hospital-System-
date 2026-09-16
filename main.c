#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIALITIES 4
#define WARDS 4
#define MAX_PATIENTS 100
#define MAX_BEDS 20

void displaySpecialties(int specialtyID[], char specialtyName[][30], float consultationFee[], int consultationTime[]);
void displayWards(int wardID[], char wardName[][30], float dailyBedRate[], int totalBedCapacity[], int bedOccupancy[][MAX_BEDS]);

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

    displaySpecialties(specialtyID, specialtyName, consultationFee, consultationTime);
    displayWards(wardID, wardName, dailyBedRate, totalBedCapacity, bedOccupancy);



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
