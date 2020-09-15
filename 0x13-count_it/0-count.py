#!/usr/bin/python3
"""Return the count of keywords in hot post titles on reddit"""


import requests
import re


def count_words(subreddit, word_list):
    """Count all the keywords from the titles of a given subreddit"""
    word_list = [x.lower() for x in word_list]
    matches = {}
    query_api(subreddit, matches, word_list)
    items = sorted(matches.items(), key=lambda x: x[1])
    [print('{}: {}'.format(x[0], x[1])) for x in reversed(items)]


def assign_map_val(to_assign, key, val):
    """utility method for use below"""
    to_assign[key] = val


def add_matches(title, matches, word_list):
    """Add the matches from word_list from a single title"""
    title = ' ' + title.lower() + ' '
    x = '(?<=\\s)'
    y = '(?=\\s)'
    words = [re.findall(re.compile(x + word + y), title) for word in word_list]
    pairs = [(z[0], len(z)) for z in words if len(z) > 0]
    [assign_map_val(matches, a[0], matches.get(a[0], 0) + a[1]) for a in pairs]


def query_api(subreddit, matches, word_list, after=None):
    """Query the api recursively"""
    params = None if after is None else {"after": after}
    head = {'User-agent': 'Mozilla/5.0'}

    url = "https://reddit.com/r/" + subreddit + "/hot.json"
    resp = requests.get(url, headers=head, params=params)
    data = resp.json().get("data", {})
    if data == {}:
        return

    posts = data.get("children", [])
    if posts == []:
        return

    temp = [x.get("data", {}).get("title", "") for x in posts]
    [add_matches(y, matches, word_list) for y in temp]

    next_page = data.get("after", None)
    if next_page is None:
        return

    query_api(subreddit, matches, word_list, next_page)
