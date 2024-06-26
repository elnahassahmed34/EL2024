import pyautogui
import time
import os

mypath = "/home/nahass/workspace_py/vscode.png"

try:
    isfind = None
    while isfind is None:
        isfind = pyautogui.locateOnScreen(mypath , confidence=0.7 , step=10)
        time.sleep(4)
        pyautogui.hotkey('enter')
except pyautogui.ImageNotFoundException:
    print("no image")
