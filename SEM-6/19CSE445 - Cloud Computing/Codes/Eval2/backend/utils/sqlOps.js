const mysql = require("mysql");

let connection;

const connectSQL = () => {
    connection = mysql.createConnection({
        host: "XX.XXX.XXX.XXX", //insert your SQL IP address
        user: "root",
        password: "demo1234",
        port: "3306",
        database: "XXXXXX", //insert your SQL Database name
    });

    connection.connect((err) => {
        if (err) {
            console.error(err);
            return;
        }
        console.log("Connected to GCP MySQL...");
    });
};

const insertData = (dataObj) => {
    connectSQL();
    const sqlQuery = `INSERT INTO HOUSEINFO VALUES (${dataObj.houseNo}, '${dataObj.houseName}',${dataObj.zipcode},'${dataObj.city}','${dataObj.housePhotoFileName}')`;
    connection.query(sqlQuery, (err, result) => {
        if (err) {
            console.error(err);
            return;
        }
        console.log("Inserted Successfully...");
    });
    connection.end();
    console.log("Disconnected from SQL...");
};

fnObj = { insertData: insertData, connectSQL: connectSQL };

module.exports = fnObj;
