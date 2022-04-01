const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/:idKortti?',
 function(request, response) {
  if (request.params.idAsiakas) {
    kortti.getById(request.params.idAsiakas, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
  else {
    kortti.getAll(function(err, dbResult) {
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
  kortti.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:idAsiakas', 
function(request, response) {
  kortti.delete(request.params.idAsiakas, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:idAsiakas', 
function(request, response) {
  kortti.update(request.params.idAsiakas, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;