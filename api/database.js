const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
<<<<<<< HEAD
  user: 'netuser',
  password: 'netpass',
<<<<<<< HEAD
<<<<<<< HEAD
  database: 'banksimuldb',
  dateStrings:true
=======
=======
>>>>>>> 39c911a62a5d62efe35fea9fb6d8e35eca8f7838
=======
  user: 'banksimuldbuser',
  password: 'banksimuldbpass',
>>>>>>> f9d4b1b (Restapi)
  database: 'banksimuldb'
>>>>>>> a8ffb63 (Restapi)
});
module.exports = connection;