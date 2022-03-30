const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (kortinnumero,paivays,tapahtuma,summa,idkortti,idtili) values(?,?,?,?,?,?)',
      [tilitapahtumat.kortinnumero, tilitapahtumat.paivays, tilitapahtumat.tapahtuma,tilitapahtumat.summa,tilitapahtumat.idkortti,tilitapahtumat.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set kortinnumero=?,paivays=?, tapahtuma=?, summa=?, idkortti=?, idtili=? where idtilitapahtumat=?',
      [tilitapahtumat.kortinnumero, tilitapahtumat.paivays, tilitapahtumat.tapahtuma, tilitapahtumat.summa,tilitapahtumat.idkortti,tilitapahtumat.idtili, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;
