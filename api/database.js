const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'netuser',
  password: 'netpass',
  database: 'banksimuldb',
<<<<<<< HEAD
  dateStrings:true
=======
  dateStrings: true
>>>>>>> 7ccefe4 (js lisätty dateStrings)
});
module.exports = connection;