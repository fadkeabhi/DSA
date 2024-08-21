import requests

url = "https://jsonmock.hackerrank.com/api/medical_records"

lmin = 120
lmax = 160

ans = 0

r = requests.get(url)
total_pages = r.json()["total_pages"]

for i in range(1, total_pages+1):
    params = {"page":i}
    r = requests.get(url, params=params)
    for data in r.json()["data"]:
        bpd = data["vitals"]["bloodPressureDiastole"]
        if bpd >= lmin and bpd <= lmax:
            ans += 1

            
print(ans)
