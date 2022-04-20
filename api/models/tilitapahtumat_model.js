const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where tilitapahtumat.idtili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (Kortinnumero,Paivays,Tapahtuma,Summa,idkortti,idtili) values(?,?,?,?,?,?)',
      [tilitapahtumat.Kortinnumero, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idkortti, 
        tilitapahtumat.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set Kortinnumero=?,Paivays=?,Tapahtuma=?,Summa=?,idkortti=?,idtili=? where idtilitapahtumat=?',
      [tilitapahtumat.Kortinnumero, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idkortti, 
        tilitapahtumat.idtili, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;