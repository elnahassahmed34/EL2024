import webbrowser

# List of favorite websites
favorite_websites = {
    'Google': 'https://www.google.com',
    'YouTube': 'https://www.youtube.com',
    'GitHub': 'https://www.github.com',
    'Stack Overflow': 'https://stackoverflow.com'
}

def firefox(url):
    """
    Opens the given URL in the default web browser.
    """
    webbrowser.open(url)
