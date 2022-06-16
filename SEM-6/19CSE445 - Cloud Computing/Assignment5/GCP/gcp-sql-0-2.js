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
    console.log("Connected to RDS");
});


var sql = "CREATE TABLE customers (name VARCHAR(25), address VARCHAR(25))";
connection.query(sql, function (err, result) {
    if (err) throw err;
    console.log("Table created");
});

connection.end();