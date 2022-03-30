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
      'insert into asiakastili (idasiakas,idtili) values(?,?)',
      [asiakastili.idasiakas, asiakastili.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakastili where idasiakas=?', [id], callback);
  },
  update: function(id, asiakastili, callback) {
    return db.query(
      'update asiakastili set idasiakas=?,idtili=?, where idasiakastili=?',
      [asiakastili.idasiakas, asiakastili.idtili, id],
      callback
    );
  }
};
module.exports = asiakastili;