const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
<<<<<<< HEAD
    return db.query('select * from tilitapahtumat where tilitapahtumat.idtili=?', [id], callback);
=======
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
>>>>>>> f9d4b1b (Restapi)
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
<<<<<<< HEAD
      'insert into tilitapahtumat (Kortinnumero,Paivays,Tapahtuma,Summa,idkortti,idtili) values(?,?,?,?,?,?)',
=======
      'insert into tilitapahtumat (Kortinnumero, Paivays, Tapahtuma, Summa, idkortti, idtili) values(?,?,?,?,?,?)',
>>>>>>> f9d4b1b (Restapi)
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