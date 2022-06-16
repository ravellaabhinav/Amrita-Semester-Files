
var mysql = require('mysql');

var connection = mysql.createConnection({
  host     : "34.122.210.150",
  user     : "root",
  password : "12345678",
  port     : "3306"
});

connection.connect(function (err) {
  if (err) {
    console.error('Database connection failed: ' + err.stack);
    return;
  }
  console.log('Connected to SQL.');
});

connection.query('use simpleRGDB', function (error, results, fields) {
  if (error) throw error;
  console.log("Connected to database... SampleDB");
});

connection.query('SELECT * from login', function (error, results, fields) {
  if (error) throw error;
  console.log("The field results are");
  console.log(typeof(fields) +" "+ fields[0].name+" "+fields[1].name);
});
connection.end();
