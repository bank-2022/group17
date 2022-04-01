const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
<<<<<<< HEAD
    return db.query('select * from asiakas where idAsiakas=?', [id], callback);
=======
    return db.query('select * from asiakas where idasiakas=?', [id], callback);
>>>>>>> f9d4b1b (Restapi)
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (Nimi,Osoite,Puhelinnumero) values(?,?,?)',
      [asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
<<<<<<< HEAD
    return db.query('delete from asiakas where idAsiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set id=?,Nimi=?, Osoite=?, Puhelinnumero=? where idAsiakas=?',
      [asiakas.idAsiakas, asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero, id],
=======
    return db.query('delete from asiakas where idasiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set Nimi=?,Osoite=?, Puhelinnumero=? where idasiakas=?',
      [asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero, id],
>>>>>>> f9d4b1b (Restapi)
      callback
    );
  }
};
module.exports = asiakas;