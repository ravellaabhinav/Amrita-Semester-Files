var mysql = require('mysql');
var zipcodes = require('zipcodes');
//var express = require('express');
//const {Storage} = require('@google-cloud/storage');
var http = require('http');
var url = require('url');
//var multer = require('multer');

//var app = express();



//const upload = multer({ dest: "uploadsHolding/" });

var connection = mysql.createConnection({
    host:"34.68.15.182",
    user:"root",
    password:"sampleinstance",
    port:"3306",
    database:"SampleDB"

});

connection.connect(function (err) {
    if (err) {
      console.error('Database connection failed: ' + err.stack);
      return;
    }
    console.log('Connected to RDS.');
  });

/*
  var port = 9001;




  app.post('/submit', (req, res) => {
    
    var hno = req.body.hno;
    var hname = req.body.hname;
    var zip = req.body.zip;
    var file = req.file;

    if(hno.length == 0 || hname.length == 0 || zip.length == 0 || file.length == 0){
        res.status(503).send("<html><body><h1 style='color:red;'>Please Provide valid Credentials</h1></body></html>");
       
    }

    else
    {

        var cit = zipcodes.lookup(zip);
        var city = cit.city;
        var sql = "Insert into house values('"+hno+"' , '"+hname+"' , '"+zip+"' , '"+city+"')";
        

        connection.query(sql,function(err){
            if(err){
                console.error("Query Error");
                res.status(503).send("<html><body><h1 style='color:red;'>Query Error/h1></body></html>");
                throw err;
                return;
            }
            else
            {
                
                const storage = new Storage({keyFilename: 'tribal-sign-339607-234391fca0fe.json'});
                const destFileName = file;

                async function copyFile() {
                    // Copies the file to the other bucket
                    
                  
                    await storage.bucket(destBucketName).upload(destFileName);
                
                    console.log(
                      `${destFileName} copied to gs://${destBucketName}/${destFileName}`
                    );
                  }

                res.status(200).send("<html><body><h1 style='color:green;'>DB Updated Successfully/h1></body></html>");
                copyFile().catch(console.error);
                

            }

        }
        )}


  

  });

  app.listen(port, () => console.log(`Listening on port ${port}...`));

  */


http.createServer(function(req,res)
{
    res.writeHead(200,{'Content-type':'text/html'});
    var q = url.parse(req.url,true).query;
    var hno = q.hno;
    var hname = q.hname;
    var zip = q.zip;
    var file = q.file;


    if(hno.length == 0 || hname.length == 0 || zip.length == 0 || file.length == 0){
        res.write("<html><body><h1 style='color:red;'>Please Provide valid Credentials</h1></body></html>");
       
    }

    else
      {

          var cit = zipcodes.lookup(zip);
          var city = cit.city;
          var sql = "Insert into users values('"+hno+"' , '"+hname+"' , '"+zip+"' , '"+city+"')";
          

          connection.query(sql,function(err){
              if(err){
                  console.error("Query Error");
                  res.write("<html><body><h1 style='color:red;'>Query Error/h1></body></html>");
                  throw err;
                  return;
              }
              else
              {
                
                /*
                  const storage = new Storage({keyFilename: 'tribal-sign-339607-234391fca0fe.json'});
                  const destFileName = file;
                  destBucketName = eval3buc123;

                  async function copyFile() {
                      // Copies the file to the other bucket
                      
                    
                      await storage.bucket(destBucketName).upload(destFileName);
                  
                      console.log(
                        `${destFileName} copied to gs://${destBucketName}/${destFileName}`
                      );
                    } 
                    */

                  res.write("<html><body><h1 style='color:green;'>DB Updated Successfully/h1></body></html>");
                 // copyFile().catch(console.error);
                  

              }

          }
          )}




}).listen(9001);

console.log("Server Running at 9001");

