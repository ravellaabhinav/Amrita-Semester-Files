var http = require("http");
var gow = require("url");

http
    .createServer(function (request, response) {
        response.writeHead(200, { "Content-Type": "text/html" });
        var q = gow.parse(request.url, true).query;
        console.log("true");
        let id = q.name;
        let empName = q.dept;
        let title = q.title;
        let author = q.author;
        let journal = q.journal;
        let link = q.link;
        let dead = q.deadline;
        let percent = q.percent;
        let num = q.number;
        var numbers = /^[0-9]*$/;
        var letters = /^[a-zA-Z]*$/;
        var date_regex = /^(0[1-9]|1[0-2])\/(0[1-9]|1\d|2\d|3[01])\/(19|20)\d{2}$/;
        var email_val = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        var txt = "Welcome " + q.name;
        var dummy = "Errors: ";
        response.write('<h1 style="color:darkblue" align="center">Hi,' + txt+'</h1>');
        response.write('<h1 style="color:red"> \t' + dummy+'</h1>');

        function validatedate(inputText,DateFormat)
        {
            // format dd/mm/yyyy or in any order of (dd or mm or yyyy) you can write dd or mm or yyyy in first or second or third position ... or can be slash"/" or dot"." or dash"-" in the dates formats
            var invalid = "";
            var dt = "";
            var mn = "";
            var yr = "";
            var k;
            var delm = DateFormat.includes("/") ? "/" : ( DateFormat.includes("-") ? "-" : ( DateFormat.includes(".") ? "." : "" ) ) ;
            var f1 = inputText.split(delm);
            var f2 = DateFormat.split(delm);
            for(k=0;k<=2;k++)
            {
                dt = dt + (f2[parseInt(k)]=="dd" ? f1[parseInt(k)] : "");
                mn = mn + (f2[parseInt(k)]=="mm" ? f1[parseInt(k)] : "");
                yr = yr + (f2[parseInt(k)]=="yyyy" ? f1[parseInt(k)] : "");
            }
            var mn_days = "0-31-" + (yr % 4 == 0 ? 29 : 28) + "-31-30-31-30-31-31-30-31-30-31";
            var days = mn_days.split("-");
            if( f1.length!=3 || mn.length>2 || dt.length>2 || yr.length!=4 || !(parseInt(mn)>=1 && parseInt(mn)<=12) || !(parseInt(yr)>=parseInt(1900) && parseInt(yr)<=parseInt(2100)) || !(parseInt(dt)>=1 && parseInt(dt)<=parseInt(days[parseInt(mn)])) )
            {
                invalid = "true";
            }
            alert( ( invalid=="true" ? "Invalid Date" : "Valid Date")  );
        }

        if (!(id !== "" && id !== undefined && id.match(letters))) {
            response.write(
                "<p>1. School is incorrect and should not be null</p>"
            );
        }
        if (
            !(empName !== "" && empName !== undefined && empName.match(letters))
        ) {
            response.write("<p>2. Department name is incorrect must contain characters only</p>");
        }
        if (!(title !== "" && title !== undefined && title.match(letters))) {
            response.write(
                "<p>3. Paper Title should not be null</p>"
            );
        }
        if (!(author !== "" && author !== undefined && author.match(letters))) {
            response.write(
                "<p>4. Author name should not be null</p>"
            );
        }
        if (!(journal !== "" && journal !== undefined && journal.match(letters))) {
            response.write(
                "<p>5. Journal Name is incorrect and not null</p>"
            );
        }
        if (!(date_regex.test(dead))) {

            response.write(
                "<p>7. Invalid Date must be in DD/MM/YYYY</p>"
            );
        }

        if (!(percent !== "" && percent !== undefined && percent.match(numbers))) {
            response.write(
                "<p>8. Percentage must contain numbers only and not null</p>"
            );
        }

        if (!(num !== "" && num !== undefined && num.match(numbers))) {
            response.write(
                "<p>9. Citations count contain numbers only and not null</p>"
            );
        }

        response.end();
    })
    .listen(8081);
// Console will print the message
console.log('Server running at 8081');
