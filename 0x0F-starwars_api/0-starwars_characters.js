#!/usr/bin/node

const request = require('request');
request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (err, res, body) {
  if (err) throw err;
  const ch = JSON.parse(body).characters;
  sameOrder(ch, 0);
});
const sameOrder = (ch, x) => {
  if (x === ch.length) return;
  request(ch[x], function (err, res, body) {
    if (err) throw err;
    console.log(JSON.parse(body).name);
    sameOrder(ch, x + 1);
  });
};
