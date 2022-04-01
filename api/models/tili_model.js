<<<<<<< HEAD
const connection = require('../database');
=======
>>>>>>> f9d4b1b (Restapi)
const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idtili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (Saldo,Tilinumero) values(?,?)',
<<<<<<< HEAD
      [tili.Saldo, tili.Tilinumero],
=======
      [tili.Saldo, tili.Tilinumero, tili.Puhelinnumero],
>>>>>>> f9d4b1b (Restapi)
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idtili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
<<<<<<< HEAD
      'update tili set Saldo=?, Tilinumero=? where idtili=?',
      [tili.Saldo, tili.Tilinumero, id],
      callback
    );
  },
  nosta: function(id, myArray,callback){
    var Summa=myArray.Summa;
    var Korttinumero=myArray.Korttinumero;
    var idkortti=myArray.idkortti;
    return db.query(
      'call nosta(?,?,?,?)',
    [id,Summa,Korttinumero,idkortti],
    callback
    );
  },
  talleta: function(id, myArray,callback){
    var Summa=myArray.Summa;
    var Korttinumero=myArray.Korttinumero;
    var idkortti=myArray.idkortti;
    return db.query(
      'call talleta(?,?,?,?)',
    [id,Summa,Korttinumero,idkortti],
    callback
    );
  }
}

=======
      'update tili set Saldo=?,Tilinumero=? where idtili=?',
      [tili.Saldo, tili.Tilinumero, id],
      callback
    );
  }
};
>>>>>>> f9d4b1b (Restapi)
module.exports = tili;