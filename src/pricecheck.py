import requests
from bs4 import BeautifulSoup

url = "https://www.thuisbezorgd.nl/"
response = requests.get(url)

# Parse the HTML content using BeautifulSoup
soup = BeautifulSoup(response.content, "html.parser")

# Print the parsed HTML content in a more readable format
print(soup.prettify())