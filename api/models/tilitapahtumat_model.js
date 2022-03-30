const db = require('../database');

const tapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tapahtumat where idtapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tapahtumat', callback);
  },
  add: function(tapahtumat, callback) {
    return db.query(
      'insert into tapahtumat (kortinnumero,paivays,tapahtuma,summa,idkortti,idtili) values(?,?,?,?,?,?)',
      [tapahtumat.kortinnumero, tapahtumat.paivays, tapahtumat.tapahtuma,tapahtumat.summa,tapahtumat.idkortti,tapahtumat.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tapahtumat where idtapahtumat=?', [id], callback);
  },
  update: function(id, tapahtumat, callback) {
    return db.query(
      'update tapahtumat set kortinnumero=?,paivays=?, tapahtuma=?, summa=?, idkortti=?, idtili=?, where idtapahtumat=?',
      [tapahtumat.kortinnumero, tapahtumat.paivays, tapahtumat.tapahtuma, tapahtumat.summa,tapahtumat,idkortti,tapahtumat.idtili, id],
      callback
    );
  }
};
module.exports = tapahtumat;
