var http = require("http");
var gow = require("url");

http
    .createServer(function (request, response) {
        response.writeHead(200, { "Content-Type": "text/html" });
        var q = gow.parse(request.url, true).query;
        console.log("true");
        let number = q.number;
        let name = q.name;
        let code = q.code;
        let comments = q.subject;
        var numbers = /^[0-9]*$/;
        var letters = /^[a-zA-Z]*$/;
        var email_val = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        var txt = "Welcome " + q.name;
        var dummy = "Errors: ";
        response.write('<h1 style="color:darkblue" align="center">Hi,' + txt+'</h1>');
        response.write('<h1 style="color:red"> \t' + dummy+'</h1>');


        if (!(number !== "" && number !== undefined && number.match(numbers))) {
            response.write(
                "<p>1. House No. must contain numbers only or should not be null</p>"
            );
        }
        if (!(name !== "" && name !== undefined && name.match(letters))
        ) {
            response.write("<p>2. Invalid Name Format or should not be null</p>");
        }
        if (!(code !== "" && code !== undefined && code.match(numbers))) {
            response.write(
                "<p>3. Invalid code or should not be null</p>"
            );
        }
        if (!(comments !== "" && comments !== undefined && comments.match(letters))) {
            response.write(
                "<p>4. Comment cannot be null</p>"
            );
        }
        response.end();
    })
    .listen(8081);
// Console will print the message
console.log('Server running at 8081');
