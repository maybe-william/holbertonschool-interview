#!/usr/bin/python3
"""Return the count of keywords in hot post titles on reddit"""


import re
import requests


def count_words(subreddit, word_list):
    """Count all the keywords from the titles of a given subreddit"""
    word_list = list(map(lambda x: x.lower(), word_list))
    matches = {}
    query_api(subreddit, matches, word_list)
    items = sorted(matches.items(), key=lambda x: x[0])
    items = sorted(matches.items(), key=lambda x: x[1])
    list(map(lambda x: print(str(x[0]) + ': ' + str(x[1])), reversed(items)))


def assign_map_val(to_assign, key, val):
    """utility method to be used below"""
    to_assign[key] = val


def add_matches(title, matches, word_list):
    """Add the matches from word_list from a single title"""
    title = ' ' + title.lower() + ' '
    x = '(?<=\\s)'
    y = '(?=\\s)'
    find_words = (lambda word: re.findall(re.compile(x + word + y), title))
    words = list(map(find_words, word_list))
    at_least_one = list(filter(lambda z: len(z) > 0, words))
    pairs = list(map(lambda a: (a[0], len(a)), at_least_one))
    ad = (lambda b: assign_map_val(matches, b[0], matches.get(b[0], 0) + b[1]))
    list(map(ad, pairs))


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

    temp = list(map(lambda x: x.get("data", {}).get("title", ""), posts))
    list(map(lambda y: add_matches(y, matches, word_list), temp))

    next_page = data.get("after", None)
    if next_page is None:
        return

    query_api(subreddit, matches, word_list, next_page)
