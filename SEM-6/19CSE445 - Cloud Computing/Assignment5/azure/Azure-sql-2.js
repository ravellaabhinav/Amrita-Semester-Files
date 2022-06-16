
var mysql = require('mysql');
const fs = require('fs');

var connection = mysql.createConnection({
  host     : "mytestserver1981.mysql.database.azure.com",
  user     : "test@mytestserver1981",
  password : "12345678q!",
  port     : "3306",
  database: 'SampleDB',
  ssl: {ca: fs.readFileSync("Root.crt.pem")}
});

connection.connect(function (err) {
  if (err) {
    console.error('Database connection failed: ' + err.stack);
    return;
  }
  console.log('Connected to RDS.');
});

connection.query('use SampleDB', function (error, results, fields) {
  if (error) throw error;
  console.log("Connected to database... SampleDB");
});

connection.query('SELECT * from login', function (error, results, fields) {
  if (error) throw error;
  console.log("The Select results are");
  console.log(results);


});
connection.end();
