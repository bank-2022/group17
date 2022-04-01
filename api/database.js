const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
<<<<<<< HEAD
  user: 'netuser',
  password: 'netpass',
<<<<<<< HEAD
  database: 'banksimuldb',
  dateStrings:true
=======
=======
  user: 'banksimuldbuser',
  password: 'banksimuldbpass',
>>>>>>> f9d4b1b (Restapi)
  database: 'banksimuldb'
>>>>>>> a8ffb63 (Restapi)
});
module.exports = connection;