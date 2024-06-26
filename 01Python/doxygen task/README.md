# To achieve your task, you'll need to follow these steps:

1. Create a simple main.c file with Doxygen comments.
2. Generate HTML documentation from the main.c file using Doxygen.
3. Parse the generated HTML documentation and extract information using a Python script.
4. Save the extracted information into a CSV file.

## Step 1: Create main.c with Doxygen Comments

```c
/**
 * @file main.c
 * @brief A simple example to demonstrate Doxygen usage.
 */

/**
 * @brief Adds two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return Sum of the two integers.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtracts the second integer from the first.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return Difference of the two integers.
 */
int subtract(int a, int b) {
    return a - b;
}

int main() {
    int result1 = add(3, 4);
    int result2 = subtract(7, 2);

    return 0;
}
```

## Step 2: Generate HTML Documentation Using Doxygen
- Create a Doxyfile configuration file. You can generate a default Doxyfile using the 
```sh
sudo apt install doxygen
doxygen -g
```
- Modify the Doxyfile to set the following options:
OUTPUT_DIRECTORY = docs
GENERATE_HTML = YES
INPUT = main.c

- Run Doxygen with the configuration file:

```sh
doxygen Doxyfile
```
This will generate HTML documentation in the docs/html directory.

## Step 3: Parse HTML Documentation and Extract Information Using Python
Create a Python script (parse_doxygen_html.py) to parse the HTML and extract information. We'll use BeautifulSoup for parsing HTML and the CSV module to write to a CSV file.

- First, install BeautifulSoup:

```sh
pip install beautifulsoup4
Here's the Python script:
```

```python
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
Step 4: Run the Python Script
Execute the Python script to parse the HTML files and generate the CSV file:
```

```sh
python parse_doxygen_html.py
```

### Explanation of the Code

- main.c: This file contains simple C functions with Doxygen comments to demonstrate documentation generation.

- Doxyfile: The configuration file for Doxygen, which specifies the output directory and input files for generating documentation.

- parse_doxygen_html.py:

1. Import Modules: Import necessary modules (os, csv, BeautifulSoup).
2. Define Directory: Set the directory containing the generated HTML files.
3. Initialize List: Create a list to store extracted function information.
4. Parse HTML Files: Loop through each HTML file in the directory, parse it with BeautifulSoup, and extract function details.
5. Write to CSV: Write the extracted information to a CSV file with columns for function name, brief description, and parameters.

By following these steps, you can generate Doxygen documentation, parse it with Python, and save the information into a CSV file. This setup ensures a simple and clear process for extracting and recording documentation details.






