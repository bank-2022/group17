const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti={
  get: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hashed_pin) {
      return db.query('insert into kortti (korttinumero, pin, idasiakas, idtili) values(?,?,?,?)',
      [kortti.korttinumero, hashed_pin, kortti.idasiakas, kortti.idtili], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hashed_pin) {
        return db.query('insert into kortti (korttinumero, pin, idasiakas, idtili) values(?,?,?,?)',
        [kortti.korttinumero, hashed_pin, kortti.idasiakas, kortti.idtili], callback);
    });
  },
  getKorttiInfo: function(Korttinumero, callback){
    return db.query('SELECT asiakas.nimi, kortti.idAsiakas, kortti.Korttinumero, kortti.idKortti, tili.idtili, saldo FROM kortti INNER JOIN tili ON kortti.idtili=tili.idtili INNER JOIN asiakas ON kortti.idAsiakas=asiakas.idAsiakas WHERE kortti.Korttinumero=?'
    , [Korttinumero], callback);
  }

}
          
module.exports = kortti;