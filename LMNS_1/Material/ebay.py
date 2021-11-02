from lxml import html
import requests

def get_price(URL):
    ''' Data scraping function '''

    page = requests.get(URL)
    tree = html.fromstring(page.content)
    price_tag = tree.xpath('//*[@id="prcIsum"]/text()')
    
    convertet_price_tag = ''.join(price_tag) #convert from 'list' to 'string' class
    
    print("The price of my article is:", convertet_price_tag)
    print(f"The price of my article is: {convertet_price_tag}") # <- With f-strings you can evaluate an expression as part of the string along with inserting result of function calls and so on...

get_price("https://www.ebay.com/itm/194202087189?_trkparms=pageci%3Abc43f0bb-f24b-11eb-a57a-028f3c999e6e%7Cparentrq%3Afe9bdf1117a0a9f10c5ef6beffeb0180%7Ciid%3A1")