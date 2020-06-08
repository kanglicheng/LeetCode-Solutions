#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################
"""
This module contains script that add
url of leetcode problem
"""

# standard library
import os
import sys
import time

# 3rd party library
import requests

def problem_url_exist(problem, sleep_time=1.5):
    # problem format is "Two-Sum"
    prefix = "https://leetcode.com/problems/"
    url = prefix + problem.lower() + '/'
    time.sleep(sleep_time)
    return url_exist(url), url

def url_exist(url):
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36'}
    request = requests.get(url, headers=headers)
    return request.status_code == 200

if __name__ == "__main__":
    base_dir = '../Python3'
    cnt, nwrongs = 0, 0
    for fn in sorted(os.listdir(base_dir), reverse=True): # folder name
        if os.path.isdir(os.path.join(base_dir, fn)):
            num, rest = fn.split('-', 1)
            cnt += 1
            time.sleep(0.5)
            exists, url = problem_url_exist(rest)
            if exists:
                nwrongs += 1
                print("{}:{}".format(num, rest))
    print("There are {} wrong folder names".format(nwrongs))
