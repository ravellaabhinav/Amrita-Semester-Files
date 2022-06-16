var mysql = require('mysql');

var connection = mysql.createConnection({
  host     : "34.135.16.85",
  user     : "root",
  password : "12345678",
  port     : "3306"
});

connection.connect(function(err) {
  if (err) throw err;
  console.log("Connected to SQL");
});

connection.query("CREATE DATABASE simpleRGDB", function (err, result) {
    if (err) throw err;
    console.log("Database created");
  });

  connection.end();