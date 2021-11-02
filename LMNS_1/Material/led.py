import requests
from lxml import html
import json

import time
import sys

import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

# LED Pin 4
LED = 4
# Declare the LED as an GPIO putput -> 
GPIO.setup(LED, GPIO.OUT)

# setup PWM
pwm = GPIO.PWM(LED, 50);
pwm.start(0)

def get_info(URL):
    ''' Data scraping function // LED starts flashing, if article is available  '''

    while True: # This part of the code runs as long as it is alive ...
        time.sleep(2) # request every 2 seconds
        print("Sleep for 2 seconds")

        page = requests.get(URL) # new request, fetch new data
        print("fetch ne data")
        tree = html.fromstring(page.content)

        content = tree.xpath('//*[@id="CurrentVariantJson-1805453197401"]/text()')
        convertet = ''.join(content) # convert from 'list' to 'string' class
        d = json.loads(convertet) #'converts' the 'sting' into json formatted dict

        for key, value in d.items():
            if key == "available":
                pwm.start(0)

                if value == True:
                    print("Buy now!")
                    for c in range(0, 101, 2):
                        pwm.ChangeDutyCycle(c)
                        time.sleep(0.1)

                    time.sleep(5)

                    for c in range(100, -1, -2):
                        pwm.ChangeDutyCycle(c)
                        time.sleep(0.1)
                else:
                    print("Nothing to see here ...")


if __name__ == '__main__':
    try:
        print("init function call")
        get_info("https://www.keychron.com/products/keychron-k1-wireless-mechanical-keyboard?variant=31562978525273")
    except KeyboardInterrupt:
        print(sys.stderr, '\nExiting by user request.\n')
        pwm.stop()
        GPIO.cleanup()
        sys.exit(0)
