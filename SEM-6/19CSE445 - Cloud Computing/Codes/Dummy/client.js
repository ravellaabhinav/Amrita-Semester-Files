var http = require("http");
var path = require("path");
var fs = require('fs');

http.createServer(function (req, res) {
    fs.readFile(__dirname + '/index.html', function (err,data) {
        if (err) {
            res.writeHead(404);
            res.end(JSON.stringify(err));
            return;
        }
        res.writeHead(200);
        res.end(data);
    });
}).listen(8080);

// Console will print the message
console.log('Server running at 8080');
