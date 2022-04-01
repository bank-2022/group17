const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    kortti.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
<<<<<<< HEAD
    kortti.get(function(err, dbResult) {
=======
    kortti.getAll(function(err, dbResult) {
>>>>>>> f9d4b1b (Restapi)
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});
<<<<<<< HEAD
router.post('/', 
function(request, response) {
  kortti.add(request.body, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
=======


router.post('/', 
function(request, response) {
  kortti.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
>>>>>>> f9d4b1b (Restapi)
    }
  });
});

<<<<<<< HEAD
router.delete('/:id', 
function(request, response) {
  kortti.delete(request.params.id, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(count);
=======

router.delete('/:id', 
function(request, response) {
  kortti.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
>>>>>>> f9d4b1b (Restapi)
    }
  });
});


router.put('/:id', 
function(request, response) {
  kortti.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

<<<<<<< HEAD
router.get('/info/:Korttinumero',
function(request,response){
  kortti.getKorttiInfo(request.params.Korttinumero, function(err,dbResult){
    if(err){
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

=======
>>>>>>> f9d4b1b (Restapi)
module.exports = router;