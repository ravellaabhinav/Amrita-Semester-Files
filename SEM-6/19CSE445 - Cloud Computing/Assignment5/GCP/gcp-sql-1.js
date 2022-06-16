var mysql = require('mysql');

var connection = mysql.createConnection({
    host     : "34.135.130.97",
    user     : "root",
    password : "12345678",
    port     : "3306"
  });

  connection.connect(function(err) {
    if (err) {
      console.error('Database connection failed: ' + err.stack);
      return;
    }
    console.log('Connected to SQL.');
});
connection.end();
