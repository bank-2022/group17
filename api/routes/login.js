const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.idtili && request.body.Pin){
      const idtili = request.body.idtili;
      const Pin = request.body.Pin;
        login.checkPin(idtili, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(Pin,dbResult[0].Pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  response.send(true);
                }
                else {
                    console.log("wrong Pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("idtili does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("idtili or Pin missing");
      response.send(false);
    }
  }
);

module.exports=router;