import requests
from bs4 import BeautifulSoup

def get_public_ip():
    """
    Fetches the public IP address.
    """
    response = requests.get('https://api.ipify.org/?format=json')
    soup = BeautifulSoup(response.text, 'html.parser')
    ip_data = soup.text
    return ip_data

def get_location(ip):
    """
    Fetches the location information based on the IP address.
    """
    response = requests.get(f'https://ipinfo.io/{ip}/geo')
    soup = BeautifulSoup(response.text, 'html.parser')
    location_data = soup.text
    return location_data

def main():
    # Get public IP address
    ip_data = get_public_ip()
    ip = eval(ip_data)['ip']  # Use eval to parse the JSON string
    print(f"Your public IP address is: {ip}")
    
    # Get location information based on IP
    location_data = get_location(ip)
    location = eval(location_data)  # Use eval to parse the JSON string
    print("Your location information:")
    print(f"  City: {location.get('city')}")
    print(f"  Region: {location.get('region')}")
    print(f"  Country: {location.get('country')}")
    print(f"  Location (lat, long): {location.get('loc')}")

if __name__ == "__main__":
    main()
