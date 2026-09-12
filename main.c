#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIALITIES 4
#define WARDS 4
#define MAX_PATIENTS 100
#define MAX_BEDS 20

int main()
{
    int specialtyID[SPECIALITIES] = {1, 2, 3, 4};

    char specialtyName[WARDS][30] =
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



    return 0;
}
