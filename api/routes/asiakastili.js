const express = require('express');
const router = express.Router();
const asiakastili = require('../models/asiakastili_model');

router.get('/:idAsiakas?',
 function(request, response) {
  if (request.params.idAsiakas) {
    asiakastili.getById(request.params.idAsiakas, request.params.idtili,function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    asiakastili.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  asiakastili.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:idAsiakas', 
function(request, response) {
  asiakastili.delete(request.params.idAsiakas, request.params.idtili, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:idAsiakas', 
function(request, response) {
  asiakastili.update(request.params.idAsiakas, request.params.idtili, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;