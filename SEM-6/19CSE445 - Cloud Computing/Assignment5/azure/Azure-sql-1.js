var mysql = require('mysql');
const fs = require('fs');

//https://www.digicert.com/CACerts/BaltimoreCyberTrustRoot.crt.pem

var connection = mysql.createConnection({
    host     : "mytestserver1981.mysql.database.azure.com",
    user     : "test@mytestserver1981",
    password : "12345678q!",
    port     : "3306",
    database: 'SampleDB',
    ssl: {ca: fs.readFileSync("Root.crt.pem")}
  });

  connection.connect(function(err) {
    if (err) {
      console.error('Database connection failed: ' + err.stack);
      return;
    }
    console.log('Connected to SQL.');
});
connection.end();
