
var mysql = require('mysql');
const fs = require('fs');

var connection = mysql.createConnection({
  host     : "myfirstservergow.mysql.database.azure.com",
  user     : "test@myfirstservergow",
  password : "12345678q!",
  port     : "3306",
  database: 'mysampleDB',
  ssl: {ca: fs.readFileSync("Root.crt.pem")}
});

  connection.connect(function(err) {
    if (err) {
      console.error('Database connection failed: ' + err.stack);
      return;
    }
    console.log('Connected to RDS.');
});



connection.query('SELECT * from login', function (error, results, fields) {
  if (error) throw error;
  var length=results.length

  for(i=0;i<length;i++)
  console.log('\nThe solution is: ', results[i].username , results[i].password);

 
});
connection.end();
