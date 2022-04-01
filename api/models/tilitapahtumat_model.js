const db = require('../database');

const tilitapahtumat = {
  getById: function(idtilitapahtumat, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [idtilitapahtumat], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (idtilitapahtumat,Kortinnumero,Paivays, Tapahtuma, Summa, idkortti, idtili) values(?,?,?,?,?,?,?)',
      [tilitapahtumat.idtilitapahtumat, tilitapahtumat.Kortinnumero, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idkortti, tilitapahtumat.idtili],
      callback
    );
  },
  delete: function(idtilitapahtumat, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [idtilitapahtumat], callback);
  },
  update: function(idtilitapahtumat, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set Kortinnumero=?, Paivays=?,Tapahtuma=?,Summa=?,idkortti=?,idtili=? where idtilitapahtumat=?',
      [tilitapahtumat.Kortinnumero, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idkortti, tilitapahtumat.idtili, idtilitapahtumat],
      callback
    );
  }
};
module.exports = tilitapahtumat;