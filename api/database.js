const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'kayttaja',
  password: 'salasana',
  database: 'banksimuldb'
});
module.exports = connection;