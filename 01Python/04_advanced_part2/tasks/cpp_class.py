def create_class_files(class_name):
    # Define the content for the .h file
    header_content = f"""\
#ifndef {class_name.upper()}_H
#define {class_name.upper()}_H

class {class_name} {{
public:
    {class_name}();  // Constructor
    ~{class_name}(); // Destructor
}};

#endif // {class_name.upper()}_H
"""

    # Define the content for the .cpp file
    cpp_content = f"""\
#include "{class_name}.h"
#include <iostream>

// Constructor
{class_name}::{class_name}() {{
    std::cout << "{class_name} constructed!" << std::endl;
}}

// Destructor
{class_name}::~{class_name}() {{
    std::cout << "{class_name} destructed!" << std::endl;
}}
"""

    # Write the content to the .h file
    with open(f"{class_name}.h", 'w') as header_file:
        header_file.write(header_content)

    # Write the content to the .cpp file
    with open(f"{class_name}.cpp", 'w') as cpp_file:
        cpp_file.write(cpp_content)

if __name__ == "__main__":
    class_name = input("Enter the name of the class: ")
    create_class_files(class_name)
    print(f"Files {class_name}.h and {class_name}.cpp have been created.")
