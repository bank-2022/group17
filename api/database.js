const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
<<<<<<< HEAD
  user: 'netuser',
  password: 'netpass',
=======
  user: 'banksimuldbuser',
  password: 'banksimuldbpass',
>>>>>>> f9d4b1b (Restapi)
  database: 'banksimuldb'
});
module.exports = connection;