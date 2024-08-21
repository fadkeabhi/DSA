import requests

url = "https://jsonmock.hackerrank.com/api/medical_records"

diagnosisName = "Common Cold"
doctorId = 2

r = requests.get(url)
total_pages = r.json()["total_pages"]
# print(total_pages)

ans = 0

for i in range(1, total_pages):
    params = {"page": i}
    r = requests.get(url, params= params)
    for data in r.json()["data"]:
        if data["diagnosis"]["name"] == diagnosisName and data["doctor"]["id"] == doctorId:
            ans += 1
    
    print(ans)