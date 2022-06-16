
var mysql = require('mysql');

var connection = mysql.createConnection({
  host     : "34.135.130.97",
  user     : "root",
  password : "12345678",
  port     : "3306",
  database: "SampleDB"
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
