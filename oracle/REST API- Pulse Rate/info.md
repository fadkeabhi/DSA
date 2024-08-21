# REST API: Pulse Rate

## Problem Description

You need to implement a function that retrieves medical records from a paginated API, filters them based on diagnosis name and doctor ID, and calculates the average pulse rate of the filtered patients.

## API Details

**Endpoint:** https://jsonmock.hackerrank.com/api/medical_records

**Method:** GET

**Pagination:** Results are paginated. Access different pages by appending `?page=num` to the URL (`num` is the page number).

**Response Format (JSON):**

```json
{
  "page": 1,                // Current page
  "per_page": 10,           // Results per page
  "total": 100,              // Total records
  "total_pages": 10,         // Total pages
  "data": [                  // Array of medical record objects
    {
      "id": "some-uuid",
      "timestamp": 1678886400000,
      "userId": "some-uuid",
      "userName": "John Doe",
      "userDob": "1980-01-15",
      "vitals": {
        "bloodPressureDiastole": 80,
        "bloodPressureSystole": 120,
        "pulse": 72,                 // Pulse rate
        "breathingRate": 12,
        "bodyTemperature": 98.6
      },
      "diagnosis": {
        "id": "some-uuid",
        "name": "Common Cold",      // Diagnosis name
        "severity": "Mild"
      },
      "doctor": {
        "id": "some-uuid",          // Doctor ID
        "name": "Dr. Jane Smith"
      },
      "meta": {
        "heightCm": 180,
        "weightLb": 170
      }
    },
    // ... more medical records
  ]
}
```

## Function Requirements

**Function Name:** `pulseRate`

**Parameters:**

* `diagnosisName`: (string) The name of the diagnosis to filter by.
* `doctorId`: (int) The ID of the doctor to filter by.

**Returns:** (int) The average pulse rate (`vitals.pulse`) of patients matching the criteria, truncated to an integer (e.g., 1.99 becomes 1).

**Logic:**

1. Retrieve all medical records from the API, handling pagination.
2. Filter the records:
   - Keep only records where `diagnosis.name` matches the given `diagnosisName` **and** `doctor.id` matches the given `doctorId`.
3. Calculate the average pulse rate (`vitals.pulse`) from the filtered records.
4. Truncate the average to an integer and return the result.
