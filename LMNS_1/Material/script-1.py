from lxml import html
import requests
import json

def get_info(URL):
    ''' Data scraping function '''

    page = requests.get(URL)
    tree = html.fromstring(page.content)   
    content = tree.xpath('//*[@id="CurrentVariantJson-1805453197401"]/text()')
    
    convertet = ''.join(content) #convert from 'list' to 'string' class
    d = json.loads(convertet) #'converts' the 'sting' into json formatted dict

    for key, value in d.items():
        if key == "available":
            print(value)
            if value == True:
                print("Buy now!")
            else:
                print("Nothing to see here...")
           

get_info("https://www.keychron.com/products/keychron-k1-wireless-mechanical-keyboard?variant=31562978525273")