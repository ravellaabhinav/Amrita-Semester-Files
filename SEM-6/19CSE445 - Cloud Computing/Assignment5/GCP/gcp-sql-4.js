var express = require('express');
var mysql = require('mysql');

var app = express();
app.use(express.urlencoded());

var connection = mysql.createConnection({
  host     : "34.135.16.85",
  user     : "root",
  password : "12345678",
  port     : "3306",
  database: "simpleRGDB"
});

connection.connect(function (err) {
  if (err) {
    console.error('Database connection failed: ' + err.stack);
    return;
  }
  console.log('Connected to RDS.');
});

var test = 0;

app.post('/abc', function (req, res) {

  var username = req.body.firstname
  var password = req.body.lastname

  connection.query('SELECT * from customers', function (error, results, fields) {
    if (error) throw error;

    var length = results.length

    for (i = 0; i < length; i++)
      if (results[i].name === username && results[i].address === password)
        test = 1

    if (test === 1)
      res.send("Congradulations Login Success");
    else
      res.send("Login Failure try again!!");

  });
  connection.end();
});

app.listen(8081);
console.log("server listening in http://localhost:8081/abc")
