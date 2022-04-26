const db = require('../database');

const login={
  checkPin: function(Korttinumero, callback) {
      return db.query('SELECT pin FROM kortti WHERE Korttinumero = ?',[Korttinumero], callback); 
    }
};
          
module.exports = login;