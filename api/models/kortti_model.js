const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
<<<<<<< HEAD
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
=======

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.Pin, saltRounds, function(err, hash) {
      return db.query('insert into kortti (Korttinumero, Pin, idAsiakas, idtili) values(?,?,?,?)',
      [kortti.Korttinumero, hash, kortti.idAsiakas, kortti.idtili], callback);
    });
  },
  
>>>>>>> f9d4b1b (Restapi)
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
<<<<<<< HEAD
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
          
=======
    bcrypt.hash(kortti.Pin, saltRounds, function(err, hash) {
      return db.query('update kortti set Korttinumero=?, Pin=?, idAsiakas=?, idtili=? where idkortti=?',
      [kortti.Korttinumero, hash, kortti.idAsiakas, kortti.idtili, id], callback);
    });
  }

};
>>>>>>> f9d4b1b (Restapi)
module.exports = kortti;