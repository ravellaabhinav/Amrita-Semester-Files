var http = require("http");
var url = require("url");


http.createServer(function (request, response) {
   response.writeHead(200, {'Content-Type': 'text/plain'});
   response.write('Hello Gowtham'+ request.url );
   var q = url.parse(request.url, true).query;
   var txt = q.username + "\t " + q.password;
   response.write('\nText Query \t' + txt);
   response.end();
}).listen(8899);
console.log("Server running at :8833");