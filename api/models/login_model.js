const db = require('../database');

const login={
  checkPassword: function(idtili, callback) {
      return db.query('SELECT Pin FROM banksimuldb WHERE idtili = ?',[idtili], callback); 
    }
};
          
module.exports = login;