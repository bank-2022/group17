const db = require('../database');

const login={
  checkPin: function(idtili, callback) {
      return db.query('SELECT Pin FROM kortti WHERE idtili = ?',[idtili], callback); 
    }
};
          
module.exports = login;