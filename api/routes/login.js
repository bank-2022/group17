const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.idtili && request.body.Pin){
      //const idtili = request.body.idtili;
      const idtili_check = request.body.idtili;
      const Pin = request.body.Pin;
        login.checkPin(idtili_check, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(Pin,dbResult[0].Pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ idtili: idtili_check });
                  response.send(token);
                }
                else {
                    console.log("wrong Pin");
                    //console.log(dbResult[0]); //TESTING
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

function generateAccessToken(idtili) {
  dotenv.config();
  return jwt.sign(idtili, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;