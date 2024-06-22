import os
import pyautogui
import time

def open_vscode():
    """
    Opens Visual Studio Code on Ubuntu.
    """
    os.system("code")  # Command to open VSCode in Ubuntu
    time.sleep(5)  # Wait for VSCode to open

def search_and_install_extension(extension_name):
    """
    Searches for and installs a VSCode extension.
    """
    # Open the Extensions view
    pyautogui.hotkey('ctrl', 'shift', 'x')
    time.sleep(2)
    
    # Click on the search box
    pyautogui.click(300, 150)  # Adjust these coordinates if necessary
    time.sleep(1)
    
    # Type the extension name and press Enter
    pyautogui.typewrite(extension_name, interval=0.1)
    pyautogui.press('enter')
    time.sleep(3)  # Wait for search results to load
    
    # Click the install button for the first result
    pyautogui.click(300, 300)  # Adjust these coordinates if necessary
    time.sleep(5)  # Wait for installation to complete

def main():
    open_vscode()
    
    extensions = [
        "clangd",
        "C++ TestMate",
        "C++ Helper",
        "CMake",
        "CMake Tools"
    ]
    
    for extension in extensions:
        search_and_install_extension(extension)

if __name__ == "__main__":
    main()
