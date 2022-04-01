const db = require('../database');

const asiakas = {
  getById: function(idAsiakas, callback) {
    return db.query('select * from asiakas where idAsiakas=?', [idAsiakas], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (idAsiakas,Nimi,Osoite,Puhelinnumero) values(?,?,?,?)',
      [asiakas.idAsiakas, asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero],
      callback
    );
  },
  delete: function(idAsiakas, callback) {
    return db.query('delete from asiakas where idAsiakas=?', [idAsiakas], callback);
  },
  update: function(idAsiakas, asiakas, callback) {
    return db.query(
      'update asiakas set Nimi=?,Osoite=?, Puhelinnumero=? where idAsiakas=?',
      [asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero, idAsiakas],
      callback
    );
  }
};
module.exports = asiakas;