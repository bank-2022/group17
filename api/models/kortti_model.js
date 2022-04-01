const db = require('../database');

const kortti = {
  getById: function([idKortti], callback) {
    return db.query('select * from kortti where idKortti=?', [idKortti], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (idKortti,Korttinumero,Pin,idAsiakas, idTili) values(?,?,?,?,?)',
      [kortti.idKortti, kortti.Korttinumero, kortti.Pin, kortti.idAsiakas, kortti.idTili],
      callback
    );
  },
  delete: function(idKortti, callback) {
    return db.query('delete from kortti where idKortti=?', [idKortti], callback);
  },
  update: function([idKortti, kortti], callback) {
    return db.query(
      'update kortti set idKortti=?,Korttinumero=?, Pin=?, idAsiakas=?, idTili=? where idKortti=?',
      [kortti.idKortti, kortti.Korttinumero, kortti.Pin, kortti.idAsiakas, kortti.idTili, idKortti],
      callback
    );
  }


};
module.exports = kortti;