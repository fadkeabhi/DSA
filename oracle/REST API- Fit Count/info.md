# REST API: Fit Count

## Problem Description

This task involves building a function to determine the number of "fit" individuals from a paginated medical records API. You'll retrieve patient data, filter based on diastolic blood pressure range, and return the count of patients meeting the criteria.

## API Details

**Endpoint:** https://jsonmock.hackerrank.com/api/medical-records

**Method:** GET

**Pagination:** The API returns paginated results. To access specific pages, append `?page=num` to the URL, where `num` is the page number.

**Response Format (JSON):**

```json
{
  "page": 1,                // Current page number
  "per_page": 10,           // Results per page
  "total": 100,              // Total records
  "total_pages": 10,         // Total pages
  "data": [                  // Array of medical record objects
    {
      "id": "some-uuid",
      "timestamp": 1678886400000,
      "userId": "some-uuid",
      "userName": "John Doe",
      "dateOfBirth": "1980-01-15",
      "vitals": {
        "bloodPressureDiastole": 80,  // Diastolic pressure (mmHg)
        "bloodPressureSystole": 120, // Systolic pressure (mmHg)
        "pulse": 72,                 // Pulse rate (bpm)
        "breathingRate": 12,          // Breathing rate (breaths/min)
        "bodyTemperature": 98.6       // Body temperature (°F)
      },
      "diagnosis": {
        "id": "some-uuid",
        "name": "Common Cold",
        "severity": "Mild"
      },
      "doctor": {
        "id": "some-uuid",
        "name": "Dr. Jane Smith"
      },
      "meta": {
        "heightCm": 180,              // Height (cm)
        "weightLb": 170               // Weight (lbs)
      }
    },
    // ... more medical records
  ]
}
```

## Function Requirements

**Function Name:** `healthCheck`

**Parameters:**

* `lowerLimit`: (int) Lower bound of the diastolic blood pressure range (inclusive).
* `upperLimit`: (int) Upper bound of the diastolic blood pressure range (inclusive).

**Returns:** (int) The number of patients with diastolic blood pressure within the specified range.

**Logic:**

1. Retrieve all medical records from the API (handle pagination).
2. For each record:
   - Check if the `vitals.bloodPressureDiastole` value falls within the `lowerLimit` and `upperLimit` (inclusive).
   - Increment a counter if the condition is met.
3. Return the final count.
