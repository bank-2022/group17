const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/:idKortti?',
 function(request, response) {
  if (request.params.idKortti) {
    kortti.getById(request.params.idKortti, function(err, dbResult) {
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


router.delete('/:idKortti', 
function(request, response) {
  kortti.delete(request.params.idKortti, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:idKortti', 
function(request, response) {
  kortti.update(request.params.idKortti, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;