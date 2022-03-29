const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'ROOT',
  database: 'banksimuldb'
});
module.exports = connection;