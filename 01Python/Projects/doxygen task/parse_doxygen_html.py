import os
import csv
from bs4 import BeautifulSoup

# Directory containing the Doxygen-generated HTML files
html_dir = 'docs/html'

# List to store extracted information
functions_info = []

# Parse each HTML file in the directory
for filename in os.listdir(html_dir):
    if filename.endswith('.html'):
        filepath = os.path.join(html_dir, filename)
        with open(filepath, 'r', encoding='utf-8') as file:
            soup = BeautifulSoup(file, 'html.parser')
            
            # Extract function details
            for func in soup.find_all('div', class_='memberdef'):
                name = func.find('name').text
                brief = func.find('briefdescription').text.strip()
                params = func.find_all('param')
                param_list = [(p.find('type').text, p.find('declname').text) for p in params]
                
                functions_info.append({
                    'name': name,
                    'brief': brief,
                    'parameters': param_list
                })

# Write extracted information to CSV
csv_file = 'functions_info.csv'
with open(csv_file, 'w', newline='', encoding='utf-8') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Function Name', 'Brief Description', 'Parameters'])
    for func_info in functions_info:
        param_str = ', '.join([f'{ptype} {pname}' for ptype, pname in func_info['parameters']])
        writer.writerow([func_info['name'], func_info['brief'], param_str])

print(f'Extracted information saved to {csv_file}')
