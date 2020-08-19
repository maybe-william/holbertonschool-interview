#!/usr/bin/node

const request = require('request');
const { promisify } = require('util');

async function getUser (url) {
  const req = promisify(request);
  return req(url);
}
function printUsersFilms (number) {
  request('https://swapi-api.hbtn.io/api/films/' + number, function (err, res, body) {
    if (err) {
      console.log(err);
    }
    if (body) {
      const chars = JSON.parse(body).characters;
      const arr = chars.map(getUser);
      Promise.all(arr).then(function (arr) {
        for (const x of arr) {
          console.log(JSON.parse(x.body).name);
        }
      });
    }
  });
}
printUsersFilms(process.argv[2]);
