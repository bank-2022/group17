const db = require('../database');

const login={
<<<<<<< HEAD
  checkPin: function(Korttinumero, callback) {
      return db.query('SELECT pin FROM kortti WHERE Korttinumero = ?',[Korttinumero], callback); 
=======
  checkPin: function(idKortti, callback) {
      return db.query('SELECT Pin FROM kortti WHERE idkortti = ?',[idKortti], callback); 
>>>>>>> f9d4b1b (Restapi)
    }
};
          
module.exports = login;