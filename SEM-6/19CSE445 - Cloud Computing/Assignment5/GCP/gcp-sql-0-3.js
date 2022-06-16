var mysql = require('mysql');

var connection = mysql.createConnection({
  host     : "34.135.16.85",
  user     : "root",
  password : "12345678",
  port     : "3306",
  database: "simpleRGDB"
});

connection.connect(function (err) {
    if (err) throw err;
    console.log("Connected RDS");
});


var sql = "INSERT INTO customers (name, address) VALUES ('gowtham', 'ramesh')";
connection.query(sql, function (err, result) {
  if (err) throw err;
  console.log(result);
});

connection.end();