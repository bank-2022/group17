const db = require('../database');

const asiakastili = {
  getById: function([idAsiakas, idtili], callback) {
    return db.query('select * from asiakastili where idAsiakas=? and idtili=?', [idAsiakas, idtili], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakastili', callback);
  },
  add: function(asiakastili, callback) {
    return db.query(
      'insert into asiakastili (idAsiakas,idtili) values(?,?)',
      [asiakastili.idAsiakas, asiakastili.idtili],
      callback
    );
  },
  delete: function([idAsiakas, idtili], callback) {
    return db.query('delete from asiakastili where idAsiakas=? and idtili=?', [idAsiakas, idtili], callback);
  },
  update: function([idAsiakas, idtili], asiakastili, callback) {
    return db.query(
      'update asiakastili set idAsiakas=?,idtili=? where idasiakas=? and idtili=?',
      [asiakastili.idAsiakas, asiakastili.idtili, idAsiakas, idtili],
      callback
    );
  }
};
module.exports = asiakastili;