# Simple script to fetch current day's input file from advent of code
# Please set AOC_SESSION environment variable as your cookies session 

import requests
import datetime
import os

def get_input(day: int) -> str:
    cookies = {
        'session': os.environ['AOC_SESSION'],
    }

    headers = {
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:78.0) Gecko/20100101 Firefox/78.0',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
        'Accept-Language': 'en-US,en;q=0.5',
        'Connection': 'keep-alive',
        'Upgrade-Insecure-Requests': '1',
        'Cache-Control': 'max-age=0',
        'TE': 'Trailers',
    }

    response = requests.get(f'https://adventofcode.com/2021/day/{day}/input', headers=headers, cookies=cookies)
    return response.text

if __name__ == '__main__':
    day = datetime.date.today().day
    res = get_input(day)
    if res.startswith('Please don\'t re'):
        print('Not open yet...')
        exit(1)
    try:
        os.mkdir(f'{day}')
    except FileExistsError:
        print(f'./{day} directory exists!')
        exit(1)
    
    with open(f'{day}/{day}.in', 'w') as fobj:
        fobj.write(res)
    
    with open('template/template.cpp') as fobj:
        cpp_template = fobj.read()
    
    cpp_code = cpp_template.replace('$$$.in', f'{day}.in')

    for i in [1, 2]:
        with open(f'{day}/{day}-{i}.cpp', 'w') as fobj:
            fobj.write(cpp_code)
