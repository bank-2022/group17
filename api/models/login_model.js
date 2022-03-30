const db = require('../database');

const login={
  checkPassword: function(id, callback) {
      return db.query('SELECT pin FROM kortti WHERE idKortti = ?',[id], callback); 
    }
};
          
module.exports = login;