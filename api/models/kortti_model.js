const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hash) {
    return db.query(
      'insert into kortti (korttinumero,pin,idasiakas,idtili) values(?,?,?,?)',
      [kortti.korttinumero, hash, kortti.idasiakas, kortti.idtili],
      callback);
    });
    },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hash) {
    return db.query(
      'update kortti set korttinumero=?,pin=?, idasiakas=?, idtili=? where idkortti=?',
      [kortti.korttinumero, hash, kortti.idasiakas, kortti.idtili, id],
      callback);
  });
}
}
module.exports = kortti;