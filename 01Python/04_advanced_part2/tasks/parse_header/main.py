import re
import openpyxl

def extract_prototypes(header_file):
    # Regular expression to match function prototypes
    prototype_pattern = re.compile(r'\b\w+\s+\w+\(.*?\);')
    prototypes = []

    with open(header_file, 'r') as file:
        for line in file:
            match = prototype_pattern.search(line)
            if match:
                prototypes.append(match.group())

    return prototypes

def write_to_excel(prototypes, excel_file):
    workbook = openpyxl.Workbook()
    sheet = workbook.active
    sheet.title = "Prototypes"

    # Write the header row
    sheet.append(["Function Prototype", "Unique ID"])

    # Write the prototypes and IDs
    for idx, prototype in enumerate(prototypes, start=1):
        unique_id = f"IDX{idx:03}"
        sheet.append([prototype, unique_id])

    # Save the workbook
    workbook.save(excel_file)
    print(f"Data written to {excel_file}")

if __name__ == "__main__":
    header_file = input("Enter the path to the header file: ")
    excel_file = "function_prototypes.xlsx"

    prototypes = extract_prototypes(header_file)
    write_to_excel(prototypes, excel_file)
