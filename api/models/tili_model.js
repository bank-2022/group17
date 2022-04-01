const db = require('../database');

const tili = {
  getById: function(idtili, callback) {
    return db.query('select * from tili where idtili=?', [idtili], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (idtili,Saldo,Tilinumero) values(?,?,?)',
      [tili.idtili, tili.Saldo, tili.Tilinumero],
      callback
    );
  },
  delete: function(idtili, callback) {
    return db.query('delete from tili where idtili=?', [idtili], callback);
  },
  update: function(idtili, tili, callback) {
    return db.query(
      'update tili set Saldo=?,Tilinumero=? where idtili=?',
      [tili.Saldo, tili.Tilinumero, idtili],
      callback
    );
  }
};
module.exports = tili;