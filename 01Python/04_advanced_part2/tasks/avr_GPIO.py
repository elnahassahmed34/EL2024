def get_bit_mode(bit_number):
    while True:
        mode = input(f"Enter the mode for bit {bit_number} (in or out): ").strip().lower()
        if mode in ['in', 'out']:
            return mode
        else:
            print("Invalid input. Please enter 'in' or 'out'.")

def generate_gpio_init():
    # Get the mode for each bit
    bit_modes = [get_bit_mode(bit) for bit in range(8)]
    
    # Create the DDRx register value
    ddrx_value = 0
    for bit, mode in enumerate(bit_modes):
        if mode == 'out':
            ddrx_value |= (1 << bit)
    
    # Generate the Init function
    init_function = f"""\
void GPIO_Init() {{
    // Set DDRx register
    DDRx = 0x{ddrx_value:02X};  // 0b{ddrx_value:08b}
}}
"""

    return init_function

if __name__ == "__main__":
    init_code = generate_gpio_init()
    print("Generated GPIO Initialization Function:\n")
    print(init_code)
