const express = require('express');
const router = express.Router();
const asiakas = require('../models/asiakas_model');

router.get('/:idAsiakas?',
 function(request, response) {
  if (request.params.idAsiakas) {
    asiakas.getById(request.params.idAsiakas, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    asiakas.getAll(function(err, dbResult) {
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
  asiakas.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:idAsiakas', 
function(request, response) {
  asiakas.delete(request.params.idAsiakas, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:idAsiakas', 
function(request, response) {
  asiakas.update(request.params.idAsiakas, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;